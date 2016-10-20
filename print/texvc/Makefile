# $FreeBSD$

PORTNAME=	texvc
PORTVERSION=	20050202
PORTREVISION=	5
CATEGORIES=	print
MASTER_SITES=	SF/wikipedia/Support%20files/${PORTNAME}%20Linux-x86%20source%20%2B%20binary
DISTNAME=	${PORTNAME}-linux-x86-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert latex equations to HTML, MathML, PNG

USES=		gmake
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
BUILD_WRKSRC=	${WRKSRC}/src

PLIST_FILES=	bin/texvc

OPTIONS_DEFINE=	RASTER
OPTIONS_DEFAULT:=	${OPTIONS_DEFINE}

RASTER_DESC=	rasterization support
RASTER_USES=	ghostscript:run
RASTER_USE=	TEX=latex,dvipsk
RASTER_RUN_DEPENDS=	convert:graphics/ImageMagick

MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/texvc ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
