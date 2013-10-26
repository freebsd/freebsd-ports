# $FreeBSD$

PORTNAME=	tagstream-conduit
PORTVERSION=	0.5.4
PORTREVISION=	2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Streamlined HTML tag parser

LICENSE=	BSD

USE_CABAL=	attoparsec attoparsec-conduit>=0.5 blaze-builder \
		blaze-builder-conduit>=0.5 case-insensitive conduit>=0.5 \
		text transformers>=0.3

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
