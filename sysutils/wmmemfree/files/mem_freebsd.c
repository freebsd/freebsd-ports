/*
 *  mem_freebsd.c - get memory status
 *
 *  Copyright (C) 2003 Alexey Dokuchaev <danfe@regency.nsu.ru>
 *	Parts are Copyright (C) 1993-2003 FreeBSD Project
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Street #330, Boston, MA 02111-1307, USA.
 */

#include <sys/types.h>
#include <sys/vmmeter.h>
#include <fcntl.h>
#include <kvm.h>
#include <nlist.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "mem_freebsd.h"

long long int mem_total, mem_used, mem_free, mem_buffers, mem_cached;
long long int swp_total, swp_used, swp_free;

static kvm_t *kd;
struct nlist nlst[] = { {"_cnt"}, {"_bufspace"}, {0} };

void
mem_init(void)
{
	int pagesize;

	if (!(kd = kvm_open(NULL, NULL, NULL, O_RDONLY, "kvm_open")))
	{
		perror("kvm_open");
		exit(1);
	}

	kvm_nlist(kd, nlst);

	if (!nlst[0].n_type)
	{
		perror("kvm_nlist");
		exit(1);
	}

	seteuid(getuid());
	setegid(getgid());

	if (geteuid() != getuid() || getegid() != getgid())
	{
		perror("sete?id");
		exit(1);
	}
}

void
mem_getfree()
{
	struct vmmeter vm;
	struct kvm_swap sw;
	int bufspace = 0;
	unsigned long cnt_offset;
	unsigned long bufspace_offset;

	static int firsttime = 1;
	static int pagesin = -1;
	static int pagesout = -1;
	static time_t lasttime = 0;
	time_t curtime;

	if ((kvm_read(kd, nlst[0].n_value, &vm, sizeof(vm))
		!= sizeof(vm)) ||
	    (kvm_read(kd, nlst[1].n_value, &bufspace, sizeof(bufspace))
		!= sizeof(bufspace)))
	{
		perror("kvm_read");
		exit(1);
	}

	mem_total = vm.v_page_count;
	mem_free = vm.v_free_count;
	mem_used = mem_total - mem_free;
	mem_cached = vm.v_cache_count;
	mem_buffers = bufspace / vm.v_page_size;

	/*
	 * Only calculate when first time or when changes took place.
	 * Do not call it more than 1 time per 2 seconds; otherwise
	 * it can eat up to 50% of CPU time on heavy swap activity.
	 */

	curtime = time(NULL);

	if (firsttime ||
	    (((vm.v_swappgsin > pagesin) ||
	    (vm.v_swappgsout > pagesout))
		&& curtime > lasttime + 1))
	{
		if (kvm_getswapinfo(kd, &sw, 1, 0) >= 0 &&
			sw.ksw_total)
		{
			swp_total = sw.ksw_total;
			swp_used = sw.ksw_used;
			swp_free = swp_total - swp_used;
		}
		firsttime = 0;
		lasttime = curtime;
	}
	pagesin = vm.v_swappgsin;
	pagesout = vm.v_swappgsout;
}
