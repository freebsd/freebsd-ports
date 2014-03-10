# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	20131101
CATEGORIES=	russian textproc
MASTER_SITES=	http://cdn.bitbucket.org/Shaman_Alex/russian-dictionary-hunspell/downloads/
DISTNAME=	ru_RU_UTF-8_${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Russian hunspell dictionaries

LICENSE=	LGPL3

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PROJECTHOST=	hunspell-ru

PLIST_FILES=	%%DATADIR%%/ru_RU.aff \
		%%DATADIR%%/ru_RU.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/ru_RU.aff ${WRKSRC}/ru_RU.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
