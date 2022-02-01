// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "sandbox/policy/freebsd/sandbox_freebsd.h"

#include <string>

#include "base/logging.h"
#include "base/memory/singleton.h"
#include "sandbox/policy/switches.h"
#include "sandbox/policy/mojom/sandbox.mojom.h"

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
std::string SandboxFreeBSD::GetSandboxTypeInEnglish(sandbox::mojom::Sandbox sandbox_type) {
  switch (sandbox_type) {
    case sandbox::mojom::Sandbox::kNoSandbox:
      return "Unsandboxed";
    case sandbox::mojom::Sandbox::kRenderer:
      return "Renderer";
    case sandbox::mojom::Sandbox::kUtility:
      return "Utility";
    case sandbox::mojom::Sandbox::kGpu:
      return "GPU";
    case sandbox::mojom::Sandbox::kPpapi:
      return "PPAPI";
    case sandbox::mojom::Sandbox::kNetwork:
      return "Network";
    case sandbox::mojom::Sandbox::kCdm:
      return "CDM";
    case sandbox::mojom::Sandbox::kPrintCompositor:
      return "Print Compositor";
#if BUILDFLAG(ENABLE_PRINTING)
    case sandbox::mojom::Sandbox::kPrintBackend:
      return "Print Backend";
#endif
    case sandbox::mojom::Sandbox::kAudio:
      return "Audio";
    case sandbox::mojom::Sandbox::kSpeechRecognition:
      return "Speech Recognition";
    case sandbox::mojom::Sandbox::kService:
      return "Service";
    default:
      return "Unknown";
  }
}

bool SandboxFreeBSD::InitializeSandbox(sandbox::mojom::Sandbox sandbox_type) {
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
