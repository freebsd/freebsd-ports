# New ports collection makefile for:	bmon
# Date created:			21 Feb 2003
# Whom:				Jon Nistor <nistor@snickers.org>
#
# $FreeBSD$
#

PORTNAME=	bmon
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://trash.net/~reeler/bmon/files/

MAINTAINER=	nistor@snickers.org
COMMENT=	"BMON - bandwidth monitor using curses lib"

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

MAN1=		bmon.1

do-install:
	${INSTALL} ${STRIP} ${COPY} ${_BINOWNGRP} -m 4755 ${WRKSRC}/bmon ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/bmon.1 ${PREFIX}/man/man1/bmon.1

.include <bsd.port.mk>
