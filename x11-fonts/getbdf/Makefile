# New ports collection makefile for:    getbdf
# Date created:         30 August 1996
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	getbdf
PORTVERSION=	1.0
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://ftp.ipa.fhg.de/pub/X/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ache@FreeBSD.org

USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes
ALL_TARGET=	getbdf

do-install:
	cd ${WRKSRC}; \
	${INSTALL} -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} getbdf ${PREFIX}/bin

.include <bsd.port.mk>
