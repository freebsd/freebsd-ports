--- FreeBSD/ProcessList.c	2011-03-17 20:50:04.000000000 +0200
+++ FreeBSD/ProcessList.c	2011-02-10 16:06:59.000000000 +0200
@@ -1,6 +1,7 @@
 /*
     KSysGuard, the KDE System Guard
 
+	Copyright (c) 2011 David Naylor <naylor.b.david@gmail.com>
 	Copyright (c) 1999-2000 Hans Petter Bieker<bieker@kde.org>
 	Copyright (c) 1999 Chris Schlaeger <cs@kde.org>
 
@@ -20,423 +21,271 @@
 
 */
 
-#include <ctype.h>
-#include <dirent.h>
+#include "ProcessList.h"
+
+#include <fcntl.h>
+#include <paths.h>
 #include <pwd.h>
+#include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/param.h>
-
-#if defined(__DragonFly__)
-#include <sys/user.h>
-#include <sys/resourcevar.h>
-#endif
-
-#if (__FreeBSD_version > 500015) || (__FreeBSD_kernel_version > 500015)
-#include <sys/priority.h>
-#endif
 #include <sys/sysctl.h>
-#include <sys/time.h>
 #include <sys/types.h>
 #include <sys/user.h>
+#include <time.h>
 #include <unistd.h>
-#include <signal.h>
 
-#include "../../gui/SignalIDs.h"
 #include "Command.h"
-#include "ProcessList.h"
-#include "ccont.h"
-#include "ksysguardd.h"
-
-CONTAINER ProcessList = 0;
+#include "../../gui/SignalIDs.h"
 
-int fscale;
+#define KILL_COMMAND "kill"
+#define SETPRIORITY_COMMAND "setpriority"
+#define PROC_MONITOR "ps"
+#define NPROC_MONITOR "pscount"
+#define PID_MONITOR "lastpid"
+#define PROCBUF 1024
+#define STATEBUF 12
+#define NAMEBUF 24
+#define UNAMEBUF 12
+#define ARGBUF 256
+#define PWDBUF 16
+#define NAMELEN 128
+
+static struct kinfo_proc proc_buf[PROCBUF], prev_list[PROCBUF];
+static int nproc, prev_nproc, sorted_proc[PROCBUF], prev_sorted[PROCBUF];
 
-#define BUFSIZE 1024
+static struct timespec last_update;
+static float scale;
 
