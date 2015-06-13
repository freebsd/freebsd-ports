# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	0.0.3
CATEGORIES=	textproc
MASTER_SITES=	MOZILLA_ADDONS/addons/222538
PKGNAMEPREFIX=	yi-
DISTNAME=	yiddish_spell_checker_yivo-${PORTVERSION}-sm+fn+fx+tb
EXTRACT_SUFX=	.xpi
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Yiddish hunspell dictionaries

LICENSE=	GPLv3

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dictionaries

PLIST_FILES=	%%DATADIR%%/yi.aff \
		%%DATADIR%%/yi.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/yi.aff ${WRKSRC}/yi.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
