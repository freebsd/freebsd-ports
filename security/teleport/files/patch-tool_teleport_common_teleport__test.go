--- tool/teleport/common/teleport_test.go.orig	2020-07-08 18:08:40 UTC
+++ tool/teleport/common/teleport_test.go
@@ -62,7 +62,7 @@ func (s *MainTestSuite) SetUpSuite(c *check.C) {
 
 	// set imprtant defaults to test-mode (non-existing files&locations)
 	defaults.ConfigFilePath = "/tmp/teleport/etc/teleport.yaml"
-	defaults.DataDir = "/tmp/teleport/var/lib/teleport"
+	defaults.DataDir = "/tmp/teleport/var/db/teleport"
 }
 
 func (s *MainTestSuite) TestDefault(c *check.C) {
@@ -72,7 +72,7 @@ func (s *MainTestSuite) TestDefault(c *check.C) {
 	})
 	c.Assert(cmd, check.Equals, "start")
 	c.Assert(conf.Hostname, check.Equals, s.hostname)
-	c.Assert(conf.DataDir, check.Equals, "/tmp/teleport/var/lib/teleport")
+	c.Assert(conf.DataDir, check.Equals, "/tmp/teleport/var/db/teleport")
 	c.Assert(conf.Auth.Enabled, check.Equals, true)
 	c.Assert(conf.SSH.Enabled, check.Equals, true)
 	c.Assert(conf.Proxy.Enabled, check.Equals, true)
