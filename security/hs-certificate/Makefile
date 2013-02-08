# $FreeBSD$

PORTNAME=	certificate
PORTVERSION=	1.3.5
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Certificates and Key Reader/Writer

LICENSE=	BSD

CABAL_SETUP=	Setup.hs

USE_CABAL=	asn1-data>=0.7.1 crypto-pubkey-types>=0.1 cryptohash mtl \
		pem>=0.1

OPTIONS_DEFINE=		EXECUTABLE
OPTIONS_DEFAULT=	

EXECUTABLE_DESC=	Build the executable

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.options.mk"

.if ${PORT_OPTIONS:MEXECUTABLE}
CONFIGURE_ARGS+=	--flags="executable"
USE_CABAL+=		cmdargs text>=0.11 cryptocipher>=0.3.0
EXECUTABLE+=		certificate
.else
CONFIGURE_ARGS+=	--flags="-executable"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
