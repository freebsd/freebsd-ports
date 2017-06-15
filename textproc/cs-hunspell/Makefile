# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	2.0
CATEGORIES=	textproc
MASTER_SITES=	SF/aoo-extensions/1078/0/
PKGNAMEPREFIX=	cs-
DISTNAME=	dict-cs-${PORTVERSION}
EXTRACT_SUFX=	.oxt
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Czech hunspell dictionaries

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/cs_CZ.aff \
		%%DATADIR%%/cs_CZ.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/cs_CZ.aff ${WRKSRC}/cs_CZ.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
