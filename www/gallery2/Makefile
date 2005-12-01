# New ports collection makefile for:   gallery2
# Date created:                29 Aug 2005
# Whom:                        Alex Varju <freebsd-ports@varju.ca>
#
# $FreeBSD$
#

PORTNAME=	gallery2
PORTVERSION=	2.0.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gallery
DISTNAME=	gallery-2.0.2-full
DIST_SUBDIR=	gallery2

MAINTAINER=	freebsd-ports@varju.ca
COMMENT=	Gallery is a web based photo album written using PHP

USE_PHP=	pcre session mysql
WANT_PHP_WEB=	yes

WRKSRC=		${WRKDIR}/${DIST_SUBDIR}
NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
CPIOARGS=	--quiet -pdum -R
PLIST_SUB+=	GALLERY2DIR=${GALLERY2DIR}

GALLERY2DIR?=	www/data/gallery2
WWWOWN?=	www
WWWGRP?=	www

OPTIONS=	NETPBM "Enable netpbm support" on \
		IMAGEMAGICK "Enable imagemagick support" on \
		JHEAD "Enable jhead support" on \
		UNZIP "Enable unzip support" on \
		GD "Enable gd support" off \
		DCRAW "Enable dcraw support" off \
		FFMPEG "Enable ffmpeg support" off

.include <bsd.port.pre.mk>

.if defined(WITH_NETPBM)
RUN_DEPENDS+=	giftopnm:${PORTSDIR}/graphics/netpbm
.endif
.if defined(WITH_IMAGEMAGICK)
RUN_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick
.endif
.if defined(WITH_GD)
RUN_DEPENDS+=	pngtogd:${PORTSDIR}/graphics/gd
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

pre-fetch:
.if !defined(GALLERY2DIR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define GALLERY2DIR to override default of '${GALLERY2DIR}'."
	@${ECHO_MSG} ""
.endif

post-configure:
	@ ${SED} -e 's#%%PREFIX%%#${PREFIX}#g' \
	  -e 's#%%GALLERY2DIR%%#${GALLERY2DIR}#g' pkg-message > ${PKGMESSAGE}

do-install:
	@ ${MKDIR} -m 0755 ${PREFIX}/${GALLERY2DIR}
	@ cd ${WRKSRC} && ${FIND} * -print | ${CPIO} ${CPIOARGS} ${WWWOWN}:${WWWGRP} ${PREFIX}/${GALLERY2DIR}
	@ ${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${GALLERY2DIR}

post-install:
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
