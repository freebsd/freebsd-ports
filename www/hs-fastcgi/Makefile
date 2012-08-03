# New ports collection makefile for: hs-fastcgi
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fastcgi
PORTVERSION=	3001.0.2.3
PORTREVISION=	5
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Haskell library for writing FastCGI programs

LICENSE=	BSD

USE_CABAL=	cgi>=3000
LIB_DEPENDS=	fcgi.0:${PORTSDIR}/www/fcgi

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
