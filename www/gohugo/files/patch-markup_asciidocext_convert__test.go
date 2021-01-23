--- markup/asciidocext/convert_test.go.orig	2021-01-23 16:44:14 UTC
+++ markup/asciidocext/convert_test.go
@@ -115,6 +115,31 @@ func TestAsciidoctorDisallowedArgs(t *testing.T) {
 	c.Assert(args, qt.DeepEquals, expected)
 }
 
+func TestAsciidoctorArbitraryExtension(t *testing.T) {
+	c := qt.New(t)
+	cfg := viper.New()
+	mconf := markup_config.Default
+	mconf.AsciidocExt.Extensions = []string{"arbitrary-extension"}
+	p, err := Provider.New(
+		converter.ProviderConfig{
+			Cfg:          cfg,
+			MarkupConfig: mconf,
+			Logger:       loggers.NewErrorLogger(),
+		},
+	)
+	c.Assert(err, qt.IsNil)
+
+	conv, err := p.New(converter.DocumentContext{})
+	c.Assert(err, qt.IsNil)
+
+	ac := conv.(*asciidocConverter)
+	c.Assert(ac, qt.Not(qt.IsNil))
+
+	args := ac.parseArgs(converter.DocumentContext{})
+	expected := []string{"-r", "arbitrary-extension", "--no-header-footer"}
+	c.Assert(args, qt.DeepEquals, expected)
+}
+
 func TestAsciidoctorDiagramArgs(t *testing.T) {
 	c := qt.New(t)
 	cfg := viper.New()
