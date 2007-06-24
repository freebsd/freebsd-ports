# New ports collection makefile for:   gallery2
# Date created:                29 Aug 2005
# Whom:                        Alex Varju <freebsd-ports@varju.ca>
#
# $FreeBSD$
#

PORTNAME=	gallery2
PORTVERSION=	2.2.2
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
PKGMESSAGE=	${WRKDIR}/pkg-message
CPIOARGS=	--quiet -pdum -R

# Note that USE_PHP must be set before bsd.port.pre.mk is included, so
# OPTIONS can't be used right now without making portlint angry
#OPTIONS=	NETPBM "Enable netpbm support" off \
#		IMAGEMAGICK "Enable imagemagick support" on \
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
.if !defined(WITHOUT_IMAGEMAGICK)
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
.if !defined(GALLERY2DIR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define GALLERY2DIR to override default of 'www/gallery2'."
	@${ECHO_MSG} ""
.endif

GALLERY2DIR?=	www/gallery2
PLIST_SUB+=	GALLERY2DIR=${GALLERY2DIR}

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
