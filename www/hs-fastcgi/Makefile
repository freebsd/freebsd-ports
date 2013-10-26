# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	fastcgi
PORTVERSION=	3001.0.2.4
PORTREVISION=	2
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell library for writing FastCGI programs

LICENSE=	BSD

USE_CABAL=	cgi>=3000.0.0

LIB_DEPENDS=	fcgi.0:${PORTSDIR}/www/fcgi

NO_STAGE=	yes
.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
