# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	HTTP
PORTVERSION=	4000.3.11
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Library for client-side HTTP

LICENSE=	BSD3CLAUSE

USE_CABAL=	mtl>=2.0 network>=2.6 network-uri>=2.6 old-time>=1.0.0.0

FLAGS_ENABLE=	network-uri
FLAGS_DISABLE=	mtl1 warn-as-error network23 conduit10 warp-tests

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
