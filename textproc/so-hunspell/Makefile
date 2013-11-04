# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	 ${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	addons/13375
PKGNAMEPREFIX=	so-
DISTNAME=	qaamuuska_af_soomaaliga-${PORTVERSION}-tb+fx
EXTRACT_SUFX=	.xpi
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Somali hunspell dictionaries

LICENSE=	GPLv2

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/dictionaries

PLIST_FILES=	%%DATADIR%%/so_SO.aff \
		%%DATADIR%%/so_SO.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/so_SO.aff ${WRKSRC}/so_SO.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
