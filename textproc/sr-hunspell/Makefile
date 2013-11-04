# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	0.18
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/10894
PKGNAMEPREFIX=	sr-
DISTNAME=	serbian_dictionary-${PORTVERSION}-fx+tb+sm
EXTRACT_SUFX=	.xpi
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Serbian hunspell dictionaries

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dictionaries

PLIST_FILES=	%%DATADIR%%/sh_YU.aff \
		%%DATADIR%%/sh_YU.dic \
		%%DATADIR%%/sr_YU.aff \
		%%DATADIR%%/sr_YU.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/sr-RS-Latn.aff ${STAGEDIR}${DATADIR}/sh_YU.aff
	${INSTALL_DATA} ${WRKSRC}/sr-RS-Latn.dic ${STAGEDIR}${DATADIR}/sh_YU.dic
	${INSTALL_DATA} ${WRKSRC}/sr-RS-Cyrl.aff ${STAGEDIR}${DATADIR}/sr_YU.aff
	${INSTALL_DATA} ${WRKSRC}/sr-RS-Cyrl.dic ${STAGEDIR}${DATADIR}/sr_YU.dic

.include <bsd.port.mk>
