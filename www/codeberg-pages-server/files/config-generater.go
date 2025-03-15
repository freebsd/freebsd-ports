package main

import (
    "bufio"
    "fmt"
    "os"
    "regexp"
    "strings"
)

var (
    linePattern  = regexp.MustCompile(`^ *--([a-zA-Z0-9_-]+)\ value.*\[\$([A-Z0-9_]+)\]`)
    descRegexp   = regexp.MustCompile(`^.*value\s+(.*)(\(default.*\)|\[.*\]).*$`)
    defValRegexp = regexp.MustCompile(`\(default: ([^)]+)\)`)
)

func main() {
    fmt.Println("# See https://codeberg.org/Codeberg/pages-server")
    fmt.Println()

    scanner := bufio.NewScanner(os.Stdin)
    for scanner.Scan() {
        line := scanner.Text()
        matches := linePattern.FindStringSubmatch(line)
        if matches == nil {
            continue
        }

        optionName := matches[2]

        descMatches := descRegexp.FindStringSubmatch(line)
        var description string
        if len(descMatches) > 1 {
            description = descMatches[1]
        }
        description = strings.TrimRight(description, " \t")
        if strings.HasPrefix(description, "]") {
            description = strings.TrimPrefix(description, "]")
            description = strings.TrimLeft(description, " ")
        }

        defValMatches := defValRegexp.FindStringSubmatch(line)
        var defaultValue string
        if len(defValMatches) > 1 {
            defaultValue = defValMatches[1]
        }

        exportCmd := "export"
        switch optionName {
        case "FORBIDDEN_MIME_TYPES",
            "ALLOWED_CORS_DOMAINS",
            "BLACKLISTED_PATHS",
            "CONFIG_FILE",
            "PROFILING_ADDRESS",
            "ACME_EAB_KID",
            "ACME_EAB_HMAC",
            "DNS_PROVIDER":
            optionName = "#" + optionName
            exportCmd = "#" + exportCmd
        }

        if description != "" {
            fmt.Printf("# %s\n", description)
        } else {
            fmt.Println("#")
        }

        if defaultValue != "" {
            fmt.Printf("%s=%s\n", optionName, defaultValue)
            fmt.Printf("%s %s\n", exportCmd, optionName)
        } else {
            fmt.Printf("%s=\"\"\n", optionName)
            uncommented := strings.TrimPrefix(optionName, "#")
            fmt.Printf("%s %s\n", exportCmd, uncommented)
        }
        fmt.Println()
    }

    if err := scanner.Err(); err != nil {
        fmt.Fprintf(os.Stderr, "read error: %v\n", err)
        os.Exit(1)
    }
}
