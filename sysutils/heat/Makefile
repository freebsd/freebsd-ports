# New ports collection makefile for:   heat
# Date created:        28 March 2000
# Whom:                Jeremy Chadwick <yoshi@parodius.com>
#
# $FreeBSD$

PORTNAME=	heat
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.parodius.com/pub/heat/

MAINTAINER=	yoshi@parodius.com

BIN1=		heat

do-install:
.for i in ${BIN1}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin/${i}
.endfor

.include <bsd.port.mk>
