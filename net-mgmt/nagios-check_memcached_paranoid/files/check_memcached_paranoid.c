/* -*- mode: c -*-
 *
 * Nagios check_memcached_paranoid plugin
 *
 * License: New BSD License
 * Copyright (c) 2009 HIROSE, Masaaki. All rights reserved.
 */

const char *progname = "check_memcached_paranoid";
const char *revision = "$Revision: 0.1 $";
#define MY_COPYRIGHT "Copyright (c) %s HIROSE, Masaaki. All rights reserved.\n\
\t<%s>\n\n"
const char *copyright = "2009";
const char *email = "hirose31 _at_ gmail.com";

#include "common.h"
#include "utils.h"
#include "utils_base.h"
#include "netutils.h"

#include "memcache.h"

#define MEMCACHED_PORT "11211"
#define TEST_VAL "check_memcached_paranoid"

#define EXIT_OK       0
#define EXIT_WARNING  1
#define EXIT_CRITICAL 2
#define EXIT_UNKNOWN  3


char      *mc_host   = NULL;
char      *mc_port   = MEMCACHED_PORT;
u_int32_t  mc_expire = 0;

int  process_arguments(int, char **);
int  validate_arguments(void);
void print_help(void);
void print_usage(void);

int verbose = 0;
thresholds *my_thresholds = NULL;

#if DO_TRACE
#define TRACE(fmt, ...)                         \
  {                                             \
    struct tm tm;                               \
    struct timeval tv;                          \
    gettimeofday(&tv, NULL);                    \
    localtime_r(&(tv.tv_sec), &tm);                            \
    printf("%02d:%02d:%02d.%06lu %.12s.%4d: (trace ) "fmt"\n", \
           tm.tm_hour,tm.tm_min,tm.tm_sec,                     \
           tv.tv_usec,                                         \
           __FILE__, __LINE__, __VA_ARGS__);                   \
  }
#else
#define TRACE(fmt, ...)
#endif

int main(int argc, char ** argv)
{
  struct memcache *mc;
  char             key[12];
  u_int32_t        keylen;
  char            *val;
  int              rv;
  struct timeval   tv;
  long             microsec;
  double           elapsed_time;

  setlocale (LC_ALL, "");
  bindtextdomain (PACKAGE, LOCALEDIR);
  textdomain (PACKAGE);

  /* Parse extra opts if any */
  argv = np_extra_opts (&argc, argv, progname);

  if (process_arguments (argc, argv) == ERROR)
    usage4 (_("Could not parse arguments"));

  TRACE("%s",">>main");

  // initialize
  gettimeofday(&tv, NULL);
  mc = mc_new();
  if (mc == NULL) {
    printf("MEMCACHED %s: failed to mc_new\n", _("CRITICAL"));
    exit(EXIT_CRITICAL);
  }
  TRACE("[server]%s:%s", mc_host, mc_port);
  rv = mc_server_add(mc, mc_host, mc_port);
  TRACE("[mc_server_add rv]%d", rv);
  if (rv != 0) {
    printf("MEMCACHED %s: failed to server_add (%d)\n", _("CRITICAL"), rv);
    exit(EXIT_CRITICAL);
  }

  srand(time(NULL) & getpid());
  sprintf(key, "%d_%s", rand(), mc_host);
  keylen = strlen(key);
  TRACE("[key]%s[keylen]%d", key, keylen);

  val = (char *)calloc(1, strlen(TEST_VAL)+1);
  sprintf(val, "%s", TEST_VAL);
  TRACE("[val]%s", val);

  // set
  TRACE("[expire]%d", mc_expire);
  rv = mc_set(mc, key, keylen, val, strlen(val), mc_expire, 0);
  TRACE("[set rv]%d", rv);
  if (rv != 0) {
    printf("MEMCACHED %s: failed to set (%d)\n", _("CRITICAL"), rv);
    exit(EXIT_CRITICAL);
  }
  free(val);

  // get
  val = (char *)mc_aget(mc, key, keylen);
  TRACE("[val]%s", val);
  if (val == NULL) {
    printf("MEMCACHED %s: failed to get after set\n", _("CRITICAL"));
    exit(EXIT_CRITICAL);
  }
  free(val);

  // delete
  rv = mc_delete(mc, key, keylen, 0);
  TRACE("[delete rv]%d", rv);
  if (rv != 0) {
    printf("MEMCACHED %s: failed to delete (%d)\n", _("CRITICAL"), rv);
    exit(EXIT_CRITICAL);
  }

  // get
  val = (char *)mc_aget(mc, key, keylen);
  TRACE("[val]%s", val);
  if (val != NULL) {
    printf("MEMCACHED %s: failed to get after delete\n", _("CRITICAL"));
    exit(EXIT_CRITICAL);
  }
  free(val);

  mc_free(mc);

  microsec = deltime(tv);
  elapsed_time = (double)microsec / 1.0e6;
  printf("MEMCACHED %s: %.3f seconds\n", _("OK"), elapsed_time);

  return 0;
}

