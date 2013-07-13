# New ports collection makefile for:	gallery2
# Date created:		29 Aug 2005
# Whom:			Alex Varju <freebsd-ports@varju.ca>
#
# $FreeBSD$
#

PORTNAME=	gallery2
PORTVERSION=	2.3.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/gallery/${PORTNAME}/${PORTVERSION}
DISTNAME=	gallery-${PORTVERSION}-full
DIST_SUBDIR=	gallery2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Web based photo album organizer written in PHP

USE_PHP=	pcre session
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		DCRAW FFMPEG GD GRAPHMAGICK IMAGEMAGICK JHEAD \
			NETPBM NLS PGSQL UNZIP
OPTIONS_DEFAULT=	IMAGEMAGICK JHEAD UNZIP

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPGSQL}
USE_PHP+=	pgsql
.else
USE_PHP+=	mysql
.endif

.if ${PORT_OPTIONS:MGD}
USE_PHP+=	gd
RUN_DEPENDS+=	pngtogd:${PORTSDIR}/graphics/gd
.endif

.if ${PORT_OPTIONS:MNLS}
USE_PHP+=	gettext
USES+=		gettext
.endif

.if ${PORT_OPTIONS:MNETPBM}
RUN_DEPENDS+=	giftopnm:${PORTSDIR}/graphics/netpbm
.endif

.if ${PORT_OPTIONS:MGRAPHMAGICK}
RUN_DEPENDS+=	gm:${PORTSDIR}/graphics/GraphicsMagick
.endif

.if ${PORT_OPTIONS:MIMAGEMAGICK}
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

.if ${PORT_OPTIONS:MJHEAD}
RUN_DEPENDS+=	jhead:${PORTSDIR}/graphics/jhead
.endif

.if ${PORT_OPTIONS:MUNZIP}
RUN_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
.endif

.if ${PORT_OPTIONS:MDCRAW}
RUN_DEPENDS+=	dcraw:${PORTSDIR}/graphics/dcraw
.endif

.if defined(GALLERY2DIR)
# Continue to support legacy GALLERY2DIR variable
WWWDIR=	${GALLERY2DIR}
.endif

do-install:
	@cd ${WRKSRC}/&&${COPYTREE_SHARE} . ${WWWDIR}/
	@ ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}

.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
