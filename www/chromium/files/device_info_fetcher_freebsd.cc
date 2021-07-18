// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/enterprise/signals/device_info_fetcher_freebsd.h"

#if defined(USE_GIO)
#include <gio/gio.h>
#endif  // defined(USE_GIO)
#include <sys/stat.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <net/if_dl.h>

#include <string>

#include "base/environment.h"
#include "base/files/dir_reader_posix.h"
#include "base/files/file.h"
#include "base/files/file_util.h"
#include "base/nix/xdg_util.h"
#include "base/strings/string_split.h"
#include "base/strings/string_util.h"
#include "base/strings/stringprintf.h"
#include "base/system/sys_info.h"
#include "net/base/network_interfaces.h"

using SettingValue = enterprise_signals::DeviceInfo::SettingValue;

namespace enterprise_signals {

namespace {

std::string GetDeviceModel() {
  return base::SysInfo::HardwareModelName();
}

std::string GetOsVersion() {
  return base::SysInfo::OperatingSystemVersion();
}

std::string GetDeviceHostName() {
  return net::GetHostName();
}

std::string GetSerialNumber() {
  return std::string();
}

// Implements the logic from the native client setup script. It reads the
// setting value straight from gsettings but picks the schema relevant to the
// currently active desktop environment.
// The current implementation support Gnone and Cinnamon only.
SettingValue GetScreenlockSecured() {
#if defined(USE_GIO)
  static constexpr char kLockScreenKey[] = "lock-enabled";

  std::unique_ptr<base::Environment> env(base::Environment::Create());
  const base::nix::DesktopEnvironment desktop_env =
      base::nix::GetDesktopEnvironment(env.get());
  if (desktop_env != base::nix::DESKTOP_ENVIRONMENT_CINNAMON &&
      desktop_env != base::nix::DESKTOP_ENVIRONMENT_GNOME) {
    return SettingValue::UNKNOWN;
  }

  const std::string settings_schema = base::StringPrintf(
      "org.%s.desktop.screensaver",
      desktop_env == base::nix::DESKTOP_ENVIRONMENT_CINNAMON ? "cinnamon"
                                                             : "gnome");

  GSettingsSchema* screensaver_schema = g_settings_schema_source_lookup(
      g_settings_schema_source_get_default(), settings_schema.c_str(), FALSE);
  GSettings* screensaver_settings = nullptr;
  if (!screensaver_schema ||
      !g_settings_schema_has_key(screensaver_schema, kLockScreenKey)) {
    return SettingValue::UNKNOWN;
  }
  screensaver_settings = g_settings_new(settings_schema.c_str());
  if (!screensaver_settings)
    return SettingValue::UNKNOWN;
  gboolean lock_screen_enabled =
      g_settings_get_boolean(screensaver_settings, kLockScreenKey);
  g_object_unref(screensaver_settings);

  return lock_screen_enabled ? SettingValue::ENABLED : SettingValue::DISABLED;
#else
  return SettingValue::UNKNOWN;
#endif  // defined(USE_GIO)
}

// Implements the logic from the native host installation script. First find the
// root device identifier, then locate its parent and get its type.
SettingValue GetDiskEncrypted() {
  return SettingValue::UNKNOWN;
}

std::vector<std::string> GetMacAddresses() {
  std::vector<std::string> result;
  struct ifaddrs* ifa = nullptr;

  if (getifaddrs(&ifa) != 0)
    return result;

  struct ifaddrs* interface = ifa;
  for (; interface != nullptr; interface = interface->ifa_next) {
    if (interface->ifa_addr == nullptr ||
        interface->ifa_addr->sa_family != AF_LINK) {
      continue;
    }
    struct sockaddr_dl* sdl =
        reinterpret_cast<struct sockaddr_dl*>(interface->ifa_addr);
    if (!sdl || sdl->sdl_alen != 6)
      continue;
    char* link_address = static_cast<char*>(LLADDR(sdl));
    result.push_back(base::StringPrintf(
        "%02x:%02x:%02x:%02x:%02x:%02x", link_address[0] & 0xff,
        link_address[1] & 0xff, link_address[2] & 0xff, link_address[3] & 0xff,
        link_address[4] & 0xff, link_address[5] & 0xff));
  }
  return result;
}

}  // namespace

DeviceInfoFetcherFreeBSD::DeviceInfoFetcherFreeBSD() = default;

DeviceInfoFetcherFreeBSD::~DeviceInfoFetcherFreeBSD() = default;

DeviceInfo DeviceInfoFetcherFreeBSD::Fetch() {
  DeviceInfo device_info;
  device_info.os_name = "freebsd";
  device_info.os_version = GetOsVersion();
  device_info.device_host_name = GetDeviceHostName();
  device_info.device_model = GetDeviceModel();
  device_info.serial_number = GetSerialNumber();
  device_info.screen_lock_secured = GetScreenlockSecured();
  device_info.disk_encrypted = GetDiskEncrypted();
  device_info.mac_addresses = GetMacAddresses();
  return device_info;
}

}  // namespace enterprise_signals
