# $FreeBSD$

PORTNAME=	http2
PORTVERSION=	1.6.3
PORTREVISION=	5
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	HTTP/2.0 library including frames and HPACK

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	aeson aeson-pretty case-insensitive hex mwc-random psqueues \
		unordered-containers vector word8

FLAGS_DISABLE=	devel

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
