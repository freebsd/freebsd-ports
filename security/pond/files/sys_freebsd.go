package system

import (
	"bufio"
	"bytes"
	"errors"
	"io"
	"io/ioutil"
	"os"
	"strings"
	"sync"
	"syscall"
)

func processLines(filename string, f func(line string) error) error {
	contents, err := ioutil.ReadFile(filename)
	if err != nil {
		return err
	}

	file := bufio.NewReader(bytes.NewBuffer(contents))
	for {
		line, isPrefix, err := file.ReadLine()
		if err == io.EOF {
			break
		}
		if err != nil {
			return err
		}
		if isPrefix {
			return errors.New("file contains a line that it too long to process")
		}
		if err = f(string(line)); err != nil {
			return err
		}
	}

	return nil
}

// IsSafe checks to see whether the current OS appears to be safe. Specifically
// it checks that any swap is encrypted.
func IsSafe() error {
	lineNo := 0
	err := processLines("/proc/swaps", func(line string) error {
		lineNo++
		if lineNo == 1 {
			// First line is just headings.
			return nil
		}
		fields := strings.Fields(line)
		if len(fields) < 1 {
			return nil
		}
		device := fields[0]
		if strings.Contains(device, "/mapper/") || strings.Contains(device, "/dm-") {
			// We don't have permissions to introspect the mapper
			// device, so we have to assume that it's encrypted.
			return nil
		}

		return errors.New("swapping is active on " + device + " which doesn't appear to be encrypted")
	})

	if err != nil {
		return errors.New("system: while checking /proc/swaps: " + err.Error())
	}
	return nil
}

var (
	safeTempDir     string
	safeTempDirErr  error
	safeTempDirOnce sync.Once
)

func findSafeTempDir() {
	var candidates []string

	err := processLines("/proc/mounts", func(line string) error {
		fields := strings.Fields(line)
		if len(fields) < 1 {
			return nil
		}
		path := fields[1]
		filesystem := fields[2]
		if filesystem == "tmpfs" &&
			syscall.Access(path, 7 /* rwx ok */) == nil {
			candidates = append(candidates, path)
		}

		return nil
	})

	if err == nil && len(candidates) == 0 {
		err = errors.New("no writable tmpfs directories found")
	}

	if err != nil {
		safeTempDirErr = errors.New("system: while checking /proc/mounts: " + err.Error())
		return
	}

	suggested := os.TempDir()
	preferred := []string{suggested}
	var otherOptions []string
	if dir := os.Getenv("XDG_RUNTIME_DIR"); len(dir) > 0 {
		otherOptions = append(otherOptions, dir)
	}
	otherOptions = append(otherOptions, "/tmp", "/var/tmp")
	for _, d := range otherOptions {
		if suggested != d {
			preferred = append(preferred, d)
		}
	}

	for _, d := range preferred {
		for _, candidate := range candidates {
			if candidate == d {
				safeTempDir = candidate
				return
			}
		}
	}

	safeTempDir = candidates[0]
}

// SafeTempDir returns the path of a writable directory which is mounted with
// tmpfs. As long as the swap is encrypted, then it should be safe to write
// there.
func SafeTempDir() (string, error) {
	safeTempDirOnce.Do(findSafeTempDir)
	if safeTempDirErr != nil {
		return "", safeTempDirErr
	}
	return safeTempDir, nil
}
