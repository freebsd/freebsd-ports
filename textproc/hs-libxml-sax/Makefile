# $FreeBSD$

PORTNAME=	libxml-sax
PORTVERSION=	0.7.5
PORTREVISION=	2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Bindings for the libXML2 SAX interface

LICENSE=	MIT

USE_CABAL=	text>=0.7 xml-types>=0.3

USES=		pkgconfig
LIB_DEPENDS=	libxml2.so:textproc/libxml2

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
