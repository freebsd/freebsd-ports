# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	20110323
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/46611
PKGNAMEPREFIX=	ts-
DISTNAME=	tsonga_spell_checker-${PORTVERSION}-tb+sm+fx+fn
EXTRACT_SUFX=	.xpi
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Tsonga hunspell dictionaries

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dictionaries

PLIST_FILES=	%%DATADIR%%/ts_ZA.aff \
		%%DATADIR%%/ts_ZA.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/ts-ZA.aff ${STAGEDIR}${DATADIR}/ts_ZA.aff
	${INSTALL_DATA} ${WRKSRC}/ts-ZA.dic ${STAGEDIR}${DATADIR}/ts_ZA.dic

.include <bsd.port.mk>
