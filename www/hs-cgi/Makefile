# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	cgi
PORTVERSION=	3001.3.0.2
PORTEPOCH=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Library for writing CGI programs

LICENSE=	BSD3CLAUSE

USE_CABAL=	exceptions mtl>=2.2.1 multipart>=0.1.2 network>=2.6 \
		network-uri>=2.6 old-locale old-time parsec>=2.0

FLAGS_ENABLE=	network-uri
FLAGS_DISABLE=	old-mtl

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
