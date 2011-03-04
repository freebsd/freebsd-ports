# New ports collection makefile for:	gallery3
# Date created:		16 June 2009
# Whom:			Bo-Yi Wu <appleboy.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gallery3
PORTVERSION=	3.0.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/gallery/${PORTNAME}/${PORTVERSION}
DISTNAME=	gallery-${PORTVERSION}

MAINTAINER=	appleboy.tw@gmail.com
COMMENT=	Web based photo album organizer written in PHP

USE_ZIP=	yes

USE_PHP=	pcre session filter xml iconv spl simplexml json mysql \
		tokenizer
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS=	DCRAW "Enable dcraw support" off \
		FFMPEG "Enable ffmpeg support" off \
		GD "Enable gd support" off \
		GRAPHMAGICK "Enable graphicsmagick support" off \
		IMAGEMAGICK "Enable imagemagick support" on \
		JHEAD "Enable jhead support" on \
		NETPBM "Enable netpbm support" off \
		NLS "Enable National Language Support" on \
		UNZIP "Enable unzip support" on

.include <bsd.port.options.mk>

.if defined(GALLERY3DIR)
# Continue to support legacy GALLERY3DIR variable
WWWDIR=		${GALLERY3DIR}
.endif

.if defined(WITH_DCRAW)
RUN_DEPENDS+=	dcraw:${PORTSDIR}/graphics/dcraw
.endif

.if defined(WITH_FFMPEG)
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
.endif

.if defined(WITH_GD)
USE_PHP+=	gd
RUN_DEPENDS+=	pngtogd:${PORTSDIR}/graphics/gd
.endif

.if defined(WITH_GRAPHMAGICK)
RUN_DEPENDS+=	gm:${PORTSDIR}/graphics/GraphicsMagick
.endif

.if !defined(WITHOUT_IMAGEMAGICK)
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

.if !defined(WITHOUT_JHEAD)
RUN_DEPENDS+=	jhead:${PORTSDIR}/graphics/jhead
.endif

.if defined(WITH_NETPBM)
RUN_DEPENDS+=	giftopnm:${PORTSDIR}/graphics/netpbm
.endif

.if !defined(WITHOUT_NLS)
USE_PHP+=	gettext
USE_GETTEXT=	yes	# Pet portlint
.endif

.if !defined(WITHOUT_UNZIP)
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
