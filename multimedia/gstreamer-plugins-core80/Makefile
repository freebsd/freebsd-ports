# New ports collection makefile for:	gstreamer-plugins-core
# Date created:		2004-11-15
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer-plugins-core
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Core set of typical audio and video gstreamer-plugins

USE_X_PREFIX=	yes
NO_BUILD=	yes

GST_DIR=	lib/gstreamer-${PORTVERSION}
PLIST_FILES=	${GST_DIR}/.gstreamer-plugins-core.keep

# Audio plugins
USE_GSTREAMER+=	a52dec mad vorbis

# Graphics plugins
USE_GSTREAMER+=	libpng

# Multimedia plugins
USE_GSTREAMER+=	ffmpeg dts dvd xvid

do-install:
	if [ ! -d ${PREFIX}/${GST_DIR} ]; then \
		${MKDIR} ${PREFIX}/${GST_DIR} ; \
	fi
	${TOUCH} -f ${PREFIX}/${GST_DIR}/.gstreamer-plugins-core.keep

.include <bsd.port.mk>
