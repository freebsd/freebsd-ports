# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	20110323
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/46599
PKGNAMEPREFIX=	xh-
DISTNAME=	xhosa_spell_checker-${PORTVERSION}-tb+fn+fx+sm
EXTRACT_SUFX=	.xpi
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Xhosa hunspell dictionaries

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dictionaries

PLIST_FILES=	%%DATADIR%%/xh.aff \
		%%DATADIR%%/xh.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/xh-ZA.aff ${STAGEDIR}${DATADIR}/xh.aff
	${INSTALL_DATA} ${WRKSRC}/xh-ZA.dic ${STAGEDIR}${DATADIR}/xh.dic

.include <bsd.port.mk>
