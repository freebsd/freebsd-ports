# $FreeBSD$

PORTNAME=	yesod-persistent
PORTVERSION=	1.6.0.1
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Some helpers for using Persistent from Yesod

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_CABAL=	blaze-builder conduit persistent persistent-template \
		resource-pool resourcet yesod-core

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
