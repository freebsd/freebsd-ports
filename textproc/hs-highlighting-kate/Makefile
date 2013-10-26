# $FreeBSD$

PORTNAME=	highlighting-kate
PORTVERSION=	0.5.3.9
PORTREVISION=	1
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Syntax highlighting

LICENSE=	GPLv2

USE_CABAL=	blaze-html>=0.4.2 mtl parsec regex-pcre-builtin

OPTIONS_DEFINE=		EXECUTABLE

EXECUTABLE_DESC=	Build the Highlight executable

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"

.if ${PORT_OPTIONS:MEXECUTABLE}
CONFIGURE_ARGS+=	--flags="executable"
EXECUTABLE+=		Highlight
.else
CONFIGURE_ARGS+=	--flags="-executable"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
