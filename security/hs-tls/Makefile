# New ports collection makefile for: hs-tls
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	tls
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	TLS/SSL protocol native implementation (Server and Client)

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	cereal>=0.3 certificate>=1.2.0 crypto-api>=0.5 \
		cryptocipher>=0.3.0 cryptohash>=0.6 mtl

OPTIONS_DEFINE=		EXECUTABLE

EXECUTABLE_DESC=	Build the executables

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXECUTABLE}
CONFIGURE_ARGS+=	--flags="executable"
USE_CABAL+=		cmdargs cprng-aes>=0.2.3 network
EXECUTABLE+=		stunnel checkciphers retrievecertificate simpleclient
.else
CONFIGURE_ARGS+=	--flags="-executable"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
