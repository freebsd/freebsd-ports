# $FreeBSD$

PORTNAME=	happstack-server
PORTVERSION=	7.1.7.1
PORTREVISION=	3
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Web-related tools and services

LICENSE=	BSD

USE_CABAL=	base64-bytestring blaze-html>=0.5 extensible-exceptions \
		hslogger>=1.0.2 html monad-control>=0.3 mtl>=2 network>=2.2.3 \
		parsec sendfile>=0.7.1 syb system-filepath>=0.3.1 text>=0.10 \
		threads>=0.5 time-compat transformers>=0.1.3 \
		transformers-base>=0.4 utf8-string>=0.3.4 xhtml zlib

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
