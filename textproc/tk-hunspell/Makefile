# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	0.1.6
CATEGORIES=	textproc
MASTER_SITES=	MOZILLA_ADDONS/addons/204314
PKGNAMEPREFIX=	tk-
DISTNAME=	turkmen_spell_checker_dictionary-${PORTVERSION}-tb+fx+sm
EXTRACT_SUFX=	.xpi
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Turkmen hunspell dictionaries

LICENSE=	GPLv3

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dictionaries

PLIST_FILES=	%%DATADIR%%/tk_TM.aff \
		%%DATADIR%%/tk_TM.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/tk_TM.aff ${WRKSRC}/tk_TM.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
