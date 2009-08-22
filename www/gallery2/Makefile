# New ports collection makefile for:	gallery2
# Date created:		29 Aug 2005
# Whom:			Alex Varju <freebsd-ports@varju.ca>
#
# $FreeBSD$
#

PORTNAME=	gallery2
PORTVERSION=	2.3
CATEGORIES=	www
MASTER_SITES=	SF/gallery/${PORTNAME}/${PORTVERSION}
DISTNAME=	gallery-${PORTVERSION}-full
DIST_SUBDIR=	gallery2

MAINTAINER=	freebsd-ports@varju.ca
COMMENT=	Web based photo album organizer written in PHP

USE_PHP=	pcre session
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

SUB_FILES=	pkg-message

OPTIONS=	NETPBM "Enable netpbm support" off \
		IMAGEMAGICK "Enable imagemagick support" on \
		GRAPHMAGICK "Enable graphicsmagick support" off \
		PGSQL "Use PostgreSQL instead of MySQL" off \
		JHEAD "Enable jhead support" on \
		UNZIP "Enable unzip support" on \
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

.include <bsd.port.post.mk>
