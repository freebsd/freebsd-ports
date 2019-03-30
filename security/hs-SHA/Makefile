# $FreeBSD$

PORTNAME=	SHA
PORTVERSION=	1.6.4.2
PORTREVISION=	5
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Implementations of the SHA suite of message digest functions

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

FLAGS_DEFINE=		EXE

EXE_DESC=		Build executables similar to 'md5sum'
EXE_FLAG_ENABLE=	exe
EXE_FLAG_EXECUTABLE=	sha512 sha384 sha256 sha224 sha1

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
