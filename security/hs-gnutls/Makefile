# $FreeBSD$

PORTNAME=	gnutls
PORTVERSION=	0.1.5
PORTREVISION=	1
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Bindings for GNU libgnutls

LICENSE=	GPLv3

USE_CABAL=	monads-tf>=0.1

USES=		pkgconfig
LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
