# New ports collection makefile for:	ucspi-tcp
# Version required:     0.80
# Date created:		12 June 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $Id$
#

DISTNAME=	ucspi-tcp-0.80
CATEGORIES=	sysutils
MASTER_SITES=   ftp://koobera.math.uic.edu/www/software/

MAINTAINER=     dom@myrddin.demon.co.uk

NO_PACKAGE=	Unsure of djb's license

ALL_TARGET=	it man
INSTALL_TARGET=	setup

SCRIPTS_ENV=	BINOWN="${BINOWN}" BINGRP="${BINGRP}" BINMODE="${BINMODE}" \
		MANMODE="${MANMODE}" CFLAGS="${CFLAGS}"

MAN1=		tcpclient.1 tcprules.1 tcpserver.1
MAN5=		tcp-environ.5

.include <bsd.port.mk>
