# $FreeBSD$

PORTNAME=	wai
PORTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Web Application Interface

LICENSE=	BSD

USE_CABAL=	blaze-builder>=0.2.1.4 conduit>=0.5 http-types>=0.7 \
		network>=2.2.1.5 text>=0.7 transformers>=0.2.2 vault>=0.1

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
