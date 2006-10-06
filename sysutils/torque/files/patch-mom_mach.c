--- src/resmom/freebsd/mom_mach.c.orig	Tue Jun 20 02:23:04 2006
+++ src/resmom/freebsd/mom_mach.c	Thu Sep 14 19:09:58 2006
@@ -370,40 +370,10 @@
 			continue;
 
 		nps++;
-		cputime += tvk(pp->kp_proc.p_rtime);
 
-		if (pp->kp_proc.p_ru == NULL) {
-			struct	pstats	ps;
-
-			DBPRT(("%s: p_stats 0x%lx\n", id,
-				(u_long)pp->kp_proc.p_stats))
-			if (pp->kp_proc.p_stats == NULL)
-				continue;
-
-			if (kvm_read(kd, (u_long)pp->kp_proc.p_stats, &ps,
-					sizeof(ps)) != sizeof(ps)) {
-				log_err(errno, id, "kvm_read(pstats)");
-				continue;
-			}
-			cputime += tv(ps.p_ru.ru_utime) +
-				tv(ps.p_ru.ru_stime) +
-				tv(ps.p_cru.ru_utime) +
-				tv(ps.p_cru.ru_stime);
-		}
-		else {
-			struct	rusage	ru;
-
-			DBPRT(("%s: p_ru 0x%lx\n", id,
-				(u_long)pp->kp_proc.p_ru))
-			if (kvm_read(kd, (u_long)pp->kp_proc.p_ru, &ru,
-					sizeof(ru)) != sizeof(ru)) {
-				log_err(errno, id, "kvm_read(session)");
-				continue;
-			}
-			cputime += tv(ru.ru_utime) + tv(ru.ru_stime);
-		}
+		cputime += pp->ki_runtime / 1000000;
 		DBPRT(("%s: ses %d pid %d cputime %d\n", id,
-				sess_tbl[i], pp->kp_proc.p_pid, cputime))
+				sess_tbl[i], pp->ki_pid,  pp->ki_runtime / 1000000))
 	}
 
 	if (nps == 0)
@@ -434,11 +404,9 @@
 		if (!injob(pjob, sess_tbl[i]))
 			continue;
 
-		memsize += ctob(pp->kp_eproc.e_vm.vm_tsize +
-			pp->kp_eproc.e_vm.vm_dsize +
-			pp->kp_eproc.e_vm.vm_ssize);
+		memsize += pp->ki_size;
 		DBPRT(("%s: ses %d pid=%d totmem=%lu\n", id,
-		       sess_tbl[i], pp->kp_proc.p_pid, memsize))
+		       sess_tbl[i], pp->ki_pid, pp->ki_size))
 	}
 
 	return (memsize);
@@ -461,10 +429,10 @@
 		if (!injob(pjob, sess_tbl[i]))
 			continue;
 
-		memsize += ctob(pp->kp_eproc.e_vm.vm_rssize);
+		memsize += pp->ki_rssize * PAGE_SIZE;
 		DBPRT(("%s: pid=%d ses=%d mem=%d totmem=%d\n", id,
-			pp->kp_proc.p_pid, sess_tbl[i],
-			pp->kp_eproc.e_vm.vm_rssize, memsize))
+			pp->ki_pid, sess_tbl[i],
+			pp->ki_rssize * PAGE_SIZE, memsize))
 	}
 
 	return (memsize);
@@ -485,9 +453,7 @@
 		if (!injob(pjob, sess_tbl[i]))
 			continue;
 
-		if (ctob(pp->kp_eproc.e_vm.vm_tsize +
-				pp->kp_eproc.e_vm.vm_dsize +
-				pp->kp_eproc.e_vm.vm_ssize) > limit)
+		if (pp->ki_size > limit)
 			return (TRUE);
 	}
 
@@ -732,7 +698,7 @@
   const void *b)
 
   {
-  return((int)((struct kinfo_proc *)a)->kp_eproc.e_paddr - (int)((struct kinfo_proc *)b)->kp_eproc.e_paddr);
+  return((int)((struct kinfo_proc *)a)->ki_paddr - (int)((struct kinfo_proc *)b)->ki_paddr);
   }
 
 int bs_cmp(
@@ -741,7 +707,7 @@
   const void *member)
 
   {
-  return((int)((struct session *)key)->s_leader - (int)((struct kinfo_proc *)member)->kp_eproc.e_paddr);
+  return((int)((struct session *)key)->s_leader - (int)((struct kinfo_proc *)member)->ki_paddr);
   }
 
 
@@ -786,24 +752,10 @@
 
 	qsort(proc_tbl, nproc, sizeof(struct kinfo_proc), qs_cmp);
 
