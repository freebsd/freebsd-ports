# $FreeBSD$

PORTNAME=	clientsession
PORTVERSION=	0.9.1.2
PORTREVISION=	4
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Securely store session data in a client-side cookie

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	base64-bytestring>=0.1.1.1 cereal>=0.3 cipher-aes>=0.1.7 \
		cprng-aes>=0.2 crypto-api>=0.8 crypto-random entropy>=0.2.1 \
		setenv skein>=1.0.0 tagged>=0.1

EXECUTABLE=	clientsession-generate

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
