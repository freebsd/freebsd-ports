//go:build freebsd

package ipc

// FIONREAD ioctl to get the number of bytes available to read.
// Same value as Darwin: _IOR('f', 127, int).
const FIONREAD = 0x4004667f
