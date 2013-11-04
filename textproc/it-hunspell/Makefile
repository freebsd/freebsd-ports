# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	2.4.2007.09.01
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/linguistico/Dizionario%20italiano%20per%20OOo/${PORTVERSION:S/./_/g}/
PKGNAMEPREFIX=	it-
DISTNAME=	italiano_${PORTVERSION:S/./_/g}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Italian hunspell dictionaries

LICENSE=	GPLv3

EXTRACT_SUFX=	.zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	%%DATADIR%%/it_IT.aff \
		%%DATADIR%%/it_IT.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/it_IT.aff ${WRKSRC}/it_IT.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
