# New ports collection makefile for:	ucspi-tcp
# Version required:     0.80
# Date created:		12 June 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $Id: Makefile,v 1.3 1998/07/27 00:08:10 steve Exp $
#

DISTNAME=	ucspi-tcp-0.84
CATEGORIES=	sysutils net
MASTER_SITES=	ftp://koobera.math.uic.edu/pub/software/

MAINTAINER=     dom@myrddin.demon.co.uk

NO_PACKAGE=	Unsure of djb's license

ALL_TARGET=	it
INSTALL_TARGET=	setup

SCRIPTS_ENV=	BINOWN="${BINOWN}" BINGRP="${BINGRP}" BINMODE="${BINMODE}" \
		MANMODE="${MANMODE}" CFLAGS="${CFLAGS}"

MAN1=		tcpclient.1 tcpserver.1 tcprules.1 tcprulescheck.1 \
		fixcr.1 addcr.1 delcr.1 who@.1 date@.1 finger@.1 http@.1 \
		tcpcat.1 mconnect.1 argv0.1 recordio.1
MAN5=		tcp-environ.5

.include <bsd.port.mk>
