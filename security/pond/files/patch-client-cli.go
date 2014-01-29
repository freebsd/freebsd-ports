--- client/cli.go.orig	2014-01-20 16:38:38.000000000 +0000
+++ client/cli.go	2014-01-24 23:57:44.000000000 +0000
@@ -105,12 +105,6 @@
 }
 
 func (c *cliClient) Start() {
-	oldState, err := terminal.MakeRaw(0)
-	if err != nil {
-		panic(err.Error())
-	}
-	defer terminal.Restore(0, oldState)
-
 	signal.Notify(make(chan os.Signal), os.Interrupt)
 
 	wrapper, interruptChan := NewTerminalWrapper(os.Stdin)
@@ -119,9 +113,6 @@
 	c.termWrapper = wrapper
 
 	c.term = terminal.NewTerminal(wrapper, "> ")
-	if width, height, err := terminal.GetSize(0); err == nil {
-		c.term.SetSize(width, height)
-	}
 
 	c.loadUI()
 
@@ -1883,7 +1874,6 @@
 		},
 		cliIdsAssigned: make(map[cliId]bool),
 	}
-	c.ui = c
 
 	c.newMeetingPlace = func() panda.MeetingPlace {
 		return &panda.HTTPMeetingPlace{
