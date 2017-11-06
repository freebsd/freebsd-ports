--- xbmc/windowing/WinEventsFreeBSD.h.orig	2016-03-02 09:32:08 UTC
+++ xbmc/windowing/WinEventsFreeBSD.h
@@ -0,0 +1,74 @@
+/*
+ *      Copyright (C) 2005-2013 Team XBMC
+ *      http://xbmc.org
+ *
+ *  This Program is free software; you can redistribute it and/or modify
+ *  it under the terms of the GNU General Public License as published by
+ *  the Free Software Foundation; either version 2, or (at your option)
+ *  any later version.
+ *
+ *  This Program is distributed in the hope that it will be useful,
+ *  but WITHOUT ANY WARRANTY; without even the implied warranty of
+ *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
+ *  GNU General Public License for more details.
+ *
+ *  You should have received a copy of the GNU General Public License
+ *  along with XBMC; see the file COPYING.  If not, see
+ *  <http://www.gnu.org/licenses/>.
+ *
+ */
+
+#ifndef WINDOW_EVENTS_FREEBSD_H
+#define WINDOW_EVENTS_FREEBSD_H
+
+#pragma once
+#include "windowing/WinEvents.h"
+
+#include <unistd.h>
+#include <termios.h>
+#include <stdio.h>
+#include <sys/select.h>
+#include <sys/mouse.h>
+#include <fcntl.h>
+#include <unistd.h>
+
+#include <termios.h>
+#include <sys/kbio.h>
+
+#include <signal.h>
+
+class CWinEventsFreeBSD : public IWinEvents
+{
+public:
+	
+	bool MessagePump();
+	size_t GetQueueSize();
+	~CWinEventsFreeBSD();
+
+private:
+
+	int m_keyMods = 0;
+
+	int mouse_fd = -1;
+	uint8_t mouse_buttons = MOUSE_SYS_STDBUTTONS;
+	int m_mouseX = 0;
+	int m_mouseY = 0;
+
+	void init_kbd();
+	int has_kbd_event(void);
+	void process_kbd_events(void);
+	static void close_kbd();
+	static void restore_signal(int sig);
+	XBMCKey TranslateKey(unsigned short);
+	XBMCMod UpdateModifiers(XBMCKey, XBMC_EventType);
+
+	void init_mouse();
+	int has_mouse_event(void);
+	void send_mouse_event(int, int);
+	void process_mouse_events(void);
+	void close_mouse();
+
+	void Shutdown();
+};
+
+#endif
