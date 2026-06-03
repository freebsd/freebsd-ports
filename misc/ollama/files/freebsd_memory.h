// Copyright © 2025 Apple Inc.

#pragma once

#include <sys/types.h>
#include <sys/sysctl.h>

namespace {

size_t get_memory_size() {
  size_t physmem = 0;
  size_t len = sizeof(physmem);
  if (sysctlbyname("hw.physmem", &physmem, &len, NULL, 0) != 0) {
    return 0;
  }
  return physmem;
}

} // namespace
