--- xbmc/windowing/WinEventsFreeBSD.cpp.orig	2016-03-02 09:32:08 UTC
+++ xbmc/windowing/WinEventsFreeBSD.cpp
@@ -0,0 +1,528 @@
+/* 
+ * Portions copied from:
+ *  xbmc/input/linux/LinuxInputDevices.cpp
+ *  https://github.com/gonzoua/quake3/blob/master/code/es/es_input.c
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
+ */
+
+#include "system.h"
+
+#ifdef HAS_FREEBSD_EVENTS
+
+#include "WinEventsFreeBSD.h"
+#include "WinEvents.h"
+#include "XBMC_events.h"
+#include "guilib/GraphicContext.h"
+#include "input/XBMC_keysym.h"
+#include "Application.h"
+#include "input/MouseStat.h"
+#include "utils/log.h"
+
+#include "es_scancodes.h"
+
+struct termios kbd_orig_tty;
+int orig_kbd_mode;
+int kbd_fd = -1;
+
+typedef struct {
+	unsigned short Key;
+	XBMCKey xbmcKey;
+} KeyMap;
+
+static const
+KeyMap keyMap[] = {
+	{ SCANCODE_ESCAPE           , XBMCK_ESCAPE      },
+	{ SCANCODE_1                , XBMCK_1           },
+	{ SCANCODE_2                , XBMCK_2           },
+	{ SCANCODE_3                , XBMCK_3           },
+	{ SCANCODE_4                , XBMCK_4           },
+	{ SCANCODE_5                , XBMCK_5           },
+	{ SCANCODE_6                , XBMCK_6           },
+	{ SCANCODE_7                , XBMCK_7           },
+	{ SCANCODE_8                , XBMCK_8           },
+	{ SCANCODE_9                , XBMCK_9           },
+	{ SCANCODE_0                , XBMCK_0           },
+	{ SCANCODE_MINUS            , XBMCK_MINUS       },
+	{ SCANCODE_EQUAL            , XBMCK_EQUALS      },
+	{ SCANCODE_BACKSPACE        , XBMCK_BACKSPACE   },
+	{ SCANCODE_TAB              , XBMCK_TAB         },
+	{ SCANCODE_Q                , XBMCK_q           },
+	{ SCANCODE_W                , XBMCK_w           },
+	{ SCANCODE_E                , XBMCK_e           },
+	{ SCANCODE_R                , XBMCK_r           },
+	{ SCANCODE_T                , XBMCK_t           },
+	{ SCANCODE_Y                , XBMCK_y           },
+	{ SCANCODE_U                , XBMCK_u           },
+	{ SCANCODE_I                , XBMCK_i           },
+	{ SCANCODE_O                , XBMCK_o           },
+	{ SCANCODE_P                , XBMCK_p           },
+	{ SCANCODE_BRACKET_LEFT     , XBMCK_LEFTBRACKET },
+	{ SCANCODE_BRACKET_RIGHT    , XBMCK_RIGHTBRACKET},
+	{ SCANCODE_ENTER            , XBMCK_RETURN      },
+	{ SCANCODE_LEFTCONTROL      , XBMCK_LCTRL       },
+	{ SCANCODE_A                , XBMCK_a           },
+	{ SCANCODE_S                , XBMCK_s           },
+	{ SCANCODE_D                , XBMCK_d           },
+	{ SCANCODE_F                , XBMCK_f           },
+	{ SCANCODE_G                , XBMCK_g           },
+	{ SCANCODE_H                , XBMCK_h           },
+	{ SCANCODE_J                , XBMCK_j           },
+	{ SCANCODE_K                , XBMCK_k           },
+	{ SCANCODE_L                , XBMCK_l           },
+	{ SCANCODE_SEMICOLON        , XBMCK_SEMICOLON   },
+	{ SCANCODE_APOSTROPHE       , XBMCK_QUOTE       },
+	{ SCANCODE_GRAVE            , XBMCK_BACKQUOTE   },
+	{ SCANCODE_LEFTSHIFT        , XBMCK_LSHIFT      },
+	{ SCANCODE_BACKSLASH        , XBMCK_BACKSLASH   },
+	{ SCANCODE_Z                , XBMCK_z           },
+	{ SCANCODE_X                , XBMCK_x           },
+	{ SCANCODE_C                , XBMCK_c           },
+	{ SCANCODE_V                , XBMCK_v           },
+	{ SCANCODE_B                , XBMCK_b           },
+	{ SCANCODE_N                , XBMCK_n           },
+	{ SCANCODE_M                , XBMCK_m           },
+	{ SCANCODE_COMMA            , XBMCK_COMMA       },
+	{ SCANCODE_PERIOD           , XBMCK_PERIOD      },
+	{ SCANCODE_SLASH            , XBMCK_SLASH       },
+	{ SCANCODE_RIGHTSHIFT       , XBMCK_RSHIFT      },
+	{ SCANCODE_KEYPADMULTIPLY   , XBMCK_KP_MULTIPLY },
+	{ SCANCODE_LEFTALT          , XBMCK_LALT        },
+	{ SCANCODE_SPACE            , XBMCK_SPACE       },
+	{ SCANCODE_CAPSLOCK         , XBMCK_CAPSLOCK    },
+	{ SCANCODE_F1               , XBMCK_F1          },
+	{ SCANCODE_F2               , XBMCK_F2          },
+	{ SCANCODE_F3               , XBMCK_F3          },
+	{ SCANCODE_F4               , XBMCK_F4          },
+	{ SCANCODE_F5               , XBMCK_F5          },
+	{ SCANCODE_F6               , XBMCK_F6          },
+	{ SCANCODE_F7               , XBMCK_F7          },
+	{ SCANCODE_F8               , XBMCK_F8          },
+	{ SCANCODE_F9               , XBMCK_F9          },
+	{ SCANCODE_F10              , XBMCK_F10         },
+	{ SCANCODE_NUMLOCK          , XBMCK_NUMLOCK     },
+	{ SCANCODE_SCROLLLOCK       , XBMCK_SCROLLOCK   },
+	{ SCANCODE_KEYPAD7          , XBMCK_KP7         },
+	{ SCANCODE_KEYPAD8          , XBMCK_KP8         },
+	{ SCANCODE_KEYPAD9          , XBMCK_KP9         },
+	{ SCANCODE_KEYPADMINUS      , XBMCK_KP_MINUS    },
+	{ SCANCODE_KEYPAD4          , XBMCK_KP4         },
+	{ SCANCODE_KEYPAD5          , XBMCK_KP5         },
+	{ SCANCODE_KEYPAD6          , XBMCK_KP6         },
+	{ SCANCODE_KEYPADPLUS       , XBMCK_KP_PLUS     },
+	{ SCANCODE_KEYPAD1          , XBMCK_KP1         },
+	{ SCANCODE_KEYPAD2          , XBMCK_KP2         },
+	{ SCANCODE_KEYPAD3          , XBMCK_KP3         },
+	{ SCANCODE_KEYPAD0          , XBMCK_KP0         },
+	{ SCANCODE_KEYPADPERIOD     , XBMCK_KP_PERIOD   },
+	{ SCANCODE_BACKSLASH        , XBMCK_BACKSLASH   },
+	{ SCANCODE_F11              , XBMCK_F11         },
+	{ SCANCODE_F12              , XBMCK_F12         },
+	{ SCANCODE_KEYPADENTER      , XBMCK_KP_ENTER    },
+	{ SCANCODE_RIGHTCONTROL     , XBMCK_RCTRL       },
+	{ SCANCODE_KEYPADDIVIDE     , XBMCK_KP_DIVIDE   },
+	{ SCANCODE_PRINTSCREEN      , XBMCK_PRINT       },
+	{ SCANCODE_RIGHTALT         , XBMCK_MODE        },
+	{ SCANCODE_HOME             , XBMCK_HOME        },
+	{ SCANCODE_CURSORBLOCKUP    , XBMCK_UP          },
+	{ SCANCODE_PAGEUP           , XBMCK_PAGEUP      },
+	{ SCANCODE_CURSORBLOCKLEFT  , XBMCK_LEFT        },
+	{ SCANCODE_CURSORBLOCKRIGHT , XBMCK_RIGHT       },
+	{ SCANCODE_END              , XBMCK_END         },
+	{ SCANCODE_CURSORBLOCKDOWN  , XBMCK_DOWN        },
+	{ SCANCODE_PAGEDOWN         , XBMCK_PAGEDOWN    },
+	{ SCANCODE_INSERT           , XBMCK_INSERT      },
+	{ SCANCODE_PRINTSCREEN      , XBMCK_PRINT       },
+	{ SCANCODE_BACKSPACE        , XBMCK_BACKSPACE   },
+};
+
+/*
+ * Translates a FreeBSD input keycode into an XBMC keycode.
+ */
+XBMCKey CWinEventsFreeBSD::TranslateKey(unsigned short code)
+{
+	for (size_t index = 0; index < sizeof(keyMap) / sizeof(KeyMap); index++) {
+		if (code == keyMap[index].Key)
+			return keyMap[index].xbmcKey;
+	}
+
+	return XBMCK_UNKNOWN;
+}
+
+XBMCMod CWinEventsFreeBSD::UpdateModifiers(XBMCKey key, XBMC_EventType xbmcKey)
+{
+	XBMCMod modifier = XBMCKMOD_NONE;
+
+	switch (key) {
+		case XBMCK_LSHIFT: modifier = XBMCKMOD_LSHIFT; break;
+		case XBMCK_RSHIFT: modifier = XBMCKMOD_RSHIFT; break;
+		case XBMCK_LCTRL: modifier = XBMCKMOD_LCTRL; break;
+		case XBMCK_RCTRL: modifier = XBMCKMOD_RCTRL; break;
+		case XBMCK_LALT: modifier = XBMCKMOD_LALT; break;
+		case XBMCK_RALT: modifier = XBMCKMOD_RALT; break;
+		case XBMCK_LMETA: modifier = XBMCKMOD_LMETA; break;
+		case XBMCK_RMETA: modifier = XBMCKMOD_RMETA; break;
+		default: break;
+	}
+
+	if (xbmcKey == XBMC_KEYDOWN) {
+		m_keyMods |= modifier;
+	} else {
+		m_keyMods &= ~modifier;
+	}
+
+	if (xbmcKey == XBMC_KEYDOWN) {
+		modifier = XBMCKMOD_NONE;
+		switch (key) {
+			case XBMCK_NUMLOCK: modifier = XBMCKMOD_NUM; break;
+			case XBMCK_CAPSLOCK: modifier = XBMCKMOD_CAPS; break;
+			default: break;
+		}
+
+		if (m_keyMods & modifier) {
+			m_keyMods &= ~modifier;
+		} else {
+			m_keyMods |= modifier;
+		}
+	}
+
+	return (XBMCMod) m_keyMods;
+}
+
+bool CWinEventsFreeBSD::MessagePump()
+{
+	bool ret = false;
+
+	if (mouse_fd < 0)
+		init_mouse();
+
+	if (kbd_fd < 0)
+		init_kbd();
+
+	while (has_kbd_event()) {
+		process_kbd_events();
+		ret = true;
+		break;
+	}
+
+	while (has_mouse_event()) {
+		process_mouse_events();
+		ret = true;
+		break;
+	}
+
+	return ret;
+}
+
+size_t CWinEventsFreeBSD::GetQueueSize()
+{
+	return 0;
+}
+
+void CWinEventsFreeBSD::init_kbd()
+{
+	struct sigaction sa = {{0}};
+	struct termios kbdtty;
+
+	kbd_fd = fileno(stdin);
+	if (kbd_fd < 0)
+		return;
+
+	if (ioctl(kbd_fd, KDGKBMODE, &orig_kbd_mode)) {
+		CLog::Log(LOGDEBUG, "ioctl(KDGKBMODE)");
+		goto out;
+	}
+
+	if (ioctl(kbd_fd, KDSKBMODE, K_CODE)) {
+		CLog::Log(LOGDEBUG, "ioctl(KDSKBMODE)");
+		goto out;
+	}
+
+	if (tcgetattr(kbd_fd, &kbdtty)) {
+		CLog::Log(LOGDEBUG, "tcgetattr");
+		goto out;
+	}
+	
+	sa.sa_handler = restore_signal;
+	sa.sa_flags   = SA_RESTART | SA_RESETHAND;
+	sigemptyset(&sa.sa_mask);
+	
+	sigaction(SIGABRT, &sa, NULL);
+	sigaction(SIGBUS,  &sa, NULL);
+	sigaction(SIGFPE,  &sa, NULL);
+	sigaction(SIGILL,  &sa, NULL);
+	sigaction(SIGQUIT, &sa, NULL);
+	sigaction(SIGSEGV, &sa, NULL);
+
+	kbd_orig_tty = kbdtty;
+
+	kbdtty.c_iflag = IGNPAR | IGNBRK;
+	/* kbdtty.c_oflag = 0; */
+	kbdtty.c_cflag = CREAD | CS8;
+	kbdtty.c_lflag = 0;
+	kbdtty.c_cc[VTIME] = 0;
+	kbdtty.c_cc[VMIN] = 1;
+	cfsetispeed(&kbdtty, 9600);
+	cfsetospeed(&kbdtty, 9600);
+	if (tcsetattr(kbd_fd, TCSANOW, &kbdtty) < 0) {
+		CLog::Log(LOGDEBUG, "tcsetattr");
+	}
+	return;
+
+out:
+	kbd_fd = -1;
+}
+
+void CWinEventsFreeBSD::restore_signal(int sig)
+{
+	close_kbd();
+	kill(getpid(), sig);
+}
+
+void CWinEventsFreeBSD::close_kbd()
+{
+	if (kbd_fd < 0)
+		return;
+
+	if (tcsetattr(kbd_fd, TCSANOW, &kbd_orig_tty) < 0)
+		CLog::Log(LOGDEBUG, "tcsetattr");
+
+	if (ioctl(kbd_fd, KDSKBMODE, orig_kbd_mode))
+		CLog::Log(LOGDEBUG, "ioctl(KDSKBMODE)");
+
+	kbd_fd = -1;
+}
+
+int CWinEventsFreeBSD::has_kbd_event(void)
+{
+	struct timeval tv;
+	fd_set fds;
+
+	if (kbd_fd < 0)
+		return(0);
+
+	tv.tv_sec = 0;
+	tv.tv_usec = 0;
+
+	FD_ZERO(&fds);
+	FD_SET(kbd_fd, &fds);
+
+	select(FD_SETSIZE, &fds, NULL, NULL, &tv);
+
+	return FD_ISSET(kbd_fd, &fds);
+}
+
+void CWinEventsFreeBSD::process_kbd_events(void)
+{
+	uint8_t code[4];
+	int bytes;
+	XBMCKey key;
+
+	if (kbd_fd < 0)
+		return;
+
+	bytes = read(kbd_fd, code, sizeof(code));
+	for (int i = 0; i < bytes; i++) {
+		key = TranslateKey(code[i] & 0x7f);
+		if (code[i] & 0x80) {
+			XBMC_Event newEvent;
+			newEvent.type = XBMC_KEYUP;
+			newEvent.key.keysym.scancode = code[i];
+			newEvent.key.keysym.unicode = 0;
+			newEvent.key.keysym.sym = key;
+			newEvent.key.keysym.mod = UpdateModifiers(key, XBMC_KEYUP);
+			newEvent.key.state = XBMC_RELEASED;
+			newEvent.key.type = XBMC_KEYUP;
+			newEvent.key.which = 0;
+			g_application.OnEvent(newEvent);
+		} else {
+			XBMC_Event newEvent;
+			newEvent.type = XBMC_KEYDOWN;
+			newEvent.key.keysym.scancode = code[i];
+			newEvent.key.keysym.unicode = 0;
+			newEvent.key.keysym.sym = key;
+			newEvent.key.keysym.mod = UpdateModifiers(key, XBMC_KEYDOWN);
+			newEvent.key.state = XBMC_PRESSED;
+			newEvent.key.type = XBMC_KEYDOWN;
+			newEvent.key.which = 0;
+			g_application.OnEvent(newEvent);
+		}
+	}
+}
+
+void CWinEventsFreeBSD::init_mouse()
+{
+	mouse_fd = open("/dev/sysmouse", O_RDONLY);
+	if (mouse_fd < 0) {
+		CLog::Log(LOGDEBUG, "open /dev/sysmouse failed");
+		return;
+	}
+
+	int level = 1;
+	if (ioctl(mouse_fd, MOUSE_SETLEVEL, &level)) {
+		close(mouse_fd);
+		CLog::Log(LOGDEBUG, "ioctl MOUSE_SETLEVEL failed");
+		return;
+	}
+}
+
+int CWinEventsFreeBSD::has_mouse_event(void)
+{
+	struct timeval tv;
+	fd_set fds;
+
+	if (mouse_fd < 0)
+		return 0;
+
+	tv.tv_sec = 0;
+	tv.tv_usec = 0;
+	FD_ZERO(&fds);
+	FD_SET(mouse_fd, &fds);
+	select(mouse_fd+1, &fds, NULL, NULL, &tv);
+
+	return FD_ISSET(mouse_fd, &fds);
+}
+
+void CWinEventsFreeBSD::send_mouse_event(int button, int pressed)
+{
+	uint8_t b;
+	switch (button) {
+		case 0:
+			b = XBMC_BUTTON_RIGHT;
+			break;
+		case 1:
+			b = XBMC_BUTTON_RIGHT;
+			break;
+		case 2:
+			b = XBMC_BUTTON_LEFT; 
+			break;
+		default:
+			b = 0xff;
+	}
+
+	if (b != 0xff) {
+		if (pressed == 1) {
+			XBMC_Event newEvent;
+			newEvent.type = XBMC_MOUSEBUTTONDOWN;
+			newEvent.button.button = b;
+			newEvent.button.state = XBMC_PRESSED;
+			newEvent.button.type = XBMC_MOUSEBUTTONDOWN;
+			newEvent.button.x = m_mouseX;
+			newEvent.button.y = m_mouseY;
+			g_application.OnEvent(newEvent);
+		} else {
+			XBMC_Event newEvent;
+			newEvent.type = XBMC_MOUSEBUTTONUP;
+			newEvent.button.button = b;
+			newEvent.button.state = XBMC_RELEASED;
+			newEvent.button.type = XBMC_MOUSEBUTTONUP;
+			newEvent.button.x = m_mouseX;
+			newEvent.button.y = m_mouseY;
+			g_application.OnEvent(newEvent);
+		}
+	}
+}
+
+void CWinEventsFreeBSD::process_mouse_events(void)
+{
+	int8_t packet[MOUSE_SYS_PACKETSIZE];
+	uint8_t status, changed;
+	int16_t relx, rely;
+
+	if (mouse_fd < 0)
+		return;
+
+	if (read(mouse_fd, packet, sizeof(packet)) < sizeof(packet))
+		return;
+
+	/* handle button click */
+	status = packet[0] & MOUSE_SYS_STDBUTTONS;
+	changed = status ^ mouse_buttons;
+	if (changed) {
+		for (int i = 0; i < 3; i++)
+			if (changed & (1<<i))
+				send_mouse_event(i, ((status & (1<<i)) == 0));
+	}
+
+	/* XBMC_BUTTON_WHEELUP */
+	if (packet[5] != 0) {
+		XBMC_Event newEvent;
+		newEvent.type = XBMC_MOUSEBUTTONDOWN;
+		newEvent.button.button = XBMC_BUTTON_WHEELUP;
+		newEvent.button.state = XBMC_PRESSED;
+		newEvent.button.x = m_mouseX;
+		newEvent.button.y = m_mouseY;
+		g_application.OnEvent(newEvent);
+
+		newEvent.type = XBMC_MOUSEBUTTONUP;
+		newEvent.button.state = XBMC_RELEASED;
+		g_application.OnEvent(newEvent);
+	}
+	/* XBMC_BUTTON_WHEELDOWN */
+	if (packet[6] != 0) {
+		XBMC_Event newEvent;
+		newEvent.type = XBMC_MOUSEBUTTONDOWN;
+		newEvent.button.button = XBMC_BUTTON_WHEELDOWN;
+		newEvent.button.state = XBMC_PRESSED;
+		newEvent.button.x = m_mouseX;
+		newEvent.button.y = m_mouseY;
+		g_application.OnEvent(newEvent);
+
+		newEvent.type = XBMC_MOUSEBUTTONUP;
+		newEvent.button.state = XBMC_RELEASED;
+		g_application.OnEvent(newEvent);
+	}
+
+	mouse_buttons = status;
+
+	relx = packet[1] + packet[3];
+	rely = -(packet[2] + packet[4]);
+
+	m_mouseX += relx;
+	m_mouseY += rely;
+
+	// limit the mouse to the screen width
+	m_mouseX = std::min(g_graphicsContext.GetWidth(), m_mouseX);
+	m_mouseX = std::max(0, m_mouseX);
+
+	// limit the mouse to the screen height
+	m_mouseY = std::min(g_graphicsContext.GetHeight(), m_mouseY);
+	m_mouseY = std::max(0, m_mouseY);
+
+	XBMC_Event newEvent;
+	newEvent.type = XBMC_MOUSEMOTION;
+	newEvent.motion.type = XBMC_MOUSEMOTION;
+	newEvent.motion.xrel = relx;
+	newEvent.motion.yrel = rely;
+	newEvent.motion.x = m_mouseX;
+	newEvent.motion.y = m_mouseY;
+	newEvent.motion.state = 0;
+	newEvent.motion.which = 0;
+	g_application.OnEvent(newEvent);
+}
+
+void CWinEventsFreeBSD::close_mouse()
+{
+	close(mouse_fd);
+	mouse_fd = -1;
+}
+
+CWinEventsFreeBSD::~CWinEventsFreeBSD()
+{
+	close_kbd();
+	close_mouse();
+}
+
+#endif
