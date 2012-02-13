# New ports collection makefile for: hs-SHA
# Date created:        January 8, 2010
# Whom:                Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SHA
PORTVERSION=	1.5.0.0
PORTREVISION=	1
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell implementations of the SHA suite of message digest functions

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	binary

OPTIONS=	TEST "Build the SHA test suite" off \
		EXE  "Build a SHA2-384 executable similar to 'md5sum'" off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_TEST)
CONFIGURE_ARGS+=	--flags="Test"
USE_CABAL+=		QuickCheck>=2 test-framework>=0.3 test-framework-quickcheck2>=0.2
EXECUTABLE+=		test_sha
.else
CONFIGURE_ARGS+=	--flags="-Test"
.endif

.if defined(WITH_EXE)
CONFIGURE_ARGS+=	--flags="exe"
EXECUTABLE+=		sha1 sha384
.else
CONFIGURE_ARGS+=	--flags="-exe"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
