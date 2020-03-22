--- vendor/github.com/gdamore/tcell/termbox/compat.go.orig	2019-07-26 09:44:40 UTC
+++ vendor/github.com/gdamore/tcell/termbox/compat.go
@@ -1,4 +1,4 @@
-// Copyright 2016 The TCell Authors
+// Copyright 2020 The TCell Authors
 //
 // Licensed under the Apache License, Version 2.0 (the "License");
 // you may not use file except in compliance with the License.
@@ -12,7 +12,7 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-// Package termbox is a compatibility layer to allow tcells to emulate
+// Package termbox is a compatibility layer to allow tcell to emulate
 // the github.com/nsf/termbox package.
 package termbox
 
@@ -236,63 +236,83 @@ const (
 
 // Keys codes.
 const (
-	KeyF1         = Key(tcell.KeyF1)
-	KeyF2         = Key(tcell.KeyF2)
-	KeyF3         = Key(tcell.KeyF3)
-	KeyF4         = Key(tcell.KeyF4)
-	KeyF5         = Key(tcell.KeyF5)
-	KeyF6         = Key(tcell.KeyF6)
-	KeyF7         = Key(tcell.KeyF7)
-	KeyF8         = Key(tcell.KeyF8)
-	KeyF9         = Key(tcell.KeyF9)
-	KeyF10        = Key(tcell.KeyF10)
-	KeyF11        = Key(tcell.KeyF11)
-	KeyF12        = Key(tcell.KeyF12)
-	KeyInsert     = Key(tcell.KeyInsert)
-	KeyDelete     = Key(tcell.KeyDelete)
-	KeyHome       = Key(tcell.KeyHome)
-	KeyEnd        = Key(tcell.KeyEnd)
-	KeyArrowUp    = Key(tcell.KeyUp)
-	KeyArrowDown  = Key(tcell.KeyDown)
-	KeyArrowRight = Key(tcell.KeyRight)
-	KeyArrowLeft  = Key(tcell.KeyLeft)
-	KeyCtrlA      = Key(tcell.KeyCtrlA)
-	KeyCtrlB      = Key(tcell.KeyCtrlB)
-	KeyCtrlC      = Key(tcell.KeyCtrlC)
-	KeyCtrlD      = Key(tcell.KeyCtrlD)
-	KeyCtrlE      = Key(tcell.KeyCtrlE)
-	KeyCtrlF      = Key(tcell.KeyCtrlF)
-	KeyCtrlG      = Key(tcell.KeyCtrlG)
-	KeyCtrlH      = Key(tcell.KeyCtrlH)
-	KeyCtrlI      = Key(tcell.KeyCtrlI)
-	KeyCtrlJ      = Key(tcell.KeyCtrlJ)
-	KeyCtrlK      = Key(tcell.KeyCtrlK)
-	KeyCtrlL      = Key(tcell.KeyCtrlL)
-	KeyCtrlM      = Key(tcell.KeyCtrlM)
-	KeyCtrlN      = Key(tcell.KeyCtrlN)
-	KeyCtrlO      = Key(tcell.KeyCtrlO)
-	KeyCtrlP      = Key(tcell.KeyCtrlP)
-	KeyCtrlQ      = Key(tcell.KeyCtrlQ)
-	KeyCtrlR      = Key(tcell.KeyCtrlR)
-	KeyCtrlS      = Key(tcell.KeyCtrlS)
-	KeyCtrlT      = Key(tcell.KeyCtrlT)
-	KeyCtrlU      = Key(tcell.KeyCtrlU)
-	KeyCtrlV      = Key(tcell.KeyCtrlV)
-	KeyCtrlW      = Key(tcell.KeyCtrlW)
-	KeyCtrlX      = Key(tcell.KeyCtrlX)
-	KeyCtrlY      = Key(tcell.KeyCtrlY)
-	KeyCtrlZ      = Key(tcell.KeyCtrlZ)
-	KeyBackspace  = Key(tcell.KeyBackspace)
-	KeyBackspace2 = Key(tcell.KeyBackspace2)
-	KeyTab        = Key(tcell.KeyTab)
-	KeyEnter      = Key(tcell.KeyEnter)
-	KeyEsc        = Key(tcell.KeyEscape)
-	KeyPgdn       = Key(tcell.KeyPgDn)
-	KeyPgup       = Key(tcell.KeyPgUp)
-	MouseLeft     = Key(tcell.KeyF63) // arbitrary assignments
-	MouseRight    = Key(tcell.KeyF62)
-	MouseMiddle   = Key(tcell.KeyF61)
-	KeySpace      = Key(tcell.Key(' '))
+	KeyF1             = Key(tcell.KeyF1)
+	KeyF2             = Key(tcell.KeyF2)
+	KeyF3             = Key(tcell.KeyF3)
+	KeyF4             = Key(tcell.KeyF4)
+	KeyF5             = Key(tcell.KeyF5)
+	KeyF6             = Key(tcell.KeyF6)
+	KeyF7             = Key(tcell.KeyF7)
+	KeyF8             = Key(tcell.KeyF8)
+	KeyF9             = Key(tcell.KeyF9)
+	KeyF10            = Key(tcell.KeyF10)
+	KeyF11            = Key(tcell.KeyF11)
+	KeyF12            = Key(tcell.KeyF12)
+	KeyInsert         = Key(tcell.KeyInsert)
+	KeyDelete         = Key(tcell.KeyDelete)
+	KeyHome           = Key(tcell.KeyHome)
+	KeyEnd            = Key(tcell.KeyEnd)
+	KeyArrowUp        = Key(tcell.KeyUp)
+	KeyArrowDown      = Key(tcell.KeyDown)
+	KeyArrowRight     = Key(tcell.KeyRight)
+	KeyArrowLeft      = Key(tcell.KeyLeft)
+	KeyCtrlA          = Key(tcell.KeyCtrlA)
+	KeyCtrlB          = Key(tcell.KeyCtrlB)
+	KeyCtrlC          = Key(tcell.KeyCtrlC)
+	KeyCtrlD          = Key(tcell.KeyCtrlD)
+	KeyCtrlE          = Key(tcell.KeyCtrlE)
+	KeyCtrlF          = Key(tcell.KeyCtrlF)
+	KeyCtrlG          = Key(tcell.KeyCtrlG)
+	KeyCtrlH          = Key(tcell.KeyCtrlH)
+	KeyCtrlI          = Key(tcell.KeyCtrlI)
+	KeyCtrlJ          = Key(tcell.KeyCtrlJ)
+	KeyCtrlK          = Key(tcell.KeyCtrlK)
+	KeyCtrlL          = Key(tcell.KeyCtrlL)
+	KeyCtrlM          = Key(tcell.KeyCtrlM)
+	KeyCtrlN          = Key(tcell.KeyCtrlN)
+	KeyCtrlO          = Key(tcell.KeyCtrlO)
+	KeyCtrlP          = Key(tcell.KeyCtrlP)
+	KeyCtrlQ          = Key(tcell.KeyCtrlQ)
+	KeyCtrlR          = Key(tcell.KeyCtrlR)
+	KeyCtrlS          = Key(tcell.KeyCtrlS)
+	KeyCtrlT          = Key(tcell.KeyCtrlT)
+	KeyCtrlU          = Key(tcell.KeyCtrlU)
+	KeyCtrlV          = Key(tcell.KeyCtrlV)
+	KeyCtrlW          = Key(tcell.KeyCtrlW)
+	KeyCtrlX          = Key(tcell.KeyCtrlX)
+	KeyCtrlY          = Key(tcell.KeyCtrlY)
+	KeyCtrlZ          = Key(tcell.KeyCtrlZ)
+	KeyCtrlUnderscore = Key(tcell.KeyCtrlUnderscore)
+	KeyBackspace      = Key(tcell.KeyBackspace)
+	KeyBackspace2     = Key(tcell.KeyBackspace2)
+	KeyTab            = Key(tcell.KeyTab)
+	KeyEnter          = Key(tcell.KeyEnter)
+	KeyEsc            = Key(tcell.KeyEscape)
+	KeyPgdn           = Key(tcell.KeyPgDn)
+	KeyPgup           = Key(tcell.KeyPgUp)
+	KeySpace          = Key(tcell.Key(' '))
+	KeyTilde          = Key(tcell.Key('~'))
+
+	// The following assignments are provided for termbox
+	// compatibility.  Their use in applications is discouraged.
+	// The mouse keys are completely not supported as tcell uses
+	// a separate mouse event instead of key strokes.
+	MouseLeft         = Key(tcell.KeyF63) // arbitrary assignments
+	MouseRight        = Key(tcell.KeyF62)
+	MouseMiddle       = Key(tcell.KeyF61)
+	MouseRelease      = Key(tcell.KeyF60)
+	MouseWheelUp      = Key(tcell.KeyF59)
+	MouseWheelDown    = Key(tcell.KeyF58)
+	KeyCtrl2          = Key(tcell.KeyNUL) // termbox defines theses
+	KeyCtrl3          = Key(tcell.KeyEscape)
+	KeyCtrl4          = Key(tcell.KeyCtrlBackslash)
+	KeyCtrl5          = Key(tcell.KeyCtrlRightSq)
+	KeyCtrl6          = Key(tcell.KeyCtrlCarat)
+	KeyCtrl7          = Key(tcell.KeyCtrlUnderscore)
+	KeyCtrlSlash      = Key(tcell.KeyCtrlUnderscore)
+	KeyCtrlRsqBracket = Key(tcell.KeyCtrlRightSq)
+	KeyCtrlBackslash  = Key(tcell.KeyCtrlBackslash)
+	KeyCtrlLsqBracket = Key(tcell.KeyCtrlLeftSq)
 )
 
 // Modifiers.
