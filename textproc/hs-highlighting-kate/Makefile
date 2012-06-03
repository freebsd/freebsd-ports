# New ports collection makefile for:	highlighting-kate
# Date created:				December 16, 2008
# Whom:					Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	highlighting-kate
PORTVERSION=	0.5.1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Syntax highlighting

LICENSE=	GPLv2

USE_CABAL=	blaze-html>=0.4.2 mtl parsec regex-pcre-builtin

OPTIONS=	EXECUTABLE "Build the Highlight executable" off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_EXECUTABLE)
CONFIGURE_ARGS+=	--flags="executable"
EXECUTABLE+=		Highlight
.else
CONFIGURE_ARGS+=	--flags="-executable"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
