--- vendor/github.com/elastic/elastic-agent-libs/monitoring/metrics.go.orig	2026-04-16 18:36:25 UTC
+++ vendor/github.com/elastic/elastic-agent-libs/monitoring/metrics.go
@@ -296,7 +296,12 @@ func NewFunc(r *Registry, name string, f func(Mode, Vi
 	return v
 }
 
-func (f *Func) Visit(m Mode, vs Visitor) { f.f(m, vs) }
+func (f *Func) Visit(m Mode, vs Visitor) {
+	if f == nil || f.f == nil {
+		return
+	}
+	f.f(m, vs)
+}
 
 func (m makeExpvar) String() string { return m() }
 
