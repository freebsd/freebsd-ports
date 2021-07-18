// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
#ifndef SANDBOX_POLICY_FREEBSD_SANDBOX_FREEBSD_H_
#define SANDBOX_POLICY_FREEBSD_SANDBOX_FREEBSD_H_

#include "base/macros.h"
#include "base/memory/singleton.h"
#include "sandbox/policy/export.h"
#include "sandbox/policy/sandbox_type.h"

namespace sandbox {
namespace policy {

// A singleton class to represent and change our sandboxing state for the
// capsicum sandbox on FreeBSD.
class SANDBOX_POLICY_EXPORT SandboxFreeBSD {
public:
  // Get our singleton instance.
  static SandboxFreeBSD* GetInstance();

  // Get a description for a sandbox type.
  static std::string GetSandboxTypeInEnglish(SandboxType sandbox_type);

  // Initializing the Capsicum sandbox.
  bool InitializeSandbox(SandboxType sandbox_type);

  // Testing whether the sandbox is enabled.
  bool IsSandboxed();

private:
  friend struct base::DefaultSingletonTraits<SandboxFreeBSD>;

  SandboxFreeBSD();
  ~SandboxFreeBSD();

  bool initialize_sandbox_ran_;  // InitializeSandbox() was called.

  DISALLOW_COPY_AND_ASSIGN(SandboxFreeBSD);
};

}  // namespace policy
}  // namespace sandbox

#endif // SANDBOX_POLICY_FREBSD_SANDBOX_FREEBSD_H_
