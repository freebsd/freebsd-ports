--- src/helper/helper.go.orig	1979-11-29 21:00:00 UTC
+++ src/helper/helper.go
@@ -20,7 +20,6 @@ import (
	"github.com/aandrew-me/tgpt/v2/src/utils"
	http "github.com/bogdanfinn/fhttp"
	"github.com/fatih/color"
-	"golang.design/x/clipboard"

	"github.com/olekukonko/ts"

@@ -816,14 +815,6 @@ func MakeRequestAndGetData(input string, params struct

				if userInput == "y" || userInput == "" {
					ExecuteCommand(ShellName, ShellOptions, fullText)
-				} else {
-					err := clipboard.Init()
-
-					if err == nil {
-						clipboard.Write(clipboard.FmtText, []byte(fullText))
-
-						fmt.Println("Copied command to clipboard")
-					}
				}
			}
		}
