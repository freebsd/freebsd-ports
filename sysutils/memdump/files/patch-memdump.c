--- memdump.c.orig	Thu Jan  1 19:30:09 2004
+++ memdump.c	Sun Feb 20 15:58:34 2005
@@ -1,92 +1,92 @@
 /*++
-/* NAME
-/*	memdump 1
-/* SUMMARY
-/*	memory dumper
-/* SYNOPSIS
-/* .ad
-/* .fi
-/*	\fBmemdump\fR [\fB-kv\fR] [\fB-b \fIbuffer_size\fR]
-/*	[\fB-d \fIdump_size\fR] [\fB-m \fImap_file\fR] [\fB-p \fIpage_size\fR]
-/* DESCRIPTION
-/*	This program dumps system memory to the standard output stream, 
-/*	skipping over holes in memory maps.
-/*	By default, the program dumps the contents of physical memory
-/*	(\fB/dev/mem\fR).
-/*
-/*	Output is in the form of a raw dump; if necessary, use the \fB-m\fR
-/*	option to capture memory layout information.
-/*
-/*	Output should be sent off-host over the network, to avoid changing
-/*	all the memory in the file system cache. Use netcat, stunnel, or
-/*	openssl, depending on your requirements.
-/*
-/*	The size arguments below understand the \fBk\fR (kilo) \fBm\fR (mega)
-/*	and \fBg\fR (giga) suffixes. Suffixes are case insensitive.
-/*
-/*	Options
-/* .IP \fB-k\fR
-/*	Attempt to dump kernel memory (\fB/dev/kmem\fR) rather than physical
-/*	memory.
-/* .sp
-/*	Warning: this can lock up the system to the point that you have
-/*	to use the power switch (for example, Solaris 8 on 64-bit SPARC).
-/* .sp
-/*	Warning: this produces bogus results on Linux 2.2 kernels.
-/* .sp
-/*	Warning: this is very slow on 64-bit machines because the entire
-/*	memory address range has to be searched.
-/* .sp
-/*	Warning: kernel virtual memory mappings change frequently. Depending
-/*	on the operating system, mappings smaller than \fIpage_size\fR or
-/*	\fIbuffer_size\fR may be missed or may be reported incorrectly.
-/* .IP "\fB-b \fIbuffer_size\fR (default: 0)"
-/*	Number of bytes per memory read operation. By default, the program
-/*	uses the \fIpage_size\fR value.
-/* .sp
-/*	Warning: a too large read buffer size causes memory to be missed on
-/*	FreeBSD or Solaris.
-/* .IP "\fB-d \fIdump-size\fR (default: 0)"
-/*	Number of memory bytes to dump. By default, the program runs
-/*	until the memory device reports an end-of-file (Linux), or until
-/*	it has dumped from \fB/dev/mem\fR as much memory as reported present
-/*	by the kernel (FreeBSD, Solaris), or until pointer wrap-around happens.
-/* .sp
-/*	Warning: a too large value causes the program to spend a lot of time
-/*	skipping over non-existent memory on Solaris systems.
-/* .sp
-/*	Warning: a too large value causes the program to copy non-existent
-/*	data on FreeBSD systems.
-/* .IP "\fB-m\fR \fImap_file\fR"
-/*	Write the memory map to \fImap_file\fR, one entry per line.
-/*	Specify \fB-m-\fR to write to the standard error stream.
-/*	Each map entry consists of a region start address and the first
-/*	address beyond that region. Addresses are separated by space,
-/*	and are printed as hexadecimal numbers (0xhhhh).
-/* .IP "\fB-p \fIpage_size\fR (default: 0)"
-/*	Use \fIpage_size\fR as the memory page size. By default the program
-/*	uses the system page size.
-/* .sp
-/*	Warning: a too large page size causes memory to be missed
-/*	while skipping over holes in memory.
-/* .IP \fB-v\fR
-/*	Enable verbose logging for debugging purposes. Multiple \fB-v\fR
-/*	options make the program more verbose.
-/* BUGS
-/*	On many hardware platforms the firmware (boot PROM, BIOS, etc.)
-/*	takes away some memory. This memory is not accessible through
-/*	\fB/dev/mem\fR.
-/*
-/*	This program should produce output in a format that supports
-/*	structure information such as ELF.
-/* LICENSE
-/*	This software is distributed under the IBM Public License.
-/* AUTHOR
-/*	Wietse Venema
-/*	IBM T.J. Watson Research
-/*	P.O. Box 704
-/*	USA
-/*--*/
+ * NAME
+ *	memdump 1
+ * SUMMARY
+ *	memory dumper
+ * SYNOPSIS
+ * .ad
+ * .fi
+ *	\fBmemdump\fR [\fB-kv\fR] [\fB-b \fIbuffer_size\fR]
+ *	[\fB-d \fIdump_size\fR] [\fB-m \fImap_file\fR] [\fB-p \fIpage_size\fR]
+ * DESCRIPTION
+ *	This program dumps system memory to the standard output stream, 
+ *	skipping over holes in memory maps.
+ *	By default, the program dumps the contents of physical memory
+ *	(\fB/dev/mem\fR).
+ *
+ *	Output is in the form of a raw dump; if necessary, use the \fB-m\fR
+ *	option to capture memory layout information.
+ *
+ *	Output should be sent off-host over the network, to avoid changing
+ *	all the memory in the file system cache. Use netcat, stunnel, or
+ *	openssl, depending on your requirements.
+ *
+ *	The size arguments below understand the \fBk\fR (kilo) \fBm\fR (mega)
+ *	and \fBg\fR (giga) suffixes. Suffixes are case insensitive.
+ *
+ *	Options
+ * .IP \fB-k\fR
+ *	Attempt to dump kernel memory (\fB/dev/kmem\fR) rather than physical
+ *	memory.
+ * .sp
+ *	Warning: this can lock up the system to the point that you have
+ *	to use the power switch (for example, Solaris 8 on 64-bit SPARC).
+ * .sp
+ *	Warning: this produces bogus results on Linux 2.2 kernels.
+ * .sp
+ *	Warning: this is very slow on 64-bit machines because the entire
+ *	memory address range has to be searched.
+ * .sp
+ *	Warning: kernel virtual memory mappings change frequently. Depending
+ *	on the operating system, mappings smaller than \fIpage_size\fR or
+ *	\fIbuffer_size\fR may be missed or may be reported incorrectly.
+ * .IP "\fB-b \fIbuffer_size\fR (default: 0)"
+ *	Number of bytes per memory read operation. By default, the program
+ *	uses the \fIpage_size\fR value.
+ * .sp
+ *	Warning: a too large read buffer size causes memory to be missed on
+ *	FreeBSD or Solaris.
+ * .IP "\fB-d \fIdump-size\fR (default: 0)"
+ *	Number of memory bytes to dump. By default, the program runs
+ *	until the memory device reports an end-of-file (Linux), or until
+ *	it has dumped from \fB/dev/mem\fR as much memory as reported present
+ *	by the kernel (FreeBSD, Solaris), or until pointer wrap-around happens.
+ * .sp
+ *	Warning: a too large value causes the program to spend a lot of time
+ *	skipping over non-existent memory on Solaris systems.
+ * .sp
+ *	Warning: a too large value causes the program to copy non-existent
+ *	data on FreeBSD systems.
+ * .IP "\fB-m\fR \fImap_file\fR"
+ *	Write the memory map to \fImap_file\fR, one entry per line.
+ *	Specify \fB-m-\fR to write to the standard error stream.
+ *	Each map entry consists of a region start address and the first
+ *	address beyond that region. Addresses are separated by space,
+ *	and are printed as hexadecimal numbers (0xhhhh).
+ * .IP "\fB-p \fIpage_size\fR (default: 0)"
+ *	Use \fIpage_size\fR as the memory page size. By default the program
+ *	uses the system page size.
+ * .sp
+ *	Warning: a too large page size causes memory to be missed
+ *	while skipping over holes in memory.
+ * .IP \fB-v\fR
+ *	Enable verbose logging for debugging purposes. Multiple \fB-v\fR
+ *	options make the program more verbose.
+ * BUGS
+ *	On many hardware platforms the firmware (boot PROM, BIOS, etc.)
+ *	takes away some memory. This memory is not accessible through
+ *	\fB/dev/mem\fR.
+ *
+ *	This program should produce output in a format that supports
+ *	structure information such as ELF.
+ * LICENSE
+ *	This software is distributed under the IBM Public License.
+ * AUTHOR
+ *	Wietse Venema
+ *	IBM T.J. Watson Research
+ *	P.O. Box 704
+ *	USA
+ *--*/
 
 /* System libraries. */
 