-	for (i=0, kp=proc_tbl; i<nproc; i++, kp++) {
-		if (kvm_read(kd, (u_long)kp->kp_eproc.e_sess, &ss, sizeof(ss))
-				!= sizeof(ss)) {
-			sprintf(log_buffer,
-				"kvm_read: %s", kvm_geterr(kd));
-			log_err(errno, id, log_buffer);
-			return (PBSE_SYSTEM);
-		}
-		if (ss.s_leader == kp->kp_eproc.e_paddr ||
-				ss.s_leader == NULL) {
-			sid = kp->kp_proc.p_pid;
-		}
-		else {
-			leader = bsearch(&ss, proc_tbl, nproc,
-				sizeof(struct kinfo_proc), bs_cmp);
-			sid = leader ? leader->kp_proc.p_pid : 0;
-		}
-		sess_tbl[i] = sid;
+	for (i=0; i<nproc; i++) {
+		struct kinfo_proc	*pp = &proc_tbl[i];
+
+		sess_tbl[i] = pp->ki_sid;
 	}
 
 	return (PBSE_NONE);
@@ -1012,8 +964,8 @@
 			continue;
 
 		DBPRT(("%s: send signal %d to pid %d\n", id,
-				sig, pp->kp_proc.p_pid))
-		(void)kill(pp->kp_proc.p_pid, sig);
+				sig, pp->ki_pid))
+		(void)kill(pp->ki_pid, sig);
 		++ct;
 	}
 	return ct;
@@ -1118,36 +1070,10 @@
 		if (jobid != sess_tbl[i])
 			continue;
 
-		cputime += tvk(pp->kp_proc.p_rtime);
-
-		if (pp->kp_proc.p_ru == NULL) {
-			struct	pstats	ps;
-
-			if (pp->kp_proc.p_stats == NULL)
-				continue;
-
-			if (kvm_read(kd, (u_long)pp->kp_proc.p_stats, &ps,
-					sizeof(ps)) != sizeof(ps)) {
-				log_err(errno, id, "kvm_read(pstats)");
-				continue;
-			}
-			cputime += tv(ps.p_ru.ru_utime) +
-				tv(ps.p_ru.ru_stime) +
-				tv(ps.p_cru.ru_utime) +
-				tv(ps.p_cru.ru_stime);
-		}
-		else {
-			struct	rusage	ru;
+		cputime += pp->ki_runtime / 1000000;
 
-			if (kvm_read(kd, (u_long)pp->kp_proc.p_ru, &ru,
-					sizeof(ru)) != sizeof(ru)) {
-				log_err(errno, id, "kvm_read(session)");
-				continue;
-			}
-			cputime += tv(ru.ru_utime) + tv(ru.ru_stime);
-		}
 		DBPRT(("%s: ses %d pid %d cputime %d\n", id,
-				jobid, pp->kp_proc.p_pid, cputime))
+				jobid, pp->ki_pid, cputime))
 
 	}
 
@@ -1166,37 +1092,11 @@
 	for (i=0; i<nproc; i++) {
 		struct kinfo_proc	*pp = &proc_tbl[i];
 
-		if (pid != pp->kp_proc.p_pid)
+		if (pid != pp->ki_pid)
 			continue;
 
-		cputime = tvk(pp->kp_proc.p_rtime);
-
-		if (pp->kp_proc.p_ru == NULL) {
-			struct	pstats	ps;
-
-			if (pp->kp_proc.p_stats == NULL)
-				break;
-
-			if (kvm_read(kd, (u_long)pp->kp_proc.p_stats, &ps,
-					sizeof(ps)) != sizeof(ps)) {
-				log_err(errno, id, "kvm_read(pstats)");
-				break;
-			}
-			cputime += tv(ps.p_ru.ru_utime) +
-				tv(ps.p_ru.ru_stime) +
-				tv(ps.p_cru.ru_utime) +
-				tv(ps.p_cru.ru_stime);
-		}
-		else {
-			struct	rusage	ru;
+       		cputime = pp->ki_runtime / 1000000;
 
-			if (kvm_read(kd, (u_long)pp->kp_proc.p_ru, &ru,
-					sizeof(ru)) != sizeof(ru)) {
-				log_err(errno, id, "kvm_read(session)");
-				break;
-			}
-			cputime += tv(ru.ru_utime) + tv(ru.ru_stime);
-		}
 		DBPRT(("%s: pid %d cputime %d\n", id, pid, cputime))
 
 		sprintf(ret_string, "%.2f", (double)cputime * cputfactor);
@@ -1261,13 +1161,11 @@
 			continue;
 
 		found = 1;
-		addmem = pp->kp_eproc.e_vm.vm_tsize +
-				pp->kp_eproc.e_vm.vm_dsize +
-				pp->kp_eproc.e_vm.vm_ssize;
+		addmem = pp->ki_size;
 		memsize += addmem;
 	}
 	if (found) {
-		sprintf(ret_string, "%ukb", ctob(memsize) >> 10); /* KB */
+		sprintf(ret_string, "%ukb", memsize / 1024); /* KB */
 		return ret_string;
 	}
 
