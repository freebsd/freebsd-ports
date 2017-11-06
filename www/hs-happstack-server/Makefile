# $FreeBSD$

PORTNAME=	happstack-server
PORTVERSION=	7.4.6.4
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Web-related tools and services

LICENSE=	BSD3CLAUSE

USE_CABAL=	base64-bytestring>=1.0 blaze-html>=0.5 exceptions \
		extensible-exceptions hslogger>=1.0.2 html monad-control>=0.3 \
		mtl>=2 network>=2.6 network-uri>=2.6 parsec sendfile>=0.7.1 \
		syb system-filepath>=0.3.1 text>=0.10 threads>=0.5 \
		time-compat transformers-base>=0.4 utf8-string>=0.3.4 zlib

FLAGS_ENABLE=	network-uri template_haskell

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
