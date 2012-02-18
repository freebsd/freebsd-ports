# New ports collection makefile for: hs-certificate
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	certificate
PORTVERSION=	1.0.1
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Certificates and Key Reader/Writer

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	asn1-data>=0.6.1 base64-bytestring crypto-pubkey-types mtl

OPTIONS=	EXECUTABLE	"Build the executable"	off

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"
.include <bsd.port.options.mk>

.if defined(WITH_EXECUTABLE)
CONFIGURE_ARGS+=	--flags="executable"
USE_CABAL+=		cmdargs text>=0.11 cryptohash cryptocipher>=0.3.0
EXECUTABLE+=		certificate
.else
CONFIGURE_ARGS+=	--flags="-executable"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
