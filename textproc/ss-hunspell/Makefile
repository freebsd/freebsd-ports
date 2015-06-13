# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	20110323
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	MOZILLA_ADDONS/addons/46614
PKGNAMEPREFIX=	ss-
DISTNAME=	swati_spell_checker-${PORTVERSION}-tb+sm+fx+fn
EXTRACT_SUFX=	.xpi
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Swati hunspell dictionaries

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dictionaries

PLIST_FILES=	%%DATADIR%%/ss_ZA.aff \
		%%DATADIR%%/ss_ZA.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/ss-ZA.aff ${STAGEDIR}${DATADIR}/ss_ZA.aff
	${INSTALL_DATA} ${WRKSRC}/ss-ZA.dic ${STAGEDIR}${DATADIR}/ss_ZA.dic

.include <bsd.port.mk>
