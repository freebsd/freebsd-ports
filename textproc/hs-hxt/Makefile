# $FreeBSD$

PORTNAME=	hxt
PORTVERSION=	9.3.1.16
PORTREVISION=	4
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Collection of tools for processing XML with Haskell

LICENSE=	MIT

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	HUnit>=1.2 hxt-charproperties>=9.1 hxt-regex-xmlschema>=9.2 \
		hxt-unicode>=9.0.1 mtl>=2.0.1 network>=2.6 network-uri>=2.6

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
