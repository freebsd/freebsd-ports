#include <sys/cdefs.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <resolv.h>

int *
__h_error(void)
{
        return (&__res_state()->res_h_errno);
}
