*** milter-regex.c.orig	Sun Mar  6 06:42:53 2005
--- milter-regex.c	Wed Sep  6 16:00:00 2006
***************
*** 86,93 ****
  static void		 usage(const char *);
  static void		 msg(int, struct context *, const char *, ...);
  
  #define USER		"_milter-regex"
  #define OCONN		"unix:/var/spool/milter-regex/sock"
  #define RCODE_REJECT	"554"
  #define RCODE_TEMPFAIL	"451"
  #define XCODE_REJECT	"5.7.1"
--- 86,94 ----
  static void		 usage(const char *);
  static void		 msg(int, struct context *, const char *, ...);
  
  #define USER		"_milter-regex"
  #define OCONN		"unix:/var/spool/milter-regex/sock"
+ #define OPID		"/var/spool/milter-regex/milter-regex.pid"
  #define RCODE_REJECT	"554"
  #define RCODE_TEMPFAIL	"451"
  #define XCODE_REJECT	"5.7.1"
***************
*** 556,565 ****
--- 557,570 ----
  {
  	int ch;
  	const char *oconn = OCONN;
+ 	const char *pid_file_name = OPID;
  	const char *user = USER;
  	sfsistat r = MI_FAILURE;
  	const char *ofile = NULL;
  
+ 	pid_t pid;
+ 	FILE *pid_fd = NULL;
+ 
  	tzset();
  	openlog("milter-regex", LOG_PID | LOG_NDELAY, LOG_DAEMON);
  
***************
*** 577,582 ****
--- 582,590 ----
  		case 'u':
  			user = optarg;
  			break;
+ 		case 'r':
+ 			pid_file_name = optarg;
+ 			break;
  		default:
  			usage(argv[0]);
  		}
***************
*** 638,646 ****
  		fprintf(stderr, "daemon: %s\n", strerror(errno));
  		goto done;
  	}
- 	umask(0177);
  
  	msg(LOG_INFO, NULL, "started: %s", rcsid);
  	r = smfi_main();
  	if (r != MI_SUCCESS)
  		msg(LOG_ERR, NULL, "smfi_main: terminating due to error");
--- 646,667 ----
  		fprintf(stderr, "daemon: %s\n", strerror(errno));
  		goto done;
  	}
  
  	msg(LOG_INFO, NULL, "started: %s", rcsid);
+ 
+ 	umask(0006);
+ 
+ 	if((pid_fd = fopen(pid_file_name, "w")) == NULL) {
+ 		msg(LOG_ERR, NULL, "can't open file: %s", pid_file_name);
+ 		goto done;
+ 	} else {
+ 		pid = getpid();
+ 		fprintf(pid_fd, "%d", (int) pid);
+ 		fclose(pid_fd);
+ 	}
+ 
+ 	umask(0177);
+ 
  	r = smfi_main();
  	if (r != MI_SUCCESS)
  		msg(LOG_ERR, NULL, "smfi_main: terminating due to error");
