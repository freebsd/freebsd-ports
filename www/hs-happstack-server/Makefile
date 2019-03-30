# $FreeBSD$

PORTNAME=	happstack-server
PORTVERSION=	7.5.1.1
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Web-related tools and services

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	base64-bytestring>=1.0 blaze-html>=0.5 exceptions \
		extensible-exceptions hslogger>=1.0.2 html monad-control>=0.3 \
		mtl>=2 network>=2.6 network-uri>=2.6 semigroups sendfile>=0.7.1 \
		syb system-filepath>=0.3.1 threads>=0.5 time-compat \
		transformers-base>=0.4 utf8-string>=0.3.4 zlib

FLAGS_ENABLE=	network-uri template_haskell

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
