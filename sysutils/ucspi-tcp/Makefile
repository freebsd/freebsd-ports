# New ports collection makefile for:	ucspi-tcp
# Version required:     0.80
# Date created:		12 June 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $Id: Makefile,v 1.2 1998/07/26 18:33:16 obrien Exp $
#

DISTNAME=	ucspi-tcp-0.80
CATEGORIES=	sysutils net
MASTER_SITES=	ftp://koobera.math.uic.edu/pub/software/

MAINTAINER=     dom@myrddin.demon.co.uk

NO_PACKAGE=	Unsure of djb's license

ALL_TARGET=	it man
INSTALL_TARGET=	setup

SCRIPTS_ENV=	BINOWN="${BINOWN}" BINGRP="${BINGRP}" BINMODE="${BINMODE}" \
		MANMODE="${MANMODE}" CFLAGS="${CFLAGS}"

MAN1=		tcpclient.1 tcprules.1 tcpserver.1
MAN5=		tcp-environ.5

.include <bsd.port.mk>
