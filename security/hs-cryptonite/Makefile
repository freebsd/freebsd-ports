# $FreeBSD$

PORTNAME=	cryptonite
PORTVERSION=	0.24
PORTREVISION=	4
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Cryptography Primitives sink

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	memory>=0.2

FLAGS_ENABLE=	support_aesni support_rdrand integer-gmp support_deepseq
FLAGS_DISABLE=	support_pclmuldq

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
