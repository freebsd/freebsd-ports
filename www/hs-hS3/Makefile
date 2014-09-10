# $FreeBSD$

PORTNAME=	hS3
PORTVERSION=	0.5.8
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Interface to Amazon's Simple Storage Service (S3)

LICENSE=	BSD3CLAUSE

USE_CABAL=	Crypto>=4.1.0 dataenc HTTP>=4000.0.0 hxt>=9.0.0 \
		MissingH>=0.18.6 network random regex-compat utf8-string

EXECUTABLE=	hs3

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
