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

BUILD_DEPENDS=	aspell:textproc/aspell

ALL_TARGET=	myspell
NO_ARCH=	yes
USES=		tar:bzip2

PLIST_FILES=	%%DATADIR%%/wa.aff \
		%%DATADIR%%/wa.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/wa.aff ${WRKSRC}/wa.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
