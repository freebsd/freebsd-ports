// Copyright 2018 The mkcert Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package main

import (
	"fmt"
	"os"
	"path/filepath"
	"strings"
)

var (
	FirefoxProfiles = []string{os.Getenv("HOME") + "/.mozilla/firefox/*"}
	NSSBrowsers = "Firefox and/or Chrome/Chromium"

	SystemTrustFilename string
	SystemTrustCommand  []string
	CertutilInstallHelp string
)

func init() {
	err := os.MkdirAll("/usr/local/etc/ssl/certs", 0755)
	fatalIfErr(err, "/usr/local/etc/ssl/certs")

	SystemTrustFilename = "/usr/local/etc/ssl/certs/%s.pem"
	SystemTrustCommand = []string{"certctl", "rehash"}
}

func (m *mkcert) systemTrustFilename() string {
	return fmt.Sprintf(SystemTrustFilename, strings.Replace(m.caUniqueName(), " ", "_", -1))
}

func (m *mkcert) installPlatform() bool {
	cert, err := os.ReadFile(filepath.Join(m.CAROOT, rootName))
	fatalIfErr(err, "failed to read root certificate")

	err = os.WriteFile(m.systemTrustFilename(), cert, 0644)
	fatalIfErr(err, "failed to write certificate")

	cmd := commandWithSudo(SystemTrustCommand...)
	out, err := cmd.CombinedOutput()
	fatalIfCmdErr(err, strings.Join(SystemTrustCommand, " "), out)

	return true
}

func (m *mkcert) uninstallPlatform() bool {
	if SystemTrustCommand == nil {
		return false
	}

	err := os.Remove(m.systemTrustFilename())
	fatalIfErr(err, "os.Remove failed on "+m.systemTrustFilename())

	// We used to install under non-unique filenames.
	legacyFilename := fmt.Sprintf(SystemTrustFilename, "mkcert-rootCA")
	if pathExists(legacyFilename) {
		err := os.Remove(legacyFilename)
		fatalIfErr(err, "os.Remove failed on "+legacyFilename)
	}

	cmd := commandWithSudo(SystemTrustCommand...)
	out, err := cmd.CombinedOutput()
	fatalIfCmdErr(err, strings.Join(SystemTrustCommand, " "), out)

	return true
}
