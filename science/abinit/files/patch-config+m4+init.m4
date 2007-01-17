Apparently this code is not good...abi_cpu_bits must be
determined by different way.

--- config/m4/init.m4~	Tue Nov 28 15:12:04 2006
+++ config/m4/init.m4	Wed Jan 17 11:49:35 2007
@@ -142,6 +142,53 @@
    abi_cpu_bits="64"
    ;;
 
+   *-*freebsd*)
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
+
  esac
 
  AC_SUBST(abi_cpu_model)
