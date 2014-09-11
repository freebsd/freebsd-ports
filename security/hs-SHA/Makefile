# $FreeBSD$

PORTNAME=	SHA
PORTVERSION=	1.6.4.1
PORTREVISION=	1
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Implementations of the SHA suite of message digest functions

LICENSE=	BSD3CLAUSE

FLAGS_DEFINE=		EXE

EXE_DESC=		Build a SHA2-384 executable similar to 'md5sum'
EXE_FLAG_ENABLE=	exe
EXE_FLAG_EXECUTABLE=	sha1 sha384

FLAGS_DISABLE=		Test

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
