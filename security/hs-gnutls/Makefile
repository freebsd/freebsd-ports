# $FreeBSD$

PORTNAME=	gnutls
PORTVERSION=	0.2
PORTREVISION=	6
CATEGORIES=	security haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Bindings for GNU libgnutls

LICENSE=	GPLv3

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	monads-tf>=0.1.0

USES=		pkgconfig
LIB_DEPENDS=	libgnutls.so:security/gnutls

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
