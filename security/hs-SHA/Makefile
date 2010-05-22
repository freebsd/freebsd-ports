# New ports collection makefile for: hs-SHA
# Date created:        January 8, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SHA
PORTVERSION=	1.4.1.1
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell implementations of the SHA suite of message digest functions

CABAL_SETUP=	Setup.hs

USE_HACKAGE=	binary

OPTIONS=	TEST "Build the SHA test suite" off \
		EXE  "Build a SHA2-384 executable similar to 'md5sum'" off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_TEST)
CONFIGURE_ARGS+=	--flags="Test"
USE_HACKAGE+=		QuickCheck>=2.0.0.0
EXECUTABLE+=		test_sha
PLIST_SUB+=		MAYBE_TEST=""
.else
CONFIGURE_ARGS+=	--flags="-Test"
PLIST_SUB+=		MAYBE_TEST="@comment "
.endif

.if defined(WITH_EXE)
CONFIGURE_ARGS+=	--flags="exe"
EXECUTABLE+=		sha1 sha384
PLIST_SUB+=		MAYBE_EXE=""
.else
CONFIGURE_ARGS+=	--flags="-exe"
PLIST_SUB+=		MAYBE_EXE="@comment "
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
