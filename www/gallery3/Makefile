# New ports collection makefile for:	gallery3
# Date created:		16 June 2009
# Whom:			Bo-Yi Wu <appleboy.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gallery3
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/gallery/${PORTNAME}/${PORTVERSION}-beta-3
DISTNAME=	gallery-${PORTVERSION}-beta-3

MAINTAINER=	appleboy.tw@gmail.com
COMMENT=	Web based photo album organizer written in PHP

USE_ZIP=	yes

USE_PHP=	pcre session filter xml iconv spl simplexml json
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS=	NETPBM "Enable netpbm support" off \
		IMAGEMAGICK "Enable imagemagick support" on \
		GRAPHMAGICK "Enable graphicsmagick support" off \
		PGSQL "Use PostgreSQL instead of MySQL" off \
		JHEAD "Enable jhead support" on \
		GD "Enable gd support" off \
		DCRAW "Enable dcraw support" off \
		FFMPEG "Enable ffmpeg support" off \
		NLS "Enable National Language Support" on

.include <bsd.port.pre.mk>

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.else
USE_PHP+=	mysql
.endif
.if defined(WITH_GD)
USE_PHP+=	gd
RUN_DEPENDS+=	pngtogd:${PORTSDIR}/graphics/gd
.endif
.if defined(WITH_NLS)
USE_PHP+=	gettext
USE_GETTEXT=	yes	# Pet portlint
.endif

.if defined(WITH_NETPBM)
RUN_DEPENDS+=	giftopnm:${PORTSDIR}/graphics/netpbm
.endif

.if defined(WITH_GRAPHMAGICK)
RUN_DEPENDS+=	gm:${PORTSDIR}/graphics/GraphicsMagick
.endif

.if defined(WITH_IMAGEMAGICK)
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

.if defined(WITH_JHEAD)
RUN_DEPENDS+=	jhead:${PORTSDIR}/graphics/jhead
.endif

.if defined(WITH_UNZIP)
RUN_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
.endif

.if defined(WITH_FFMPEG)
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg

.endif
.if defined(WITH_DCRAW)
RUN_DEPENDS+=	dcraw:${PORTSDIR}/graphics/dcraw
.endif

.if defined(GALLERY3DIR)
# Continue to support legacy GALLERY3DIR variable
WWWDIR=	${GALLERY3DIR}
.endif

do-install:
	@cd ${WRKSRC}/&&${COPYTREE_SHARE} . ${WWWDIR}/
	@ ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}

.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
