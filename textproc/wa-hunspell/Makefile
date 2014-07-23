# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	0.4.15
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://chanae.walon.org/walon/
PKGNAMEPREFIX=	wa-
DISTNAME=	aspell-wa-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Wallon hunspell dictionaries

LICENSE=	LGPL21

BUILD_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell

ALL_TARGET=	myspell
USES=		tar:bzip2

PLIST_FILES=	%%DATADIR%%/wa.aff \
		%%DATADIR%%/wa.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/wa.aff ${WRKSRC}/wa.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
