#!/bin/sh 
#
# Copyright (c) 1995, 2006 Ederson de Moura <ederbs@ederbs.org>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer
#    in this position and unchanged.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. The name of the author may not be used to endorse or promote products
#    derived from this software without specific prior written permission
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#

# PROVIDE: upsdaemon
# REQUIRE: DAEMON
# KEYWORD: shutdown
#
# Add the following to /etc/rc.conf to enable this service
#
# upsdaemon_enable="YES"

. /etc/rc.subr

name=upsdaemon
rcvar=`set_rcvar`

command=/usr/local/sbin/upsdaemon

upsdaemon=${upsdaemon:-"/usr/local/libexec/upsdaemon/upsdaemon-alerts"}

required_files="${upsdaemon}"

pidfile=/var/run/upsdaemon.pid

upsdaemon_enable=${upsdaemon_enable:-"NO"}
start_precmd="${upsdaemon_start_precmd}"

load_rc_config $name
run_rc_command "$1"
