# $FreeBSD$

PORTNAME=	libxml-sax
PORTVERSION=	0.7.5
PORTREVISION=	7
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Bindings for the libXML2 SAX interface

LICENSE=	MIT

DEPRECATED=		Haskell libraries are getting pushed out of the ports tree. If you are using this port for development, consider switching to cabal sandboxes (old way), cabal new-build (new way), or use devel/stack. If you believe this port shouldn't be removed, contact haskell@FreeBSD.org
EXPIRATION_DATE=	2019-04-14

USE_CABAL=	xml-types>=0.3

USES=		pkgconfig
LIB_DEPENDS=	libxml2.so:textproc/libxml2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
