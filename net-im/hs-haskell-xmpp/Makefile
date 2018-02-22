# $FreeBSD$

PORTNAME=	haskell-xmpp
PORTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	net-im haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Haskell XMPP library based on HaXml & STM

LICENSE=	BSD3CLAUSE

USE_CABAL=	HaXml>=1.23.3 html mtl>=1.0 network \
		polyparse random regex-compat stm utf8-string

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
