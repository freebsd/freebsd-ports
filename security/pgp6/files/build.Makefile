#
# build.sh expressed as a makefile
# mike@fate.com
#

all:
	cd libs/pfl ; ./configure
	cd libs/pfl ; gmake
	cd libs/pgpcdk ; ./configure
	cd libs/pgpcdk ; gmake headers
	cd libs/pgpcdk ; gmake
	cd clients/pgp/shared ; ./configure
	cd clients/pgp/shared ; gmake
	cd clients/pgp/cmdline ; ./configure
	cd clients/pgp/cmdline ; gmake

