/*
 *  mem_freebsd.h
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

#ifndef __MEM_FREEBSD_H__
#define __MEM_FREEBSD_H__

extern long long int mem_total, mem_used;
extern long long int mem_shared, mem_buffers, mem_cached;
extern long long int swp_total, swp_used;

void mem_init();
void mem_getfree();

#endif /* __MEM_FREEBSD_H__ */
