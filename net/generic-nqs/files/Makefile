#
#

HOSTNAME=	`uname -n`
RELEASE=	`uname -r | cut -d'-' -f 1`
HARDWARE=	`uname -m`
PLATFORM=	${HARDWARE}-unknown-freebsd${RELEASE}

all:
	@ cd Build-Tree/${PLATFORM}/${HOSTNAME}; \
	$(MAKE)

install:
	@ cd Build-Tree/${PLATFORM}/${HOSTNAME}; \
	$(MAKE) install
