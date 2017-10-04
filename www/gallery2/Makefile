# Created by: Alex Varju <freebsd-ports@varju.ca>
# $FreeBSD$

PORTNAME=	gallery2
PORTVERSION=	2.3.2
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	SF/gallery/${PORTNAME}/${PORTVERSION}
DISTNAME=	gallery-${PORTVERSION}-full
DIST_SUBDIR=	gallery2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Web based photo album organizer written in PHP

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DCRAW FFMPEG GD GRAPHMAGICK IMAGEMAGICK JHEAD NETPBM NLS
OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	MYSQL PGSQL
OPTIONS_DEFAULT=IMAGEMAGICK JHEAD MYSQL

NO_ARCH=	yes
NO_BUILD=	yes
USES=		php:web
USE_PHP=	pcre session
WRKSRC=		${WRKDIR}/${PORTNAME}

SUB_FILES=	pkg-message

DCRAW_RUN_DEPENDS=	dcraw:graphics/dcraw
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
GD_RUN_DEPENDS=		pngtogd:graphics/gd
GD_USE=			PHP=gd
GRAPHMAGICK_RUN_DEPENDS=gm:graphics/GraphicsMagick
IMAGEMAGICK_RUN_DEPENDS=convert:graphics/ImageMagick
JHEAD_RUN_DEPENDS=	jhead:graphics/jhead
MYSQL_USE=		PHP=mysqli
NETPBM_RUN_DEPENDS=	giftopnm:graphics/netpbm
NLS_USE=		PHP=gettext
NLS_USES=		gettext
PGSQL_USE=		PHP=pgsql

do-install:
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/

.include <bsd.port.mk>
