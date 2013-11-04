# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	0.0.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/222538
PKGNAMEPREFIX=	yi-
DISTNAME=	yiddish_spell_checker__yivo_-${PORTVERSION}-fx+tb+sm+fn
EXTRACT_SUFX=	.xpi
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Yiddish hunspell dictionaries

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dictionaries

PLIST_FILES=	%%DATADIR%%/yi.aff \
		%%DATADIR%%/yi.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/yi.aff ${WRKSRC}/yi.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
