# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	0.6
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc
PKGNAMEPREFIX=	ie-

MAINTAINER=	mistresssilvara@hotmail.com
COMMENT=	Interlingue Hunspell dictionaries

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	Carmina16
GH_PROJECT=	hunspell-ie

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${DATADIR}/ie.aff \
		${DATADIR}/ie.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ie.aff ${WRKSRC}/ie.dic ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
