#!/bin/sh
#
# PROVIDE: instiki
# REQUIRE: DAEMON
# KEYWORD: FreeBSD
#
# Add the following line to /etc/rc.conf to enable instiki:
# instiki_enable (bool):      Set to "NO" by default
#                             Set it to "YES" to enable instiki
# instiki_flags (str):        Set to "--port %%INSTIKIPORT%% --storage %%PREFIX%%/%%INSTIKIDIR%%/storage" by default.
#                             Extra flags passed to start command
#
. %%RC_SUBR%%

name="instiki"
rcvar=`set_rcvar`

command="%%PREFIX%%/%%INSTIKIDIR%%/instiki"
command_interpreter="%%RUBY_WITHOUT_SUFFIX%%"

[ -z "$instiki_enable" ]	&& instiki_enable="NO"
[ -z "$instiki_flags" ]	&& instiki_flags="--port %%INSTIKIPORT%% --storage %%PREFIX%%/%%INSTIKIDIR%%/storage"

load_rc_config $name

sig_stop=-TERM

run_rc_command "$1"

