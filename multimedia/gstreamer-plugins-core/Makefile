# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-plugins-core/Makefile,v 1.17 2006/07/17 01:39:57 ahze Exp $

PORTNAME=	gstreamer-plugins-core
PORTVERSION=	0.10
PORTREVISION=	13
CATEGORIES=	multimedia audio
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Core set of typical audio and video gstreamer-plugins

NO_BUILD=	yes
NO_MTREE=	yes
GST_DIR=	lib/gstreamer-${PORTVERSION}
PLIST_FILES=	${GST_DIR}/.gstreamer-plugins-core.keep

WANT_GSTREAMER=	yes

.include <bsd.port.pre.mk>

# Audio plugins
USE_GSTREAMER+=	mp3 ogg vorbis

# Graphics plugins
USE_GSTREAMER+=	libpng

# Misc plugins
USE_GSTREAMER+=	pango

# Multimedia plugins
USE_GSTREAMER+=	ffmpeg good theora xvid

.if !defined(WITHOUT_DVD)
# Audio plugins
USE_GSTREAMER+=	a52dec dvd dts
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " Disable DVD plugins by defining WITHOUT_DVD"
	@${ECHO_MSG} ""

do-install:
	if [ ! -d ${PREFIX}/${GST_DIR} ]; then \
		${MKDIR} ${PREFIX}/${GST_DIR} ; \
	fi
	${TOUCH} -f ${PREFIX}/${GST_DIR}/.gstreamer-plugins-core.keep

.include <bsd.port.post.mk>
