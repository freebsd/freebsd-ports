# Created by: Bo-Yi Wu <appleboy.tw@gmail.com>
# $FreeBSD$

PORTNAME=	gallery3
PORTVERSION=	3.0.9
CATEGORIES=	www
MASTER_SITES=	SF/gallery/${PORTNAME}/${PORTVERSION}
DISTNAME=	gallery-${PORTVERSION}

MAINTAINER=	appleboy.tw@gmail.com
COMMENT=	Web based photo album organizer written in PHP

USES=		zip

USE_PHP=	ctype filter iconv json mysql mbstring pcre \
		simplexml session spl tokenizer xml
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DCRAW FFMPEG GD GRAPHMAGICK IMAGEMAGICK JHEAD \
		NETPBM NLS UNZIP
OPTIONS_DEFAULT=	IMAGEMAGICK JHEAD UNZIP

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if defined(GALLERY3DIR)
# Continue to support legacy GALLERY3DIR variable
WWWDIR=		${GALLERY3DIR}
.endif

.if ${PORT_OPTIONS:MDCRAW}
RUN_DEPENDS+=	dcraw:${PORTSDIR}/graphics/dcraw
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	avcodec:${PORTSDIR}/multimedia/ffmpeg
.endif

.if ${PORT_OPTIONS:MGD}
USE_PHP+=	gd
RUN_DEPENDS+=	pngtogd:${PORTSDIR}/graphics/gd
.endif

.if ${PORT_OPTIONS:MGRAPHMAGICK}
RUN_DEPENDS+=	gm:${PORTSDIR}/graphics/GraphicsMagick
.endif

.if ${PORT_OPTIONS:MIMAGEMAGICK}
.if !defined(WITHOUT_X11)
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.else
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick-nox11
.endif
.endif

.if ${PORT_OPTIONS:MJHEAD}
RUN_DEPENDS+=	jhead:${PORTSDIR}/graphics/jhead
.endif

.if ${PORT_OPTIONS:MNETPBM}
RUN_DEPENDS+=	giftopnm:${PORTSDIR}/graphics/netpbm
.endif

.if ${PORT_OPTIONS:MNLS}
USE_PHP+=	gettext
USES+=		gettext
.endif

.if ${PORT_OPTIONS:MUNZIP}
RUN_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
.endif

do-install:
	@cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${WWWDIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}

.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
