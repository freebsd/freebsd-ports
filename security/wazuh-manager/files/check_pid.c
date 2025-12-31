#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <errno.h>
#include <sys/sysctl.h>
#include <sys/stat.h>
#include <sysexits.h>
#include <unistd.h>

#define PID_MAX_FALLBACK    99999
#define PROC_PATH           "/proc"
/*
 * /proc = 5, / = 1, <pid> = 5, \0 = 1
 */
#define PID_PATH_LEN        12

static void     usage(void);
static void     raise_invalid_number(int);
static void     raise_atoi_exception(const char *);
static int      safe_atoi(const char *, int *);

int
main(int argc, char **argv)
{
    const char *pid_str;
    if ((pid_str = argv[1]) == NULL)
        usage();

    int pid;
    if (safe_atoi(pid_str, &pid) != 0)
        raise_atoi_exception(pid_str);

    pid_t pid_max;

    size_t pid_max_len;

    pid_max_len = sizeof(pid_max);
    if (sysctlbyname("kern.pid_max", &pid_max, &pid_max_len, NULL, 0) == -1) {
        warnx("error getting sysctl");
        pid_max = PID_MAX_FALLBACK;
    }
    
    if (pid <= 0 || pid > pid_max)
        raise_invalid_number(pid);

    char pid_path[PID_PATH_LEN];

    snprintf(pid_path, sizeof(pid_path), "/proc/%d", pid);

    struct stat sbuf;

    if (lstat(pid_path, &sbuf) == -1) {
        if (errno == ENOENT)
            return EX_NOINPUT;
        else
            warnx("error getting file status");
            return EX_SOFTWARE;
    }

    return EX_OK;
}

static void
raise_invalid_number(int n)
{
    errx(EX_DATAERR, "%d: invalid number", n);
}

static void
raise_atoi_exception(const char *s)
{
    if (errno != 0)
        err(EX_SOFTWARE, "atol()");
    else
        errx(EX_SOFTWARE, "could not convert %s to an integer", s);
}

static int
safe_atoi(const char *s, int *ret_i)
{
    char *x = NULL;
    long l;

    errno = 0;
    l = strtol(s, &x, 0);

    if (!x || x == s || *x || errno)
        return errno > 0 ? -errno : -EINVAL;

    if ((long)(int)l != l)
        return -ERANGE;

    *ret_i = (int)l;

    return 0;
}

static void
usage(void)
{
    errx(EX_USAGE, "%s",
        "usage: check_pid <pid>");
}
