--- config/m4/init.m4.orig	Tue Nov 28 15:12:04 2006
+++ config/m4/init.m4	Sun Feb 25 16:51:02 2007
@@ -142,6 +142,101 @@
    abi_cpu_bits="64"
    ;;
 
+   i386-*freebsd*)
+   dnl Pentium 3 ?
+   if test "${abi_cpu_model}" = ""; then
+    abi_cpu_model=`sysctl hw.model | grep 'Pentium III'`
+    if test "${abi_cpu_model}" != ""; then
+     abi_cpu_model="pentium3"
+     abi_cpu_64bits="no"
+     abi_cpu_bits="32"
+    fi
+   fi
+   dnl Pentium 4 ?
+   if test "${abi_cpu_model}" = ""; then
+    abi_cpu_model=`sysctl hw.model | grep 'Intel(R) Pentium(R) 4'`
+    if test "${abi_cpu_model}" != ""; then
+     abi_cpu_model="pentium4"
+     abi_cpu_64bits="no"
+     abi_cpu_bits="32"
+    fi
+   fi
+   dnl Pentium 4M ?
+   if test "${abi_cpu_model}" = ""; then
+    abi_cpu_model=`sysctl hw.model | grep 'Intel(R) Pentium(R) M'`
+    if test "${abi_cpu_model}" != ""; then
+     abi_cpu_model="pentium4"
+     abi_cpu_64bits="no"
+     abi_cpu_bits="32"
+    fi
+   fi
+   dnl Unknown
+   if test "${abi_cpu_model}" = ""; then
+    abi_cpu_model="unknown"
+   fi
+   dnl The processor is anyway 32-bit
+   abi_cpu_64bits="no"
+   abi_cpu_bits="32"
+   ;;
+
+   amd64-*freebsd*)
+   dnl Opteron ?
+   if test "${abi_cpu_model}" = ""; then
+    abi_cpu_model=`sysctl hw.model | grep 'Opteron'`
+    if test "${abi_cpu_model}" != ""; then
+     abi_cpu_model="opteron"
+     abi_cpu_64bits="yes"
+     abi_cpu_bits="64"
+    fi
+   fi
+   dnl Xeon ?
+   if test "${abi_cpu_model}" = ""; then
+    abi_cpu_model=`sysctl hw.model | grep 'Intel(R) XEON(TM)'`
+    if test "${abi_cpu_model}" != ""; then
+     abi_cpu_model="xeon"
+     abi_cpu_64bits="yes"
+     abi_cpu_bits="64"
+    fi
+   fi
+   dnl Unknown
+   if test "${abi_cpu_model}" = ""; then
+    abi_cpu_model="unknown"
+   fi
+   dnl The processor is anyway 64-bit
+   abi_cpu_64bits="yes"
+   abi_cpu_bits="64"
+   ;;
+
+  ia64-*freebsd*)
+   dnl Itanium 1 ?
+   if test "${abi_cpu_model}" = ""; then
+    abi_cpu_model=`sysctl hw.model | grep 'Itanium 1'`
+    if test "${abi_cpu_model}" = ""; then
+     abi_cpu_model="itanium1"
+    fi
+   fi
+   dnl Itanium 2 ?
+   if test "${abi_cpu_model}" = ""; then
+    abi_cpu_model=`sysctl hw.model | grep 'Itanium 2'`
+    if test "${abi_cpu_model}" != ""; then
+     abi_cpu_model="itanium2"
+    fi
+   fi
+   dnl Unknown
+   if test "${abi_cpu_model}" = ""; then
+    abi_cpu_model="unknown"
+   fi
+   dnl The processor is anyway 64-bit
+   abi_cpu_64bits="yes"
+   abi_cpu_bits="64"
+   ;;
+
+   sparc64-*freebsd*)
+    abi_cpu_model="unknown"
+    abi_cpu_64bits="yes"
+    abi_cpu_bits="64"
+   ;;
+
  esac
 
  AC_SUBST(abi_cpu_model)
