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

USE_BZIP2=	yes
ALL_TARGET=	uz_UZ.dic
WRKSRC=		${WRKDIR}/${DISTNAME}/hunspell

PLIST_FILES=	%%DATADIR%%/uz_UZ.aff \
		%%DATADIR%%/uz_UZ.dic
PLIST_DIRSTRY=	%%DATADIR%%

NO_STAGE=	yes
do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/uz_UZ.aff ${WRKSRC}/uz_UZ.dic ${DATADIR}/

.include <bsd.port.mk>
