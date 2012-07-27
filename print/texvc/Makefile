# New ports collection makefile for:	texvc
# Date created:		2008-06-14
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	texvc
PORTVERSION=	20050202
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	SF/wikipedia/Support%20files/${PORTNAME}%20Linux-x86%20source%20%2B%20binary
DISTNAME=	${PORTNAME}-linux-x86-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Convert latex equations to HTML, MathML, PNG

USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes
USE_GMAKE=	yes
BUILD_WRKSRC=	${WRKSRC}/src

PLIST_FILES=	bin/texvc

OPTIONS_DEFINE=	RASTER
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
RASTER_DESC=	rasterization support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRASTER}
USE_GHOSTSCRIPT_RUN=	yes
RUN_DEPENDS+=	latex:${PORTSDIR}/print/teTeX-base \
		dvips:${PORTSDIR}/print/dvipsk-tetex \
		convert:${PORTSDIR}/graphics/ImageMagick
.endif

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/texvc ${PREFIX}/bin

.include <bsd.port.mk>
