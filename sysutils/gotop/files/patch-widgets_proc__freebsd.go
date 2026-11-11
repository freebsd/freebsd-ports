-- Fix non-constant format string errors in FreeBSD process widget.
-- Go 1.24 vet treats dynamic strings passed to fmt.Errorf/log.Printf as
-- format strings as a compile-time error. Use "%s" as the constant format
-- and pass the translated string as the argument.
-- Upstream issue: not yet reported.

--- widgets/proc_freebsd.go.orig	2026-11-11 18:36:52 UTC
+++ widgets/proc_freebsd.go
@@ -26,13 +26,13 @@ func getProcs() ([]Proc, error) {
 func getProcs() ([]Proc, error) {
 	output, err := exec.Command("ps", "-axo pid,comm,%cpu,%mem,args", "--libxo", "json").Output()
 	if err != nil {
-		return nil, fmt.Errorf(tr.Value("widget.proc.err.ps", err.Error()))
+		return nil, fmt.Errorf("%s", tr.Value("widget.proc.err.ps", err.Error()))
 	}
 
 	list := processList{}
 	err = json.Unmarshal(output, &list)
 	if err != nil {
-		return nil, fmt.Errorf(tr.Value("widget.proc.err.parse", err.Error()))
+		return nil, fmt.Errorf("%s", tr.Value("widget.proc.err.parse", err.Error()))
 	}
 	procs := []Proc{}
 
@@ -43,17 +43,17 @@ func getProcs() ([]Proc, error) {
 		pid, err := strconv.Atoi(strings.TrimSpace(process.Pid))
 		if err != nil {
 			sp := fmt.Sprintf("%v", process)
-			log.Printf(tr.Value("widget.proc.err.pidconv", err.Error(), sp))
+			log.Printf("%s", tr.Value("widget.proc.err.pidconv", err.Error(), sp))
 		}
 		cpu, err := strconv.ParseFloat(utils.ConvertLocalizedString(process.CPU), 32)
 		if err != nil {
 			sp := fmt.Sprintf("%v", process)
-			log.Printf(tr.Value("widget.proc.err.cpuconv", err.Error(), sp))
+			log.Printf("%s", tr.Value("widget.proc.err.cpuconv", err.Error(), sp))
 		}
 		mem, err := strconv.ParseFloat(utils.ConvertLocalizedString(process.Mem), 32)
 		if err != nil {
 			sp := fmt.Sprintf("%v", process)
-			log.Printf(tr.Value("widget.proc.err.memconv", err.Error(), sp))
+			log.Printf("%s", tr.Value("widget.proc.err.memconv", err.Error(), sp))
 		}
 		proc := Proc{
 			Pid:         pid,
