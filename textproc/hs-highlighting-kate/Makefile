# New ports collection makefile for:	highlighting-kate
# Date created:				December 16, 2008
# Whom:					Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	highlighting-kate
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Syntax highlighting

LICENSE=	GPLv2

USE_CABAL=	blaze-html>=0.4.2 mtl parsec regex-pcre-builtin

OPTIONS_DEFINE=		EXECUTABLE

EXECUTABLE_DESC=	Build the Highlight executable

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXECUTABLE}
CONFIGURE_ARGS+=	--flags="executable"
EXECUTABLE+=		Highlight
.else
CONFIGURE_ARGS+=	--flags="-executable"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
