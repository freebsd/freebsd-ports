#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <dlfcn.h>
#include <stdlib.h>

static void *socket_p = NULL;

static struct sockaddr_in bind_addr;
static int	   do_bind;

int socket(int domain, int type, int protocol) {
	auto int res;
	if (socket_p == NULL) {
		char *str;
		socket_p = dlsym(RTLD_NEXT, "socket");
		if (!socket_p)
			return -1;
#ifdef DEBUG
		printf("Loaded socket %x\n", socket_p);
#endif

		if ((domain == PF_INET) && (str = getenv("BINDTO")) != NULL) {
#ifdef DEBUG
			printf("Thinking about bind\n");
#endif
			if (inet_aton(str, &bind_addr.sin_addr)) {
				do_bind = 1;
				bind_addr.sin_len = INET_ADDRSTRLEN;
				bind_addr.sin_family = AF_INET;
#ifdef DEBUG
				printf("WILL DO BIND %s, %x\n", str, bind_addr.sin_addr.s_addr);
#endif
			}
		}
	}
	res = ((int(*)(int a, int b, int c))socket_p)(domain, type, protocol); 
	if (do_bind) {
		bind(res, (struct sockaddr*)&bind_addr, INET_ADDRSTRLEN);
	}
	return res;
};

