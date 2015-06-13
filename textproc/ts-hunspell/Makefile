# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	20110323
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	MOZILLA_ADDONS/addons/46611
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

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/ts-ZA.aff ${STAGEDIR}${DATADIR}/ts_ZA.aff
	${INSTALL_DATA} ${WRKSRC}/ts-ZA.dic ${STAGEDIR}${DATADIR}/ts_ZA.dic

.include <bsd.port.mk>
