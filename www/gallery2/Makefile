# New ports collection makefile for:   gallery2
# Date created:                29 Aug 2005
# Whom:                        Alex Varju <freebsd-ports@varju.ca>
#
# $FreeBSD$
#

PORTNAME=	gallery2
PORTVERSION=	2.2.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gallery
DISTNAME=	gallery-2.2.2-full
DIST_SUBDIR=	gallery2

MAINTAINER=	freebsd-ports@varju.ca
COMMENT=	Gallery is a web based photo album written using PHP

USE_PHP=	pcre session
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${DIST_SUBDIR}
NO_BUILD=	yes
CPIOARGS=	--quiet -pdum -R

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
SUB_LIST+=	WWWDIR_REL=${WWWDIR_REL}

# Note that USE_PHP must be set before bsd.port.pre.mk is included, so
# OPTIONS can't be used right now without making portlint angry
#OPTIONS=	NETPBM "Enable netpbm support" off \
#		IMAGEMAGICK "Enable imagemagick support" on \
#		GRAPHICSMAGICK "Use graphicsmagick instead of imagemagick" off \
#		PGSQL "Use PostgreSQL instead of MySQL" off \
#		JHEAD "Enable jhead support" on \
#		UNZIP "Enable unzip support" on \
#		GD "Enable gd support" off \
#		DCRAW "Enable dcraw support" off \
#		FFMPEG "Enable ffmpeg support" off

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.else
USE_PHP+=	mysql
.endif
.if defined(WITH_GD)
USE_PHP+=	gd
RUN_DEPENDS+=	pngtogd:${PORTSDIR}/graphics/gd
.endif
.if !defined(WITHOUT_NLS)
USE_PHP+=	gettext
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_NETPBM)
RUN_DEPENDS+=	giftopnm:${PORTSDIR}/graphics/netpbm
.endif

.if defined(WITH_GRAPHICSMAGICK)
RUN_DEPENDS+=	GraphicsMagick.1:${PORTSDIR}/graphics/GraphicsMagick
.elif !defined(WITHOUT_IMAGEMAGICK)
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif

.if !defined(WITHOUT_JHEAD)
RUN_DEPENDS+=	jhead:${PORTSDIR}/graphics/jhead
.endif
.if !defined(WITHOUT_UNZIP)
RUN_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
.endif
.if defined(WITH_FFMPEG)
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
.endif
.if defined(WITH_DCRAW)
RUN_DEPENDS+=	dcraw:${PORTSDIR}/graphics/dcraw
.endif

pre-everything::
.if defined(GALLERY2DIR)
WWWDIR=	${GALLERY2DIR}
.else
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define GALLERY2DIR to override default of ${WWWDIR}."
	@${ECHO_MSG} ""
.endif

do-install:
	@ ${MKDIR} -m 0755 ${WWWDIR}
	@ cd ${WRKSRC} && ${FIND} * -print | ${CPIO} ${CPIOARGS} ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@ ${CHOWN} ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
