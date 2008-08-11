#!%%PYTHON_CMD%%

# Copyright (c) 2008 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#

__version__ = "$FreeBSD$"

try:
	from distutils import sysconfig
	from distutils.core import setup
except:
	raise SystemExit, "Distutils problem"

try:
	from os import environ
except:
	raise SystemExit, "os import problem"

LOCALBASE = sysconfig.PREFIX
PREFIX = environ.get('PREFIX', LOCALBASE)
DATADIR = PREFIX + "/share/metalink-editor"

setup(
	name		= 'metalink_editor',
	version		= '%%VERSION%%',
	description	= 'GUI editor to create and edit metalinks.',
	author		= 'Hampus Wessman',
	url		= 'http://hampus.vox.nu/metalink/',
	packages	= ['Metalink_editor'],
	scripts		= ['metalink_editor.py'],
	data_files	= [(DATADIR, ["metalink_small.png", "metalink.png"])],
)
