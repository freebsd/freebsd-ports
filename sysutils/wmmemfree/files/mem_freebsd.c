#include <sys/types.h>
#include <sys/sysctl.h>
#include <vm/vm_param.h>
#include <unistd.h>

long long int mem_total, mem_used, mem_buffers, mem_cached;
long long int swp_total, swp_used;

enum { total, active, laundry, wired, buffers, swap };
int mib[swap - total + 1][4];
/*
 * Values below are in kilobytes: we don't need higher granulation,
 * and it allows to keep numbers relatively small.
 */
unsigned int mem[swap - total];
int pagesize;

void
mem_init()
{
	size_t len = 4;

	/* Precache MIB name vectors for faster lookups later */
	sysctlnametomib("vm.stats.vm.v_page_count", mib[total], &len);
	sysctlnametomib("vm.stats.vm.v_active_count", mib[active], &len);
	sysctlnametomib("vm.stats.vm.v_laundry_count", mib[laundry], &len);
	sysctlnametomib("vm.stats.vm.v_wire_count", mib[wired], &len);

	len = 2;
	sysctlnametomib("vfs.bufspace", mib[buffers], &len);
	sysctlnametomib("vm.swap_info", mib[swap], &len);

	pagesize = getpagesize() / 1024;
}

static void
get_swap_info()
{
	struct xswdev xsw;
	size_t len = sizeof(xsw);
	int n;

	for (swp_total = swp_used = n = 0; ; ++n) {
		mib[swap][2] = n;
		if (sysctl(mib[swap], 3, &xsw, &len, NULL, 0) == -1)
			break;
		swp_total += pagesize * xsw.xsw_nblks;
		swp_used += pagesize * xsw.xsw_used;
	}
}

void
mem_getfree()
{
	size_t len = 4;
	int n;

	for (n = 0; n < buffers - total; ++n)
		sysctl(mib[n], 4, &mem[n], &len, NULL, 0);
	sysctl(mib[buffers], 2, &mem[buffers], &len, NULL, 0);

	/*
	 * See the following links for explanation which pages we consider
	 * free and used (cf. Linux vs. FreeBSD):
	 * https://unix.stackexchange.com/questions/14102/real-memory-usage
	 * https://unix.stackexchange.com/questions/134862/what-do-the-different-memory-counters-in-freebsd-mean
	 */
	mem_total = pagesize * mem[total];
	/* On FreeBSD, "Laundry" had replaced "Cache" in November 2016 */
	mem_cached = pagesize * mem[laundry];
	mem_buffers = mem[buffers] / 1024;
	mem_used = pagesize * (mem[active] + mem[wired]);
	mem_used += mem_cached + mem_buffers;

	get_swap_info();
}
