# $FreeBSD$

PORTNAME=	connection
PORTVERSION=	0.2.8
PORTREVISION=	2
CATEGORIES=	net haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Simple and easy network connections API

LICENSE=	BSD3CLAUSE

USE_CABAL=	byteable data-default-class network>=2.3 socks>=0.4 \
		tls>=1.3 x509>=1.5 x509-store>=1.5 x509-system>=1.5 \
		x509-validation>=1.5

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