/* process command-line arguments */
int
process_arguments (int argc, char **argv)
{
  int c;
  char *warning = NULL;
  char *critical = NULL;

  int option = 0;
  static struct option longopts[] = {
    {"hostname" ,required_argument, 0, 'H'},
    {"port"     ,required_argument, 0, 'P'},
    {"expire"   ,required_argument, 0, 'E'},
    {"verbose"  ,no_argument,       0, 'v'},
    {"version"  ,no_argument,       0, 'V'},
    {"help"     ,no_argument,       0, 'h'},
    {"warning"  ,required_argument, 0, 'w'},
    {"critical" ,required_argument, 0, 'c'},
    {0, 0, 0, 0}
  };

  if (argc < 1)
    return ERROR;

  while (1) {
    c = getopt_long (argc, argv, "H:P:E:vVhw:c:", longopts, &option);

    if (c == -1 || c == EOF)
      break;

    switch (c) {
    case 'H':
      if (is_host(optarg)) {
        mc_host = optarg;
      }
      else {
        usage2(_("Invalid hostname/address"), optarg);
      }
      break;
    case 'P':
      mc_port = optarg;
      break;
    case 'E':
      mc_expire = atoi(optarg);
      break;
    case 'v':
      verbose++;
      break;
    case 'V':
      print_revision(progname, revision);
      exit(STATE_OK);
    case 'h':
      print_help();
      exit (STATE_OK);
    case 'w':
      warning  = optarg;
      break;
    case 'c':
      critical = optarg;
      break;
    case '?':
      usage5();
    }
  }

  c = optind;

  set_thresholds(&my_thresholds, warning, critical);

  return validate_arguments();
}


int validate_arguments(void)
{
  if (mc_host == NULL)
    usage("Must specify memcached server");

  return OK;
}


void print_help(void)
{
  char *mcport;
  asprintf(&mcport, "%s", MEMCACHED_PORT);

  print_revision (progname, revision);

  printf (_(MY_COPYRIGHT), copyright, email);

  printf ("%s\n", _("This program checks results of request sequentially: SET, GET, DELETE, GET"));

  printf ("\n\n");

  print_usage ();

  printf (_(UT_HELP_VRSN));
  printf (_(UT_EXTRA_OPTS));
  printf (_(UT_WARN_CRIT_RANGE));
  printf (_(UT_HOST_PORT), 'P', mcport);
  printf (" -E, --expire=INTEGER\n    expire time(second) for SET command (default: 0)\n");

#ifdef NP_EXTRA_OPTS
  printf ("\n");
  printf ("%s\n", _("Notes:"));
  printf (_(UT_EXTRA_OPTS_NOTES));
#endif

  /* printf (_(UT_SUPPORT)); */
  puts("\nRepository:\n  http://github.com/hirose31/nagios-check_memcached_paranoid/tree/master\n\n");
}


void print_usage(void)
{
  printf (_("Usage:"));
  printf (" %s -H host [-P port] [-E expire] [-w warn] [-c crit]\n", progname);
}
