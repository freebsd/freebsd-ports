# New ports collection makefile for:    rispell
# Version required:	N/A
# Date created:         16 Dec 1997
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=       rispell
PKGNAME=        ru-ispell-1.0
CATEGORIES=     textproc russian
MASTER_SITES=   http://www.ispras.ru/~knizhnik/ \
		ftp://ftp.kiarchive.ru/pub/unix/text/ispell/

MAINTAINER=     ache@FreeBSD.org

BUILD_DEPENDS=  ispell:${PORTSDIR}/textproc/ispell

WRKSRC=         ${WRKDIR}/russian-ispell

do-install:
	cd ${WRKSRC} && \
	${INSTALL_DATA} russian.hash russian.aff ${PREFIX}/lib

.include <bsd.port.mk>
