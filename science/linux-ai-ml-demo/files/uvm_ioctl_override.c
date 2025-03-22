// Downloaded from https://gist.github.com/shkhln/40ef290463e78fb2b0000c60f4ad797e

#define _GNU_SOURCE

#include <assert.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>

// pkg install linux-c7-devtools
// /compat/linux/bin/cc --sysroot=/compat/linux -m64 -std=c99 -Wall -ldl -fPIC -shared -o dummy-uvm.so uvm_ioctl_override.c
// env LD_PRELOAD=$PWD/dummy-uvm.so <cmd>

#define NV_UVM_INITIALIZE   0x30000001
#define NV_UVM_DEINITIALIZE 0x30000002

#define NV_ERR_NOT_SUPPORTED 0x56

struct NvUvmInitParams
{
  uint64_t flags __attribute__((aligned(8)));
  uint32_t status;
};

int (*libc_ioctl)(int fd, unsigned long request, ...) = NULL;

int ioctl(int fd, unsigned long request, ...) {

  if (!libc_ioctl) {
    libc_ioctl = dlsym(RTLD_NEXT, "ioctl");
  }

  va_list _args_;
  va_start(_args_, request);
  void* data = va_arg(_args_, void*);
  va_end(_args_);

  if (request == NV_UVM_INITIALIZE) {
    struct NvUvmInitParams* params = (struct NvUvmInitParams*)data;
    params->status = NV_ERR_NOT_SUPPORTED;
    return 0;
  }

  if (request == NV_UVM_DEINITIALIZE) {
    return 0;
  }

  return libc_ioctl(fd, request, data);
}

int (*libc_open)(const char* path, int flags, ...) = NULL;

int open(const char* path, int flags, ...) {

  if (!libc_open) { libc_open = dlsym(RTLD_NEXT, "open"); }

  mode_t mode = 0;

  va_list _args_;
  va_start(_args_, flags);

  if (flags & O_CREAT) {
    mode = va_arg(_args_, int);
  }

  va_end(_args_);

  if (strcmp("/dev/nvidia-uvm", path) == 0) {
    return libc_open("/dev/null", flags, mode);
  }

  return libc_open(path, flags, mode);
}

FILE* (*libc_fopen)(const char* path, const char* mode) = NULL;

FILE* fopen(const char* path, const char* mode) {

  if (!libc_fopen) { libc_fopen = dlsym(RTLD_NEXT, "fopen"); }

  if (strncmp(path, "/proc/self/task/", sizeof("/proc/self/task/") - 1) == 0) {
    char* tail = strchr(path + sizeof("/proc/self/task/"), '/');
    if (tail != NULL && strcmp(tail, "/comm") == 0) {
      assert(strcmp(mode, "wb") == 0);
      return libc_fopen("/dev/null", mode);
    }
  }

  return libc_fopen(path, mode);
}
