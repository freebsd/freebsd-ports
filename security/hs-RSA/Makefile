# New ports collection makefile for: hs-RSA
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	RSA
PORTVERSION=	1.0.6.2
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Implementation of RSA, using the padding schemes of PKCS#1 v2.1

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	SHA

OPTIONS=	MD5	"Include support for using MD5"			on \
		BINARY	"Use the binary package for serialization"	on

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_MD5)
CONFIGURE_ARGS+=	--flags="IncludeMD5"
USE_CABAL+=		pureMD5
.else
CONFIGURE_ARGS+=	--flags="-IncludeMD5"
.endif

.if defined(WITH_BINARY)
CONFIGURE_ARGS+=	--flags="UseBinary"
USE_CABAL+=		binary
.else
CONFIGURE_ARGS+=	--flags="-UseBinary"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
