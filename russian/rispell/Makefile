# New ports collection makefile for:    rispell
# Date created:         16 Dec 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.2 1997/12/17 04:17:08 ache Exp $
#

DISTNAME=       rispell
PKGNAME=        ru-ispell-1.0
CATEGORIES=     textproc russian
MASTER_SITES=   http://www.ispras.ru/~knizhnik/ \
		ftp://ftp.kiarchive.ru/pub/unix/text/ispell/

BUILD_DEPENDS=  ispell:${PORTSDIR}/textproc/ispell

WRKSRC=         ${WRKDIR}/russian-ispell

MAINTAINER=     ache@FreeBSD.org

do-install:
	cd ${WRKSRC} && \
	${INSTALL_DATA} russian.hash russian.aff ${PREFIX}/lib

.include <bsd.port.mk>
