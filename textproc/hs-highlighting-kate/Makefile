# New ports collection makefile for:	highlighting-kate
# Date created:				December 16, 2008
# Whom:					Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	highlighting-kate
PORTVERSION=	0.2.6.2
CATEGORIES=	textproc haskell
PKGNAMESUFFIX=	-ghc

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Haskell syntax highlighting library for 50+ languages

USE_HACKAGE=	pcre-light

OPTIONS=	EXECUTABLE "Build the Highlight executable" off

.include <bsd.port.options.mk>

.if defined(WITH_EXECUTABLE)
CONFIGURE_ARGS+=	--flags="executable"
EXECUTABLE+=		Highlighting
PLIST_SUB+=		MAYBE_EXECUTABLE=""
.else
CONFIGURE_ARGS+=	--flags="-executable"
PLIST_SUB+=		MAYBE_EXECUTABLE="@comment "
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
