#!/bin/sh
#
# $FreeBSD$
#

# If some IPA module requires some services, then they should
# be specified after the REQUIRE, by default REQUIRE is empty,
# since ipa itself does not require anything for running.

# PROVIDE: ipa
# REQUIRE:
# BEFORE: LOGIN

# Following line can enable ipa (see rc.subr(8) for information
# where to write it):
#
# ipa_enable (boolean)		Set to "YES" to enable ipa
#				(default is "NO")

. %%RC_SUBR%%

name=ipa
rcvar=`set_rcvar`

command="%%PREFIX%%/bin/ipa"

load_rc_config $name

ipa_enable=${ipa_enable:-"NO"}

extra_commands="reload"
run_rc_command "$1"
