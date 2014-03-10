# $FreeBSD$

PORTNAME=	libxml
PORTVERSION=	0.1.1
PORTREVISION=	11
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Binding to libxml2

LICENSE=	BSD

USE_CABAL=	mtl
USE_GNOME=	libxml2

CONFIGURE_ARGS+=	--extra-include-dirs="${LOCALBASE}/include/libxml2"

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
