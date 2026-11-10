// abseil 20250127+ removed the absl::StatusBuilder class and its header;
// sentencepiece still uses it, so provide a minimal compatibility shim.

#ifndef COMPAT_ABSL_STATUS_STATUS_BUILDER_H_
#define COMPAT_ABSL_STATUS_STATUS_BUILDER_H_

#include <sstream>
#include <string>

#include "absl/status/status.h"

namespace absl {

class StatusBuilder {
 public:
  explicit StatusBuilder(absl::StatusCode code) : code_(code) {}

  template <typename T>
  StatusBuilder& operator<<(const T& value) {
    os_ << value;
    return *this;
  }

  operator absl::Status() const {
    return absl::Status(code_, os_.str());
  }

 private:
  absl::StatusCode code_;
  std::ostringstream os_;
};

}  // namespace absl

#endif  // COMPAT_ABSL_STATUS_STATUS_BUILDER_H_
