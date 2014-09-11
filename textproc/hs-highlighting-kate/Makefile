# $FreeBSD$

PORTNAME=	highlighting-kate
PORTVERSION=	0.5.8.5
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Syntax highlighting

LICENSE=	GPLv2

USE_CABAL=	blaze-html>=0.4.2 mtl parsec \
		regex-pcre-builtin>=0.94.4.8.8.35 utf8-string

FLAGS_DEFINE=			EXECUTABLE

EXECUTABLE_DESC=		Build the Highlight executable
EXECUTABLE_FLAG_ENABLE=		executable
EXECUTABLE_FLAG_EXECUTABLE=	Highlight

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
