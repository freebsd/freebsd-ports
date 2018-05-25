# Created by: Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
# $FreeBSD$

PORTNAME=	feed
PORTVERSION=	1.0.0.0
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Interfacing with RSS (v 0.9x, 2.x, 1.0) + Atom feeds

LICENSE=	BSD3CLAUSE

USE_CABAL=	base-compat old-locale>=1.0 old-time>=1 safe \
		time-locale-compat>=0.1 utf8-string xml>=1.2.6 xml-conduit \
		xml-types

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
