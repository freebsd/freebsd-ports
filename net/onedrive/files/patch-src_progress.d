--- src/progress.d.orig	2019-04-16 02:18:26 UTC
+++ src/progress.d
@@ -7,6 +7,20 @@ import std.datetime;
 import core.sys.posix.unistd;
 import core.sys.posix.sys.ioctl;
 
+// core.sys.posix.sys.ioccom;
+enum uint IOCPARM_MASK = 0x1fff; // parameter length, at most 13 bits
+enum uint IOC_OUT = 0x40000000; // copy parameters back
+
+uint _IOC(T=typeof(null))(uint inorout, uint group, uint num, size_t len)
+{
+    return (inorout | ((len & IOCPARM_MASK) << 16) | (group << 8) | num);
+}
+uint _IOR(T)(char g, int n)
+{
+    return _IOC!(T)(IOC_OUT, cast(uint)g, cast(uint)n, T.sizeof);
+}
+enum uint TIOCGWINSZ = _IOR!(winsize)('t', 104);
+
 class Progress
 {
   private:
