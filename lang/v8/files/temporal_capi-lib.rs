// temporal_capi is no_std, so it can not be built as a static library on its
// own: there would be no panic handler.  Re-exporting it from a crate that
// links std provides one, and keeps its #[no_mangle] C API in the archive.
pub use temporal_capi::*;
