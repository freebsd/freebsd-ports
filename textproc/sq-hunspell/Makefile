# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.shkenca.org/shkarkime/
PKGNAMEPREFIX=	sq-
DISTNAME=	myspell-sq_AL-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Albanian hunspell dictionaries

USES=		zip
NO_BUILD=	yes

PLIST_FILES=	%%DATADIR%%/sq_AL.aff \
		%%DATADIR%%/sq_AL.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/sq_AL.aff ${WRKSRC}/sq_AL.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
