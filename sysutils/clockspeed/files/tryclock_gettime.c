#include <sys/time.h>

main()
{
  struct timespec ts;

  (void) clock_gettime(CLOCK_REALTIME, &ts);
}
