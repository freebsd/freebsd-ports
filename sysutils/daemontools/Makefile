# New ports collection makefile for:	daemontools
# Version required:     0.53
# Date created:		09 June 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $FreeBSD$
#

DISTNAME=	daemontools-0.53
CATEGORIES=	sysutils
MASTER_SITES=   ftp://koobera.math.uic.edu/www/software/

MAINTAINER=	dom@myrddin.demon.co.uk

NO_PACKAGE=	Unsure of djb's license

ALL_TARGET=	it man
INSTALL_TARGET=	setup

SCRIPTS_ENV=	BINOWN="${BINOWN}" BINGRP="${BINGRP}" BINMODE="${BINMODE}" \
		MANMODE="${MANMODE}" CFLAGS="${CFLAGS}"

MAN1= accustamp.1 cyclog.1 errorsto.1 fifo.1 setuser.1 supervise.1 svc.1 \
	svstat.1 tailocal.1 testfilelock.1 usually.1

.include <bsd.port.mk>
