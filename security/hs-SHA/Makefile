# $FreeBSD$

PORTNAME=	SHA
PORTVERSION=	1.6.4.2
PORTREVISION=	1
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Implementations of the SHA suite of message digest functions

LICENSE=	BSD3CLAUSE

FLAGS_DEFINE=		EXE

EXE_DESC=		Build executables similar to 'md5sum'
EXE_FLAG_ENABLE=	exe
EXE_FLAG_EXECUTABLE=	sha512 sha384 sha256 sha224 sha1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
