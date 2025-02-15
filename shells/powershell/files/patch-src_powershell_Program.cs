--- src/powershell/Program.cs.orig	2024-03-30 20:39:17 UTC
+++ src/powershell/Program.cs
@@ -56,6 +56,13 @@ namespace Microsoft.PowerShell
         private const int MACOS_KERN_ARGMAX = 8;
         private const int MACOS_KERN_PROCARGS2 = 49;
         private const int MACOS_PROC_PIDPATHINFO_MAXSIZE = 4096;
+
+        // FreeBSD p/Invoke constants
+        private const int FREEBSD_CTL_KERN = 1;
+        private const int FREEBSD_KERN_PROC = 14;
+        private const int FREEBSD_KERN_PROC_ARGS = 7;
+        private const int FREEBSD_KERN_PROC_PATHNAME = 12;
+        private const int FREEBSD_ENOMEM = 12;
 #endif
 
         /// <summary>
@@ -125,7 +132,62 @@ namespace Microsoft.PowerShell
                 ThrowOnFailure("exec", ExecPwshLogin(args, pwshPath, isMacOS: false));
                 return;
             }
+            else if (OperatingSystem.IsFreeBSD())
+            {
+                Span<int> fmib = stackalloc int[4];
+                int fmibLength = 4;
+                fmib[0] = FREEBSD_CTL_KERN;
+                fmib[1] = FREEBSD_KERN_PROC;
+                fmib[2] = FREEBSD_KERN_PROC_ARGS;
+                fmib[3] = -1;
 
+                int sz = 1;
+                unsafe
+                {
+                    fixed (int *mibptr = fmib)
+                    {
+                        ThrowOnFailure(nameof(procNameFirstByte), SysCtl(mibptr, fmibLength, &procNameFirstByte, &sz, IntPtr.Zero, 0), FREEBSD_ENOMEM);
+                    }
+                }
+
+                if (!IsLogin(procNameFirstByte, args))
+                {
+                    return;
+                }
+
+                fmib[2] = FREEBSD_KERN_PROC_PATHNAME;
+                int pathsz = 0;
+
+                unsafe
+                {
+                    fixed (int *mibptr = fmib)
+                    {
+                        ThrowOnFailure(nameof(pathsz), SysCtl(mibptr, fmibLength, (void *)null, &pathsz, IntPtr.Zero, 0));
+                    }
+                }
+
+                IntPtr execPathPtr = Marshal.AllocHGlobal(pathsz);
+                try
+                {
+                    unsafe
+                    {
+                        fixed (int *mibptr = fmib)
+                        {
+                            ThrowOnFailure(nameof(execPathPtr), SysCtl(mibptr, fmibLength, execPathPtr.ToPointer(), &pathsz, IntPtr.Zero, 0));
+                        }
+                    }
+                    string? execPath = Marshal.PtrToStringAnsi(execPathPtr);
+                    ArgumentNullException.ThrowIfNull(execPath);
+                    ThrowOnFailure("exec", ExecPwshLogin(args, execPath, isMacOS: false));
+                }
+                finally
+                {
+                    Marshal.FreeHGlobal(execPathPtr);
+                }
+
+                return;
+            }
+
             // At this point, we are on macOS
 
             // Set up the mib array and the query for process maximum args size
@@ -417,11 +479,13 @@ namespace Microsoft.PowerShell
         /// </summary>
         /// <param name="call">The native call that was attempted.</param>
         /// <param name="code">The exit code it returned.</param>
-        private static void ThrowOnFailure(string call, int code)
+        /// <param name="ignore">Ignore this error, consider it success.</param>
+        private static void ThrowOnFailure(string call, int code, int ignore = 0)
         {
             if (code < 0)
             {
                 code = Marshal.GetLastWin32Error();
+                if (code == ignore) return;
                 Console.Error.WriteLine($"Call to '{call}' failed with errno {code}");
                 throw new StartupException(call, code);
             }
