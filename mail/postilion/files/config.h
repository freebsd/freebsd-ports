/* Define if you have <sys/wait.h> that is POSIX.1 compatible.  */
#define HAVE_SYS_WAIT_H	1

/* Define if utime(file, NULL) sets file's timestamp to the present.  */
#define HAVE_UTIME_NULL	1

/* Define if your <sys/time.h> declares struct tm.  */
#define TM_IN_SYS_TIME	1

/* Define if you have the gethostname function.  */
#define HAVE_GETHOSTNAME	1

/* Define if you have the mkdir function.  */
#define HAVE_MKDIR	1

/* Define if you have the mktime function.  */
#define HAVE_MKTIME	1

/* Define if you have the strstr function.  */
#define HAVE_STRSTR	1

/* Define if you have the <dirent.h> header file.  */
#define HAVE_DIRENT_H	1

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H	1

/* Define if you have the <sys/ndir.h> header file.  */
#define HAVE_SYS_NDIR_H	1

/* Define if you have the <tkstep.h> header file.  */
#undef HAVE_TKSTEP_H	1

/* Define if you have the <unistd.h> header file.  */
#define HAVE_UNISTD_H	1

/* Timezone defines */
#undef HAVE_TM_TZADJ
#define HAVE_TM_GMTOFF	1
#define HAVE_TIMEZONE_VAR	1

/* Define if you have the crypt library (-lcrypt).  */
#define HAVE_LIBCRYPT	1

/* Define if you have the s library (-ls).  */
#undef HAVE_LIBS