@@ -108,7 +108,7 @@
 #endif
 
 #if defined(FREEBSD2) || defined(FREEBSD3) || defined(FREEBSD4) \
-	|| defined(FREEBSD5) \
+	|| defined(FREEBSD5) || defined(FREEBSD6) \
 	|| defined(OPENBSD2) || defined(OPENBSD3) \
 	|| defined(BSDI2) || defined(BSDI3) || defined(BSDI4)
 #include <sys/param.h>
@@ -184,7 +184,7 @@
 #endif
 
 #if defined(FREEBSD2) || defined(FREEBSD3) || defined(FREEBSD4) \
-	|| defined(FREEBSD5) \
+	|| defined(FREEBSD5) || defined(FREEBSD6) \
 	|| defined(OPENBSD2) || defined(OPENBSD3)
     int     name[] = {CTL_HW, HW_PHYSMEM};
     size_t  len;
@@ -220,9 +220,9 @@
 static void dump_memory(int fd, FILE * map, char *buffer, size_t buffer_size,
 		              size_t dump_size, size_t page_size, int flags)
 {
-    OFFT_TYPE start;
-    OFFT_TYPE where;
-    OFFT_TYPE count;
+    OFFT_TYPE start = 0;
+    OFFT_TYPE where = 0;
+    OFFT_TYPE count = 0;
     size_t  todo;
     ssize_t read_count;
     int     in_region = 0;
