// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "sandbox/policy/freebsd/sandbox_freebsd.h"

#include <string>

#include "base/logging.h"
#include "base/memory/singleton.h"
#include "sandbox/policy/switches.h"

namespace sandbox {
namespace policy {

SandboxFreeBSD::SandboxFreeBSD()
    : initialize_sandbox_ran_(false) {
}

SandboxFreeBSD::~SandboxFreeBSD() {
}

// static
SandboxFreeBSD* SandboxFreeBSD::GetInstance() {
  SandboxFreeBSD* instance = base::Singleton<SandboxFreeBSD>::get();
  CHECK(instance);
  return instance;
}

// static
std::string SandboxFreeBSD::GetSandboxTypeInEnglish(SandboxType sandbox_type) {
  switch (sandbox_type) {
    case SandboxType::kNoSandbox:
      return "Unsandboxed";
    case SandboxType::kRenderer:
      return "Renderer";
    case SandboxType::kUtility:
      return "Utility";
    case SandboxType::kGpu:
      return "GPU";
    case SandboxType::kPpapi:
      return "PPAPI";
    case SandboxType::kNetwork:
      return "Network";
    case SandboxType::kCdm:
      return "CDM";
    case SandboxType::kPrintCompositor:
      return "Print Compositor";
    case SandboxType::kAudio:
      return "Audio";
    case SandboxType::kSpeechRecognition:
      return "Speech Recognition";
    case SandboxType::kService:
      return "Service";
    case SandboxType::kVideoCapture:
      return "Video Capture";
    default:
      return "Unknown";
  }
}

bool SandboxFreeBSD::InitializeSandbox(SandboxType sandbox_type) {
  DCHECK(!initialize_sandbox_ran_);
  initialize_sandbox_ran_ = true;

  base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();

  if (command_line->HasSwitch(switches::kNoSandbox))
    return true;

  const std::string process_type = command_line->GetSwitchValueASCII(switches::kProcessType);

  VLOG(1) << "SandboxFreeBSD::InitializeSandbox: process_type="
          << process_type << " sandbox_type=" << GetSandboxTypeInEnglish(sandbox_type);

  return true;
}

bool SandboxFreeBSD::IsSandboxed() {
  return false;
}

} // namespace policy
} // namespace sandbox
