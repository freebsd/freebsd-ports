/*
 *  cpu_freebsd.h
 *
 *  Copyright (C) 2003 Alexey Dokuchaev <danfe@regency.nsu.ru>
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

#ifndef __CPU_FREEBSD_H__
#define __CPU_FREEBSD_H__

extern int cpu_used;
extern int history[16];

void cpu_init(void);
void cpu_getusage(void);

#endif /* __CPU_FREEBSD_H__ */
