PORTNAME=	hunspell
PORTVERSION=	0.18
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	MOZILLA_ADDONS/addons/10894
PKGNAMEPREFIX=	sr-
DISTNAME=	serbian_dictionary-${PORTVERSION}-fx+tb+sm
EXTRACT_SUFX=	.xpi
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Serbian hunspell dictionaries
WWW=		https://addons.mozilla.org/en-US/firefox/addon/%D1%81%D1%80%D0%BF%D1%81%D0%BA%D0%B8-%D1%80%D0%B5%D1%87%D0%BD%D0%B8%D0%BA-serbian-dictiona/

LICENSE=	GPLv2

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dictionaries

PLIST_FILES=	${DATADIR}/sh_YU.aff \
		${DATADIR}/sh_YU.dic \
		${DATADIR}/sr_YU.aff \
		${DATADIR}/sr_YU.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/sr-RS-Latn.aff ${STAGEDIR}${DATADIR}/sh_YU.aff
	${INSTALL_DATA} ${WRKSRC}/sr-RS-Latn.dic ${STAGEDIR}${DATADIR}/sh_YU.dic
	${INSTALL_DATA} ${WRKSRC}/sr-RS-Cyrl.aff ${STAGEDIR}${DATADIR}/sr_YU.aff
	${INSTALL_DATA} ${WRKSRC}/sr-RS-Cyrl.dic ${STAGEDIR}${DATADIR}/sr_YU.dic

.include <bsd.port.mk>
