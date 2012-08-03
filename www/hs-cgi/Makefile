# New ports collection makefile for: hs-cgi
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	cgi
PORTVERSION=	3001.1.7.4
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Haskell library for writing CGI programs

LICENSE=	BSD

CABAL_SETUP=	Setup.hs
USE_CABAL=	mtl>=1 network>=2 parsec>=2 xhtml>=3000

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
