# New ports collection makefile for:    rus-ispell
# Date created:         29.01.2001
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	rus-ispell
PORTVERSION=    0.99d9
CATEGORIES=	russian textproc
MASTER_SITES=   ftp://mch5.chem.msu.su/pub/russian/ispell/

MAINTAINER=	ache@FreeBSD.org

BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

USE_GMAKE=      yes
MAKE_ARGS=      YO=1
.if defined(RUS_ISPELL_LOCAL_DICT)
MAKE_ARGS+=     LOCAL_DICT=${RUS_ISPELL_LOCAL_DICT}
.endif

ALL_TARGET=     koi

NO_WRKSUBDIR=   yes

do-install:
	cd ${WRKSRC} && \
		${INSTALL_DATA} russian.hash russian.dict russian.aff \
		${PREFIX}/share/ispell
	${INSTALL_SCRIPT} ${FILESDIR}/ispell-ru.sh ${PREFIX}/bin/ispell-ru

.include <bsd.port.mk>
