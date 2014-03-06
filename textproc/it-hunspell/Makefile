# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	3.3.2012.04.03
CATEGORIES=	textproc
MASTER_SITES=	http://sourceforge.net/projects/aoo-extensions/files/1204/11/
PKGNAMEPREFIX=	it-
DISTFILES=	dict-it.oxt
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
	${INSTALL_DATA} ${WRKSRC}/dictionaries/it_IT.aff \
		${WRKSRC}/dictionaries/it_IT.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
