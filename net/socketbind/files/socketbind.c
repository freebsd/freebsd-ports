#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dlfcn.h>

static void *socket_p, *dl_handle;

static struct sockaddr_in bind_addr;
static int	   do_bind;

int socket(int domain, int type, int protocol) {
	auto int res;
	if (dl_handle == NULL) {
		char *str;
		dl_handle = dlopen("/usr/lib/libc.so", RTLD_LAZY);
		if (dl_handle == NULL) 
			return -1;
		socket_p = dlsym(dl_handle, "socket");
		if (!socket_p)
			return -1;
#ifdef DEBUG
		printf("Loaded socket %x\n", socket_p);
#endif

		if ((str = getenv("BINDTO")) != NULL) {
#ifdef DEBUG
			printf("Thinking about bind\n");
#endif
			if (ascii2addr(AF_INET, str, &bind_addr.sin_addr)) {
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

