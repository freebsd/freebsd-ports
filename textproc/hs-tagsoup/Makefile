# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	tagsoup
PORTVERSION=	0.13.1
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Parsing and extracting information from HTML/XML documents

LICENSE=	BSD3CLAUSE

USE_CABAL=	text

INSTALL_PORTDATA=	${INSTALL_DATA} ${WRKSRC}/tagsoup.htm ${STAGEDIR}${DATADIR}

FLAGS_DEFINE=	DOWNLOAD

DOWNLOAD_DESC=		Build with Download module
DOWNLOAD_FLAG_ENABLE=	download

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
