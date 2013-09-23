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

BUILD_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell

USE_BZIP2=	yes
ALL_TARGET=	myspell

PLIST_FILES=	%%DATADIR%%/wa.aff \
		%%DATADIR%%/wa.dic
PLIST_DIRSTRY=	%%DATADIR%%

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/wa.aff ${WRKSRC}/wa.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