@@ -1289,13 +1187,11 @@
 	for (i=0; i<nproc; i++) {
 		struct kinfo_proc	*pp = &proc_tbl[i];
 
-		if (pid != pp->kp_proc.p_pid)
+		if (pid != pp->ki_pid)
 			continue;
 
-		memsize = pp->kp_eproc.e_vm.vm_tsize +
-				pp->kp_eproc.e_vm.vm_dsize +
-				pp->kp_eproc.e_vm.vm_ssize;
-		sprintf(ret_string, "%ukb", ctob(memsize) >> 10); /* KB */
+		memsize = pp->ki_size;
+		sprintf(ret_string, "%ukb", memsize / 1024); /* KB */
 		return ret_string;
 	}
 
@@ -1358,10 +1254,10 @@
 			continue;
 
 		found = 1;
-		resisize += pp->kp_eproc.e_vm.vm_rssize;
+		resisize += pp->ki_rssize * PAGE_SIZE;
 	}
 	if (found) {
-		sprintf(ret_string, "%ukb", ctob(resisize) >> 10); /* KB */
+		sprintf(ret_string, "%ukb", resisize / 1024); /* KB */
 		return ret_string;
 	}
 
@@ -1385,11 +1281,11 @@
 	for (i=0; i<nproc; i++) {
 		struct kinfo_proc	*pp = &proc_tbl[i];
 
-		if (pid != pp->kp_proc.p_pid)
+		if (pid != pp->ki_pid)
 			continue;
 
-		resisize = pp->kp_eproc.e_vm.vm_rssize;
-		sprintf(ret_string, "%ukb", ctob(resisize) >> 10); /* KB */
+		resisize = pp->ki_rssize * PAGE_SIZE;
+		sprintf(ret_string, "%ukb", resisize / 1024); /* KB */
 		return ret_string;
 	}
 
@@ -1462,12 +1358,12 @@
 	for (i=0; i<nproc; i++) {
 		struct kinfo_proc	*pp = &proc_tbl[i];
 
-		if (pp->kp_eproc.e_pcred.p_ruid == 0)
+		if (pp->ki_ruid == 0)
 			continue;
 
 		jobid = sess_tbl[i];
 		DBPRT(("%s: pid %d sid %u\n",
-		       id, (int)pp->kp_proc.p_pid, jobid))
+		       id, (int)pp->ki_pid, jobid))
 		for (j=0; j<njids; j++) {
 			if (jids[j] == jobid)
 				break;
@@ -1548,12 +1444,12 @@
 		struct kinfo_proc	*pp = &proc_tbl[i];
 
 		DBPRT(("%s[%d]: pid %d sid %u\n",
-		       id, num_pids, pp->kp_proc.p_pid, sess_tbl[i]))
+		       id, num_pids, pp->ki_pid, sess_tbl[i]))
 		if (jobid != sess_tbl[i])
 			continue;
 
 		checkret(&fmt, 100);
-		sprintf(fmt, " %d", pp->kp_proc.p_pid);
+		sprintf(fmt, " %d", pp->ki_pid);
 		fmt += strlen(fmt);
 		num_pids++;
 	}
@@ -1591,11 +1487,11 @@
 	for (i=0; i<nproc; i++) {
 		struct kinfo_proc	*pp = &proc_tbl[i];
 
-		if ((uid = pp->kp_eproc.e_pcred.p_ruid) == 0)
+		if ((uid = pp->ki_ruid) == 0)
 			continue;
 
 		DBPRT(("%s: pid %d uid %u\n",
-		       id, (int)pp->kp_proc.p_pid, uid))
+		       id, (int)pp->ki_pid, uid))
 		for (j=0; j<nuids; j++) {
 			if (uids[j] == uid)
 				break;
@@ -1884,23 +1780,12 @@
 				continue;
 		}
 		else {
-			if (value != pp->kp_proc.p_pid)
+			if (value != pp->ki_pid)
 				continue;
 		}
 
-		if (pp->kp_proc.p_stats == NULL) {
-			rm_errno = RM_ERR_SYSTEM;
-			return NULL;
-		}
-
-		if (kvm_read(kd, (u_long)pp->kp_proc.p_stats, &ps,
-				sizeof(ps)) != sizeof(ps)) {
-			log_err(errno, id, "kvm_read(pstats)");
-			rm_errno = RM_ERR_SYSTEM;
-			return NULL;
-		}
 		found = 1;
-		start = MIN(start, ps.p_start.tv_sec);
+		start = MIN(start, pp->ki_start.tv_sec);
 	}
 	if (found) {
 		sprintf(ret_string, "%ld", (long)((double)(now - start) * wallfactor));
@@ -2035,7 +1920,7 @@
 	dirdev = sb.st_dev;
 	DBPRT(("dir has devnum %d\n", dirdev))
 
-	if (setfsent() == NULL) {
+	if (setfsent() == 0) {
 		log_err(errno, id, "setfsent");
 		rm_errno = RM_ERR_SYSTEM;
                 return NULL;
