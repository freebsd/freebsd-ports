# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	cgi
PORTVERSION=	3001.3.0.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Library for writing CGI programs

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	exceptions mtl>=2.2.1 multipart>=0.1.2 network>=2.6 \
		network-uri>=2.6 old-locale old-time

FLAGS_ENABLE=	network-uri
FLAGS_DISABLE=	old-mtl

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