-typedef struct
-{
-	/* This flag is set for all found processes at the beginning of the
-	 * process list update. Processes that do not have this flag set will
-	 * be assumed dead and removed from the list. The flag is cleared after
-	 * each list update. */
-	int alive;
+static int pagesize, smpmode;
 
-	/* the process ID */
-	pid_t pid;
+static unsigned int lastpid;
 
-	/* the parent process ID */
-	pid_t ppid;
-
-	/* the real user ID */
+static struct {
 	uid_t uid;
+	char name[NAMELEN];
+} pwd_cache[PWDBUF];
+static int pwd_size = 0, pwd_hit = 0, pwd_last = 0;
 
-	/* the real group ID */
-	gid_t gid;
+static char *const statuses[] = { "", "IDLE", "RUN", "SLEEP", "STOP", "ZOMBIE", "WAIT", "LOCK" };
+static char (*cpunames)[8] = NULL;
 
-	/* a character description of the process status */
-	char status[16];
+static int cmp_pid(const void *, const void *);
+static char *getname(const uid_t);
 
-	/* the number of the tty the process owns */
-	int ttyNo;
+void initProcessList(struct SensorModul *sm) {
+	size_t len;
+	
+	if (!RunAsDaemon) {
+		registerCommand(KILL_COMMAND, killProcess);
+		registerCommand(SETPRIORITY_COMMAND, setPriority);
+	}
 
-	/*
-	 * The nice level. The range should be -20 to 20. I'm not sure
-	 * whether this is true for all platforms.
-	 */
-	int niceLevel;
-
-	/*
-	 * The scheduling priority.
-	 */
-	int priority;
-
-	/*
-	 * The total amount of memory the process uses. This includes shared and
-	 * swapped memory.
-	 */
-	unsigned int vmSize;
-
-	/*
-	 * The amount of physical memory the process currently uses.
-	 */
-	unsigned int vmRss;
-
-	/*
-	 * The amount of memory (shared/swapped/etc) the process shares with
-	 * other processes.
-	 */
-	unsigned int vmLib;
-
-	/*
-	 * The number of 1/100 of a second the process has spend in user space.
-	 * If a machine has an uptime of 1 1/2 years or longer this is not a
-	 * good idea. I never thought that the stability of UNIX could get me
-	 * into trouble! ;)
-	 */
-#if !defined(__DragonFly__)
-	unsigned int userTime;
-#else
-        long userTime;
-#endif
-
-	/*
-	 * The number of 1/100 of a second the process has spend in system space.
-	 * If a machine has an uptime of 1 1/2 years or longer this is not a
-	 * good idea. I never thought that the stability of UNIX could get me
-	 * into trouble! ;)
-	 */
-	unsigned int sysTime;
-
-	/* system time as multime of 100ms */
-	int centStamp;
-
-	/* the current CPU load (in %) from user space */
-	double userLoad;
-
-	/* the current CPU load (in %) from system space */
-	double sysLoad;
-
-	/* the name of the process */
-	char name[64];
-
-	/* the command used to start the process */
-	char cmdline[256];
-
-	/* the login name of the user that owns this process */
- 	char userName[32];
-} ProcessInfo;
+	len = sizeof(int);
+	if (sysctlbyname("kern.smp.active", &smpmode, &len, NULL, 0))
+		smpmode = 0;
+	else {
+		int cpus = 0;
+		len = sizeof(int);
+		sysctlbyname("kern.smp.cpus", &cpus, &len, NULL, 0);
+		cpunames = malloc(8 * sizeof(char) * cpus);
+		while (cpus--)
+			snprintf(cpunames[cpus], 8, "CPU%d", cpus);
+	}
 
-static unsigned ProcessCount;
+	pagesize = getpagesize() / 1024;
 
-static int
-processCmp(void* p1, void* p2)
-{
-	return (((ProcessInfo*) p1)->pid - ((ProcessInfo*) p2)->pid);
+	registerMonitor(PROC_MONITOR, "table", printProcessList, printProcessListInfo, sm);
+	registerMonitor(NPROC_MONITOR, "integer", printProcessCount, printProcessCountInfo, sm);
+	registerMonitor(PID_MONITOR, "integer", printLastPID, printLastPIDInfo, sm);
+
+	nproc = 0;
+	updateProcessList();
 }
 
-static ProcessInfo*
-findProcessInList(int pid)
-{
-	ProcessInfo key;
-	long index;
+void exitProcessList(void) {
+	removeCommand(KILL_COMMAND);
+	removeCommand(SETPRIORITY_COMMAND);
 
-	key.pid = pid;
-	if ((index = search_ctnr(ProcessList, processCmp, &key)) < 0)
-		return (0);
+	removeMonitor(PROC_MONITOR);
+	removeMonitor(NPROC_MONITOR);
+	removeMonitor(PID_MONITOR);
 
-	return (get_ctnr(ProcessList, index));
+	free(cpunames);
+	cpunames = NULL;
 }
 
-static int
-updateProcess(int pid)
-{
-	static const char * const statuses[] = { "idle","run","sleep","stop","zombie" };
-	
-	ProcessInfo* ps;
-	struct passwd* pwent;
-	int mib[4];
-	struct kinfo_proc p;
-	struct rusage pru;
+int updateProcessList(void) {
+	int proc;
+	int mib[3];
 	size_t len;
-	size_t buflen = 256;
-	char buf[256];
-
-	if ((ps = findProcessInList(pid)) == 0)
-	{
-		ps = (ProcessInfo*) malloc(sizeof(ProcessInfo));
-		ps->pid = pid;
-		ps->centStamp = 0;
-		push_ctnr(ProcessList, ps);
-		bsort_ctnr(ProcessList, processCmp);
-	}
+	struct timespec update;
 
-	ps->alive = 1;
+	memcpy(prev_list, proc_buf, sizeof(struct kinfo_proc) * nproc);
+	memcpy(prev_sorted, sorted_proc, sizeof(int) * nproc);
+	prev_nproc = nproc;
 
 	mib[0] = CTL_KERN;
 	mib[1] = KERN_PROC;
-	mib[2] = KERN_PROC_PID;
-	mib[3] = pid;
-
-	len = sizeof (p);
-	if (sysctl(mib, 4, &p, &len, NULL, 0) == -1 || !len)
-		return -1;
+	mib[2] = KERN_PROC_PROC;
+	len = PROCBUF * sizeof(struct kinfo_proc);
+	clock_gettime(CLOCK_MONOTONIC, &update);
+	sysctl(mib, 3, proc_buf, &len, NULL, 0);
+	nproc = len / sizeof(struct kinfo_proc);
+
+	len = sizeof(unsigned int);
+	sysctlbyname("kern.lastpid", &lastpid, &len, NULL, 0);
+
+	if (nproc > PROCBUF)
+		nproc = PROCBUF;
+	for (proc = 0; proc < nproc; ++proc)
+		sorted_proc[proc] = proc;
+	qsort(sorted_proc, nproc, sizeof(int), cmp_pid);
 
-#if (__FreeBSD_version > 500015) || (__FreeBSD_kernel_version > 500015)
-        ps->pid       = p.ki_pid;
-        ps->ppid      = p.ki_ppid;
-        ps->uid       = p.ki_uid;    
-        ps->gid       = p.ki_pgid;
-        ps->priority  = p.ki_pri.pri_user;
-        ps->niceLevel = p.ki_nice;
-#elif defined(__DragonFly__) && __DragonFly_version >= 190000
-	ps->pid       = p.kp_pid;
-	ps->ppid      = p.kp_ppid;
-	ps->uid       = p.kp_uid;
-	ps->gid       = p.kp_pgid;
-	ps->priority  = p.kp_lwp.kl_tdprio;
-	ps->niceLevel = p.kp_nice;
-#else
-        ps->pid       = p.kp_proc.p_pid;
-        ps->ppid      = p.kp_eproc.e_ppid;
-        ps->uid       = p.kp_eproc.e_ucred.cr_uid;
-        ps->gid       = p.kp_eproc.e_pgid;
-#if defined(__DragonFly__)
-	ps->priority  = p.kp_thread.td_pri;
-#else
-        ps->priority  = p.kp_proc.p_priority;
-#endif
-        ps->niceLevel = p.kp_proc.p_nice;
-#endif
-
-        /* this isn't usertime -- it's total time (??) */
-#if (__FreeBSD_version > 500015) || (__FreeBSD_kernel_version > 500015)
-        ps->userTime = p.ki_runtime / 10000;
-#elif defined(__DragonFly__)
-#if __DragonFly_version >= 190000
-	if (!getrusage(p.kp_pid, &pru))
-#else
-	if (!getrusage(p.kp_proc.p_pid, &pru))
-#endif
-	{
-		errx(1, "failed to get rusage info");
-	}
-	ps->userTime = pru.ru_utime.tv_usec / 1000; /*p_runtime / 1000*/ 
-#elif __FreeBSD_version >= 300000
-        ps->userTime = p.kp_proc.p_runtime / 10000;
-#else
-	ps->userTime = p.kp_proc.p_rtime.tv_sec*100+p.kp_proc.p_rtime.tv_usec/100;
-#endif
-        ps->sysTime  = 0;
-        ps->sysLoad  = 0;
-
-        /* memory, process name, process uid */
-	/* find out user name with process uid */
-	pwent = getpwuid(ps->uid);
-	strncpy(ps->userName,pwent&&pwent->pw_name? pwent->pw_name:"????",sizeof(ps->userName));
-	ps->userName[sizeof(ps->userName)-1]='\0';
+	scale = (update.tv_sec - last_update.tv_sec) + (update.tv_nsec - last_update.tv_nsec) / 1000000000.0;
+	last_update = update;
 
-	if (fscale == 0)
-		ps->userLoad = 0;
-	else
-#if (__FreeBSD_version > 500015) || (__FreeBSD_kernel_version > 500015)
-	ps->userLoad = 100.0 * (double) p.ki_pctcpu / fscale;
-	ps->vmSize   = p.ki_size;
-	ps->vmRss    = p.ki_rssize * getpagesize();
-	strlcpy(ps->name,p.ki_comm? p.ki_comm:"????",sizeof(ps->name));
-	strcpy(ps->status,(p.ki_stat>=1)&&(p.ki_stat<=5)? statuses[p.ki_stat-1]:"????");
-#elif defined (__DragonFly__) && __DragonFly_version >= 190000
-	ps->userLoad = 100.0 * (double) p.kp_lwp.kl_pctcpu / fscale;
-	ps->vmSize   = p.kp_vm_map_size;
-	ps->vmRss    = p.kp_vm_rssize * getpagesize();
-	strlcpy(ps->name,p.kp_comm ? p.kp_comm : "????", 
-		sizeof(ps->name));
-	strcpy(ps->status,(p.kp_stat>=1)&&(p.kp_stat<=5)? statuses[p.kp_stat-1]:"????");
-#else
-	ps->userLoad = 100.0 * (double) p.kp_proc.p_pctcpu / fscale;
-	ps->vmSize   = p.kp_eproc.e_vm.vm_map.size;
-	ps->vmRss    = p.kp_eproc.e_vm.vm_rssize * getpagesize();
-#if defined (__DragonFly__)
-	strlcpy(ps->name,p.kp_thread.td_comm ? p.kp_thread.td_comm : "????", 
-		sizeof(ps->name));
-#else
-	strlcpy(ps->name,p.kp_proc.p_comm ? p.kp_proc.p_comm : "????", sizeof(ps->name));
-#endif
-	strcpy(ps->status,(p.kp_proc.p_stat>=1)&&(p.kp_proc.p_stat<=5)? statuses[p.kp_proc.p_stat-1]:"????");
-#endif
+	return (0);
+}
 
-        /* process command line */
-	/* do a sysctl to get the command line args. */
+void printProcessList(const char* cmd)
+{
+	int proc, prev_proc;
+	float load;
+	int mib[4];
+	char *name, *uname, *state, *arg_fix;
+	char buf[STATEBUF + 1], buf2[UNAMEBUF], buf3[NAMEBUF], args[ARGBUF];
+	struct kinfo_proc *ps, *last_ps;
+	size_t len;
 
+	buf[STATEBUF] = '\0';
+	buf3[0] = '[';
 	mib[0] = CTL_KERN;
 	mib[1] = KERN_PROC;
 	mib[2] = KERN_PROC_ARGS;
-	mib[3] = pid;
-
-	if ((sysctl(mib, 4, buf, &buflen, 0, 0) == -1) || !buflen)
-		strcpy(ps->cmdline, "????");
-	else
-		strncpy(ps->cmdline, buf, buflen);
 
-	return (0);
-}
+	for (prev_proc = 0, proc = 0; proc < nproc; ++proc) {
+		ps = &proc_buf[sorted_proc[proc]];
 
-static void
-cleanupProcessList(void)
-{
-	ProcessInfo* ps;
-
-	ProcessCount = 0;
-	/* All processes that do not have the active flag set are assumed dead
-	 * and will be removed from the list. The alive flag is cleared. */
-	for (ps = first_ctnr(ProcessList); ps; ps = next_ctnr(ProcessList))
-	{
-		if (ps->alive)
-		{
-			/* Process is still alive. Just clear flag. */
-			ps->alive = 0;
-			ProcessCount++;
+		mib[3] = ps->ki_pid;
+		len = ARGBUF;
+		sysctl(mib, 4, args, &len, 0, 0);
+		if (!len)
+			args[0] = '\0';
+		else {
+			arg_fix = args;
+			while ((arg_fix += strlen(arg_fix)) < args + len - 1)
+				*arg_fix = '*';
 		}
+
+		if (args[0] == '\0' && (ps->ki_flag & P_SYSTEM || ps->ki_args == NULL)) {
+			int cpy;
+			cpy = strlcpy(buf3 + 1, ps->ki_comm, NAMEBUF - 1);
+			if (cpy > NAMEBUF - 2)
+				cpy = NAMEBUF - 2;
+			buf3[cpy + 1] = ']';
+			buf3[cpy + 2] = '\0';
+			name = buf3;
+			// TODO: should kernel processes be displayed?
+			//continue;
+		} else if (ps->ki_comm != NULL)
+			name = ps->ki_comm;
 		else
-		{
-			/* Process has probably died. We remove it from the list and
-			 * destruct the data structure. */
-			free(remove_ctnr(ProcessList));
+			name = "????";
+
+		switch (ps->ki_stat) {
+			case SRUN:
+				if (smpmode && ps->ki_oncpu != 0xff)
+					state = cpunames[ps->ki_oncpu];
+				else
+					state = statuses[2];
+				break;
+			case SSLEEP:
+				if (ps->ki_wmesg != NULL) {
+					state = ps->ki_wmesg;
+					break;
+				}
+
+			case SLOCK:
+				if (ps->ki_kiflag & KI_LOCKBLOCK) {
+					snprintf(buf, STATEBUF, "*%s", ps->ki_lockname);
+					state = buf;
+					break;
+				}
+
+			case SIDL:
+			case SSTOP:
+			case SZOMB:
+			case SWAIT:
+				state = statuses[(int)ps->ki_stat];
+				break;
+
+			default:
+				snprintf(buf, STATEBUF, "?%d", ps->ki_stat);
+				state = buf;
 		}
-	}
-}
 
-/*
-================================ public part ==================================
-*/
+		uname = getname(ps->ki_ruid);
+		if (uname[0] == '\0') {
+			snprintf(buf2, UNAMEBUF, "%d", ps->ki_ruid);
+			uname = buf2;
+		}
 
-void
-initProcessList(struct SensorModul* sm)
-{
-	size_t fscalelen;
-	ProcessList = new_ctnr();
+		for (;;) {
+			if (prev_proc >= prev_nproc) {
+				last_ps = NULL;
+				break;
+			}
+			last_ps = &prev_list[prev_sorted[prev_proc]];
+			if (last_ps->ki_pid == ps->ki_pid &&
+			    last_ps->ki_start.tv_sec == ps->ki_start.tv_sec &&
+			    last_ps->ki_start.tv_usec == ps->ki_start.tv_usec)
+				break;
+			else if (last_ps->ki_pid > ps->ki_pid) {
+				last_ps = NULL;
+				break;
+			}
+			++prev_proc;
+		}
 
-	registerMonitor("ps", "table", printProcessList, printProcessListInfo, sm);
-	registerMonitor("pscount", "integer", printProcessCount, printProcessCountInfo, sm);
+		if (last_ps != NULL)
+			load = (ps->ki_runtime - last_ps->ki_runtime) / 1000000.0 / scale;
+		else
+			load = ps->ki_runtime / 1000000.0 / scale;
 
-	if (!RunAsDaemon)
-	{
-		registerCommand("kill", killProcess);
-		registerCommand("setpriority", setPriority);
+		fprintf(CurrentClient, "%s\t%ld\t%ld\t%ld\t%ld\t%s\t%.2f\t%.2f\t%d\t%ld\t%ld\t%s\t%s\n",
+			   name, (long)ps->ki_pid, (long)ps->ki_ppid,
+			   (long)ps->ki_uid, (long)ps->ki_pgid, state,
+			   ps->ki_runtime / 1000000.0, load, ps->ki_nice,
+			   ps->ki_size / 1024, ps->ki_rssize * pagesize, uname, args);
 	}
-
-	fscalelen = sizeof(fscale);
-	if (sysctlbyname("kern.fscale", &fscale, &fscalelen, NULL, 0) == -1)
-		fscale = 0;
-
-	updateProcessList();
-}
-
-void
-exitProcessList(void)
-{
-	removeMonitor("ps");
-	removeMonitor("pscount");
-
-	if (ProcessList)
-		free (ProcessList);
-}
-
-int
-updateProcessList(void)
-{
-        int mib[3];
-        size_t len;
-        size_t num;
-        struct kinfo_proc *p;
-
-
-        mib[0] = CTL_KERN;
-        mib[1] = KERN_PROC;
-        mib[2] = KERN_PROC_ALL;
-        sysctl(mib, 3, NULL, &len, NULL, 0);
-	p = malloc(len);
-        sysctl(mib, 3, p, &len, NULL, 0);
-
-	for (num = 0; num < len / sizeof(struct kinfo_proc); num++)
-#if (__FreeBSD_version > 500015) || (__FreeBSD_kernel_version > 500015)
-		updateProcess(p[num].ki_pid);
-#elif __DragonFly_version >= 190000
-	    /* Skip kernel threads with pid -1. Swapper with pid 0 also
-	     * causing problems is skipped in printProcessList() as 'kernel'
-	     * entry. */
-	    if (p[num].kp_pid >= 0)
-		updateProcess(p[num].kp_pid);
-#elif defined(__DragonFly__)
-	    if (p[num].kp_proc.p_pid >= 0)
-		updateProcess(p[num].kp_proc.p_pid);
-#else
-		updateProcess(p[num].kp_proc.p_pid);
-#endif
-	free(p);
-	cleanupProcessList();
-
-	return (0);
 }
 
-void
-printProcessListInfo(const char* cmd)
+void printProcessListInfo(const char* cmd)
 {
 	fprintf(CurrentClient, "Name\tPID\tPPID\tUID\tGID\tStatus\tUser%%\tSystem%%\tNice\tVmSize\tVmRss\tLogin\tCommand\n");
 	fprintf(CurrentClient, "s\td\td\td\td\tS\tf\tf\td\tD\tD\ts\ts\n");
 }
 
-void
-printProcessList(const char* cmd)
-{
-	ProcessInfo* ps;
+void printProcessCount(const char *cmd) {
+	fprintf(CurrentClient, "%d\n", nproc);
+}
 
-	ps = first_ctnr(ProcessList); /* skip 'kernel' entry */
-	for (ps = next_ctnr(ProcessList); ps; ps = next_ctnr(ProcessList))
-	{
-		fprintf(CurrentClient, "%s\t%ld\t%ld\t%ld\t%ld\t%s\t%.2f\t%.2f\t%d\t%d\t%d\t%s\t%s\n",
-			   ps->name, (long)ps->pid, (long)ps->ppid,
-			   (long)ps->uid, (long)ps->gid, ps->status,
-			   ps->userLoad, ps->sysLoad, ps->niceLevel,
-			   ps->vmSize / 1024, ps->vmRss / 1024, ps->userName, ps->cmdline);
-	}
+void printProcessCountInfo(const char *cmd) {
+	fprintf(CurrentClient, "Number of Processes\t1\t65535\t\n");
 }
 
-void
-printProcessCount(const char* cmd)
-{
-	fprintf(CurrentClient, "%d\n", ProcessCount);
+void printLastPID(const char *cmd) {
+	fprintf(CurrentClient, "%u\n", lastpid);
 }
 
-void
-printProcessCountInfo(const char* cmd)
-{
-	fprintf(CurrentClient, "Number of Processes\t1\t65535\t\n");
+void printLastPIDInfo(const char *cmd) {
+	fprintf(CurrentClient, "Last used Process ID\t1\t65535\t\n");
 }
 
-void
-killProcess(const char* cmd)
+void killProcess(const char *cmd)
 {
 	int sig, pid;
 
@@ -524,8 +373,7 @@
 		fprintf(CurrentClient, "0\t%d\n", pid);
 }
 
-void
-setPriority(const char* cmd)
+void setPriority(const char *cmd)
 {
 	int pid, prio;
 
@@ -535,20 +383,58 @@
 		switch(errno)
 		{
 		case EINVAL:
-			fprintf(CurrentClient, "4\n");
+			fprintf(CurrentClient, "4\t%d\t%d\n", pid, prio);
 			break;
 		case ESRCH:
-			fprintf(CurrentClient, "3\n");
+			fprintf(CurrentClient, "3\t%d\t%d\n", pid, prio);
 			break;
 		case EPERM:
 		case EACCES:
-			fprintf(CurrentClient, "2\n");
+			fprintf(CurrentClient, "2\t%d\t%d\n", pid, prio);
 			break;
 		default:
-			fprintf(CurrentClient, "1\n");	/* unknown error */
+			fprintf(CurrentClient, "1\t%d\t%d\n", pid, prio);	/* unknown error */
 			break;
 		}
 	}
 	else
 		fprintf(CurrentClient, "0\n");
 }
+
+int cmp_pid(const void *first_idx, const void *last_idx) {
+	struct kinfo_proc *first = &proc_buf[*(int *)first_idx];
+	struct kinfo_proc *last = &proc_buf[*(int *)last_idx];
+
+	if (first->ki_pid < last->ki_pid)
+		return -1;
+	else if (first->ki_pid > last->ki_pid)
+		return 1;
+	else
+		return 0;
+}
+
+char *getname(const uid_t uid) {
+	int idx;
+	struct passwd *pw;
+
+	for (idx = 0; idx < pwd_size; ++idx) {
+		if (pwd_cache[pwd_hit].uid == uid)
+			return pwd_cache[pwd_hit].name;
+		pwd_hit = (pwd_hit + 1) % pwd_size;
+	}
+
+	if (pwd_size < PWDBUF)
+		pwd_last = pwd_size++;
+	else
+		pwd_last = (pwd_last + 1) % PWDBUF;
+	pwd_hit = pwd_last;
+
+	pwd_cache[pwd_hit].uid = uid;
+	pw = getpwuid(uid);
+	if (pw == NULL)
+		pwd_cache[pwd_hit].name[0] = '\0';
+	else
+		strlcpy(pwd_cache[pwd_hit].name, pw->pw_name, NAMELEN);
+
+	return (pwd_cache[pwd_hit].name);
+}
