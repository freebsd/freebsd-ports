# New ports collection makefile for:    rispell
# Date created:         16 Dec 1997
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	ispell
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	russian textproc
MASTER_SITES=	http://www.garret.ru/~knizhnik/
DISTNAME=	rispell

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Russian (KOI8-R) dictionary for ISPELL

# Very dirty implementation, use rus-ispell port instead
NO_LATEST_LINK=	yes

BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

WRKSRC=		${WRKDIR}/russian-ispell

post-build:
	cd ${WRKSRC} && LANG=ru_RU.KOI8-R ${SORT} russian.sml > russian.dict

do-install:
	cd ${WRKSRC} && \
		${INSTALL_DATA} russian.hash russian.aff russian.dict \
		${PREFIX}/share/ispell
	${INSTALL_SCRIPT} ${FILESDIR}/rispell.sh ${PREFIX}/bin/rispell

.include <bsd.port.mk>
