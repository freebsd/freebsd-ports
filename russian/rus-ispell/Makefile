# New ports collection makefile for:    rus-ispell
# Date created:         29.01.2001
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=       rus-ispell
PORTVERSION=    0.99d6
CATEGORIES=	russian textproc
MASTER_SITES=   ftp://mch5.chem.msu.su/pub/russian/ispell/
DISTNAME=       rus-ispell

MAINTAINER=	ache@FreeBSD.org

BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

USE_GMAKE=      yes
MAKE_ARGS=      YO=1
ALL_TARGET=     koi

NO_WRKSUBDIR=   yes

do-install:
	cd ${WRKSRC} && \
	${INSTALL_DATA} russian.hash russian.aff ${PREFIX}/share/ispell
	${INSTALL_SCRIPT} ${FILESDIR}/ispell-ru.sh ${PREFIX}/bin/ispell-ru

.include <bsd.port.mk>
