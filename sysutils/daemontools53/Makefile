# New ports collection makefile for:	daemontools
# Date created:		09 June 1998
# Whom:			Dom Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	daemontools
PORTVERSION=	0.53
CATEGORIES=	sysutils
MASTER_SITES=	http://cr.yp.to/daemontools/ \
		ftp://cr.yp.to/daemontools/

MAINTAINER=	dom@happygiraffe.net
COMMENT=	Service monitoring and logging utilities by djb

NO_PACKAGE=	"Unsure of djb\'s license"
NO_LATEST_LINK=	yes

ALL_TARGET=	it man
INSTALL_TARGET=	setup

SCRIPTS_ENV=	BINOWN="${BINOWN}" BINGRP="${BINGRP}" BINMODE="${BINMODE}" \
		MANMODE="${MANMODE}" CFLAGS="${CFLAGS}"

MAN1=		accustamp.1 cyclog.1 errorsto.1 fifo.1 setuser.1 supervise.1 \
		svc.1 svstat.1 tailocal.1 testfilelock.1 usually.1

.include <bsd.port.mk>
