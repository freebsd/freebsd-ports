--- platform/FreeBSD/conf.sh.orig	Thu Mar 10 09:34:37 2005
+++ platform/FreeBSD/conf.sh	Thu Mar 10 09:35:24 2005
@@ -1,25 +1,34 @@
-case `grep -cq "m_drops" /usr/include/sys/mbuf.h` in
-1)	echo "#define HAS_MBUF_MDROPS	1" ;;
-0)	echo "#undef HAS_MBUF_MDROPS" ;;
-esac;
-case `grep -cq "sf_allocfail" /usr/include/sys/mbuf.h` in
-1)	echo "#define HAS_MBUF_SFALLOCFAIL	1" ;;
-0)	echo "#undef HAS_MBUF_SFALLOCFAIL" ;;
-esac;
-case `grep -cq "VM_TOTAL" /usr/include/vm/vm_param.h` in
-0)      echo "#define VM_TOTAL VM_METER" ;;
-esac;
-sysctl -N vm.nswapdev 1>/dev/null 2>&1
-case $? in
-1)      echo "#undef HAS_VM_NSWAPDEV" ;;
-0)      echo "#define HAS_VM_NSWAPDEV	1" ;;
-esac;
+#!/bin/sh
+if grep -q "m_drops" /usr/include/sys/mbuf.h; then
+	echo "#define HAS_MBUF_MDROPS	1"
+else
+	echo "#undef HAS_MBUF_MDROPS"
+fi
+if grep -q "sf_allocfail" /usr/include/sys/mbuf.h; then
+	echo "#define HAS_MBUF_SFALLOCFAIL	1"
+else
+	echo "#undef HAS_MBUF_SFALLOCFAIL"
+fi
+if ! grep -q "VM_TOTAL" /usr/include/vm/vm_param.h; then
+	echo "#define VM_TOTAL VM_METER"
+fi
+if grep -q "struct xswdev" /usr/include/vm/vm_param.h; then
+	echo "#define HAS_VM_NSWAPDEV	1"
+else
+	echo "#undef HAS_VM_NSWAPDEV"
+fi
 if [ -f /usr/include/net/pfvar.h ]; then
     echo "#define HAS_PFVAR_H	1"
 else
     echo "#undef HAS_PFVAR_H"
-fi;
-case `grep -cq "ki_paddr" /usr/include/sys/user.h` in
-1)      echo "#define HAS_KI_PADDR	1" ;;
-0)      echo "#undef HAS_KI_PADDR" ;;
-esac;
\ No newline at end of file
+fi
+if grep -q "ki_paddr" /usr/include/sys/user.h; then
+	echo "#define HAS_KI_PADDR	1"
+else
+	echo "#undef HAS_KI_PADDR"
+fi
+if grep -q "struct rusage_ext" /usr/include/sys/proc.h; then
+	echo "#define HAS_RUSAGE_EXT	1"
+else
+	echo "#undef HAS_RUSAGE_EXT"
+fi
