# $FreeBSD$

PORTNAME=	texvc
PORTVERSION=	20050202
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	SF/wikipedia/Support%20files/${PORTNAME}%20Linux-x86%20source%20%2B%20binary
DISTNAME=	${PORTNAME}-linux-x86-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Convert latex equations to HTML, MathML, PNG

USES=		gmake
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
BUILD_WRKSRC=	${WRKSRC}/src

PLIST_FILES=	bin/texvc

OPTIONS_DEFINE=	RASTER
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
RASTER_DESC=	rasterization support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRASTER}
USE_GHOSTSCRIPT_RUN=	yes
USE_TEX=	latex dvipsk
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/texvc ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
