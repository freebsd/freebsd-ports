# New ports collection makefile for: hs-clientsession
# Date created:        November 19, 2011
# Whom:                haskell@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	clientsession
PORTVERSION=	0.7.5
PORTREVISION=	1
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Securely store session data in a client-side cookie

LICENSE=	BSD

USE_CABAL=	base64-bytestring>=0.1.1.1 cereal>=0.3 cprng-aes>=0.2 \
		crypto-api>=0.8 cryptocipher>=0.2.5 entropy>=0.2.1 \
		skein>=0.1 tagged>=0.1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
