# New ports collection makefile for: hs-RSA
# Date created:        December 26, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	RSA
PORTVERSION=	1.2.1.0
PORTREVISION=	1
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Implementation of RSA, using the padding schemes of PKCS#1 v2.1

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	crypto-api>=0.10 crypto-pubkey-types monadcryptorandom SHA

OPTIONS_DEFINE=		MD5 BINARY
OPTIONS_DEFAULT=	MD5 BINARY

MD5_DESC=		Include support for using MD5
BINARY_DESC=		Use the binary package for serialization

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMD5}
CONFIGURE_ARGS+=	--flags="IncludeMD5"
USE_CABAL+=		pureMD5
.else
CONFIGURE_ARGS+=	--flags="-IncludeMD5"
.endif

.if ${PORT_OPTIONS:MBINARY}
CONFIGURE_ARGS+=	--flags="UseBinary"
.else
CONFIGURE_ARGS+=	--flags="-UseBinary"
.endif

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
