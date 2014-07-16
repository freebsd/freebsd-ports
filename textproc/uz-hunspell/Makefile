# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www-user.uni-bremen.de/~kmashrab/uzbek-word-list/
PKGNAMEPREFIX=	uz-
DISTNAME=	uzbek-wordlist-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Uzbek hunspell dictionaries

ALL_TARGET=	uz_UZ.dic
USES=		tar:bzip2
WRKSRC=		${WRKDIR}/${DISTNAME}/hunspell

PLIST_FILES=	%%DATADIR%%/uz_UZ.aff \
		%%DATADIR%%/uz_UZ.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/uz_UZ.aff ${WRKSRC}/uz_UZ.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
