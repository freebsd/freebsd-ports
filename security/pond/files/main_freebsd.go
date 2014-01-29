package main

import (
	"crypto/rand"
	"encoding/binary"
	"flag"
	"fmt"
	"os"
	"path/filepath"
	"runtime"

	"code.google.com/p/go.crypto/scrypt"
)

func main() {
	stateFile := flag.String("state-file", "", "File in which to save persistent state")
	pandaScrypt := flag.Bool("panda-scrypt", false, "Run in subprocess mode to process passphrase")
	cliFlag := flag.Bool("cli", false, "If true, the CLI will be used, even if the GUI is available")
	devFlag := flag.Bool("dev", false, "Is this a development environment?")
	flag.Parse()

	if *pandaScrypt {
		var numBytes uint32
		if err := binary.Read(os.Stdin, binary.LittleEndian, &numBytes); err != nil {
			panic(err)
		}
		if numBytes > 1024*1024 {
			panic("passphrase too large")
		}
		passphrase := make([]byte, int(numBytes))
		if _, err := os.Stdin.Read(passphrase); err != nil {
			panic(err)
		}
		data, err := scrypt.Key(passphrase, nil, 1<<17, 16, 4, 32*3)
		if err != nil {
			panic(err)
		}
		os.Stdout.Write(data)
		os.Exit(0)
	}

	dev := os.Getenv("POND") == "dev" || *devFlag
	runtime.GOMAXPROCS(4)

	if len(*stateFile) == 0 && dev {
		*stateFile = "state"
	}

	if len(*stateFile) == 0 {
		home := os.Getenv("HOME")
		if len(home) == 0 {
			fmt.Fprintf(os.Stderr, "$HOME not set. Please either export $HOME or use --state-file to set the location of the state file explicitly.\n")
			os.Exit(1)
		}
		configDir := filepath.Join(home, ".config")
		os.Mkdir(configDir, 0700)
		*stateFile = filepath.Join(configDir, "pond")
	}

	if !haveGUI || *cliFlag || len(os.Getenv("PONDCLI")) > 0 {
		client := NewCLIClient(*stateFile, rand.Reader, false /* testing */, true /* autoFetch */)
		client.disableV2Ratchet = true
		client.dev = dev
		client.Start()
	} else {
		ui := NewGTKUI()
		client := NewGUIClient(*stateFile, ui, rand.Reader, false /* testing */, true /* autoFetch */)
		client.disableV2Ratchet = true
		client.dev = dev
		client.Start()
		ui.Run()
	}
}
