# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	20141110
CATEGORIES=	vietnamese textproc
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Vietnamese hunspell dictionaries

LICENSE=	GPLv3

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/vi-DauCu.aff \
		%%DATADIR%%/vi-DauCu.dic \
		%%DATADIR%%/vi-DauMoi.aff \
		%%DATADIR%%/vi-DauMoi.dic

GH_ACCOUNT=	1ec5
GH_PROJECT=	${PORTNAME}-vi
GH_TAGNAME=	v2.2.0
USE_GITHUB=	yes

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/dictionaries/*.aff ${WRKSRC}/dictionaries/*.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
