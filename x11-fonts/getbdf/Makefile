# New ports collection makefile for:    getbdf
# Version required:	?
# Date created:         30 August 1996
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=       getbdf
PKGNAME=        getbdf-1.0
CATEGORIES=	x11-fonts
MASTER_SITES=   ftp://ftp.ipa.fhg.de/pub/X/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=     ache@FreeBSD.org

USE_X_PREFIX=   yes
NO_WRKSUBDIR=   yes
ALL_TARGET=     getbdf

do-install:
	cd ${WRKSRC}; \
	${INSTALL} -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} getbdf ${PREFIX}/bin

.include <bsd.port.mk>
