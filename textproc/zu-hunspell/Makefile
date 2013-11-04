# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	20110323
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/46490
PKGNAMEPREFIX=	zu-
DISTNAME=	zulu_spell_checker-${PORTVERSION}-tb+fn+fx+sm
EXTRACT_SUFX=	.xpi
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Zulu hunspell dictionaries

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dictionaries

PLIST_FILES=	%%DATADIR%%/zu.aff \
		%%DATADIR%%/zu.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/zu-ZA.aff ${STAGEDIR}${DATADIR}/zu.aff
	${INSTALL_DATA} ${WRKSRC}/zu-ZA.dic ${STAGEDIR}${DATADIR}/zu.dic

.include <bsd.port.mk>
