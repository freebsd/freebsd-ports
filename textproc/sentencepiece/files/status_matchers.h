#ifndef COMPAT_ABSL_STATUS_STATUS_MATCHERS_H_
#define COMPAT_ABSL_STATUS_STATUS_MATCHERS_H_

#include "absl/status/status_matchers.h"

// absl/status/status_matchers.h of abseil 20250127 lacks ABSL_EXPECT_OK
#define ABSL_EXPECT_OK(expr) EXPECT_TRUE((expr).ok())

#endif  // COMPAT_ABSL_STATUS_STATUS_MATCHERS_H_
