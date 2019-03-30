# $FreeBSD$

PORTNAME=	libxml
PORTVERSION=	0.1.1
PORTREVISION=	21
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to libxml2

LICENSE=	BSD3CLAUSE

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	mtl
USE_GNOME=	libxml2

CONFIGURE_ARGS+=	--extra-include-dirs="${LOCALBASE}/include/libxml2"

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
