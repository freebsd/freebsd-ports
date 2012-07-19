--- resources/__init__.py	1970-01-01 00:00:00 +0000
+++ resources/__init__.py	2012-06-30 19:23:27 +0000
@@ -0,0 +1,34 @@
+# -*- coding: utf-8 -*-
+# vim: autoindent shiftwidth=4 expandtab textwidth=80 tabstop=4 softtabstop=4
+
+###############################################################################
+# OpenLP - Open Source Lyrics Projection                                      #
+# --------------------------------------------------------------------------- #
+# Copyright (c) 2008-2012 Raoul Snyman                                        #
+# Portions copyright (c) 2008-2012 Tim Bentley, Gerald Britton, Jonathan      #
+# Corwin, Samuel Findlay, Michael Gorven, Scott Guerrieri, Matthias Hub,      #
+# Meinert Jordan, Armin Köhler, Edwin Lunando, Joshua Miller, Stevan Pettit,  #
+# Andreas Preikschat, Mattias Põldaru, Christian Richter, Philip Ridout,      #
+# Simon Scudder, Jeffrey Smith, Maikel Stuivenberg, Martin Thompson, Jon      #
+# Tibble, Dave Warnock, Frode Woldsund                                        #
+# --------------------------------------------------------------------------- #
+# This program is free software; you can redistribute it and/or modify it     #
+# under the terms of the GNU General Public License as published by the Free  #
+# Software Foundation; version 2 of the License.                              #
+#                                                                             #
+# This program is distributed in the hope that it will be useful, but WITHOUT #
+# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       #
+# FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for    #
+# more details.                                                               #
+#                                                                             #
+# You should have received a copy of the GNU General Public License along     #
+# with this program; if not, write to the Free Software Foundation, Inc., 59  #
+# Temple Place, Suite 330, Boston, MA 02111-1307 USA                          #
+###############################################################################
+"""
+**NB: DO NOT REMOTE THIS FILE!**
+
+This file converts the "resources" directory into a Python module so that
+setup.py will see it and package all the files within it. This, in particular,
+is needed by FreeBSD.
+"""
