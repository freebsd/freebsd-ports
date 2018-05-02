# Created by: Bo-Yi Wu <appleboy.tw@gmail.com>
# $FreeBSD$

PORTNAME=	gallery3
PORTVERSION=	3.0.9
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	SF/gallery/${PORTNAME}/${PORTVERSION}
DISTNAME=	gallery-${PORTVERSION}

MAINTAINER=	appleboy.tw@gmail.com
COMMENT=	Web based photo album organizer written in PHP

IGNORE_WITH_PHP=	70 71 72

USES=		zip php:web

USE_PHP=	ctype filter iconv json mysql mbstring pcre \
		simplexml session spl tokenizer xml

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DCRAW FFMPEG GD GRAPHMAGICK IMAGEMAGICK JHEAD \
		NETPBM NLS X11
OPTIONS_DEFAULT=	IMAGEMAGICK JHEAD

.include <bsd.port.options.mk>

.if defined(GALLERY3DIR)
# Continue to support legacy GALLERY3DIR variable
WWWDIR=		${GALLERY3DIR}
.endif

.if ${PORT_OPTIONS:MDCRAW}
RUN_DEPENDS+=	dcraw:graphics/dcraw
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	libavcodec.so:multimedia/ffmpeg
.endif

.if ${PORT_OPTIONS:MGD}
USE_PHP+=	gd
RUN_DEPENDS+=	pngtogd:graphics/gd
.endif

.if ${PORT_OPTIONS:MGRAPHMAGICK}
RUN_DEPENDS+=	gm:graphics/GraphicsMagick
.endif

.if ${PORT_OPTIONS:MIMAGEMAGICK}
.if ${PORT_OPTIONS:MX11}
RUN_DEPENDS+=	convert:graphics/ImageMagick
.else
RUN_DEPENDS+=	convert:graphics/ImageMagick-nox11
.endif
.endif

.if ${PORT_OPTIONS:MJHEAD}
RUN_DEPENDS+=	jhead:graphics/jhead
.endif

.if ${PORT_OPTIONS:MNETPBM}
RUN_DEPENDS+=	giftopnm:graphics/netpbm
.endif

.if ${PORT_OPTIONS:MNLS}
USE_PHP+=	gettext
USES+=		gettext
.endif

do-install:
	@cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
