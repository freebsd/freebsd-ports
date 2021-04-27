// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_FILES_DIR_READER_FREEBSD_H_
#define BASE_FILES_DIR_READER_FREEBSD_H_

#include <errno.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

#include "base/logging.h"
#include "base/posix/eintr_wrapper.h"

// See the comments in dir_reader_posix.h about this.

namespace base {

class DirReaderFreeBSD {
 public:
  explicit DirReaderFreeBSD(const char* directory_path)
      : fd_(open(directory_path, O_RDONLY | O_DIRECTORY)),
        offset_(0),
        size_(0) {
    memset(buf_, 0, sizeof(buf_));
  }

  DirReaderFreeBSD(const DirReaderFreeBSD&) = delete;
  DirReaderFreeBSD& operator=(const DirReaderFreeBSD&) = delete;

  ~DirReaderFreeBSD() {
    if (fd_ >= 0) {
      if (IGNORE_EINTR(close(fd_)))
        RAW_LOG(ERROR, "Failed to close directory handle");
    }
  }

  bool IsValid() const {
    return fd_ >= 0;
  }

  // Move to the next entry returning false if the iteration is complete.
  bool Next() {
    if (size_) {
      struct dirent* dirent = reinterpret_cast<struct dirent*>(&buf_[offset_]);
      offset_ += dirent->d_reclen;
    }

    if (offset_ != size_)
      return true;

    ssize_t r = getdents(fd_, buf_, sizeof(buf_));
    if (r == 0)
      return false;
    if (r == -1) {
      DPLOG(FATAL) << "getdents failed";
      return false;
    }
    size_ = r;
    offset_ = 0;
    return true;
  }

  const char* name() const {
    if (!size_)
      return nullptr;

    const struct dirent* dirent =
        reinterpret_cast<const struct dirent*>(&buf_[offset_]);
    return dirent->d_name;
  }

  int fd() const {
    return fd_;
  }

  static bool IsFallback() {
    return false;
  }

 private:
  const int fd_;
  alignas(struct dirent) unsigned char buf_[512];
  size_t offset_;
  size_t size_;
};

}  // namespace base

#endif  // BASE_FILES_DIR_READER_LINUX_H_
