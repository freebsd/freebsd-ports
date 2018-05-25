# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	mwc-random
PORTVERSION=	0.13.6.0
PORTREVISION=	2
CATEGORIES=	math haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Fast, high-quality pseudo random number generation

LICENSE=	BSD3CLAUSE

USE_CABAL=	math-functions primitive vector>=0.7

INSTALL_PORTDATA=	${INSTALL_DATA} ${WRKSRC}/README.markdown ${STAGEDIR}${DATADIR}

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
