-- Add the missing NOTE_PCTRLMASK kevent flag constant for FreeBSD 15.x.
-- This constant is defined in sys/event.h on FreeBSD 15+ but is absent
-- from the libc-0.2.190 crate, causing mio to fail to compile.
-- Upstream libc has not yet included this constant for FreeBSD.
-- upstreamed: https://github.com/rust-lang/libc/pull/5679

--- cargo-crates/libc-0.2.190/src/unix/bsd/freebsdlike/freebsd/mod.rs.orig	2026-10-29 11:22:17.274961000 -0700
+++ cargo-crates/libc-0.2.190/src/unix/bsd/freebsdlike/freebsd/mod.rs	2026-10-29 11:22:17.275847000 -0700
@@ -2262,6 +2262,7 @@
 pub const NOTE_FFOR: u32 = 0x80000000;
 pub const NOTE_FFCOPY: u32 = 0xc0000000;
 pub const NOTE_FFCTRLMASK: u32 = 0xc0000000;
+pub const NOTE_PCTRLMASK: u32 = 0xfc000000;
 pub const NOTE_FFLAGSMASK: u32 = 0x00ffffff;
 pub const NOTE_LOWAT: u32 = 0x00000001;
 pub const NOTE_FILE_POLL: u32 = 0x00000002;
