# New ports collection makefile for:	gstreamer-plugins-core
# Date created:		2004-11-15
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-plugins-core80/Makefile,v 1.4 2006/01/24 18:49:48 marcus Exp $

PORTNAME=	gstreamer-plugins-core80
PORTVERSION=	0.8.11
PORTREVISION=	7
CATEGORIES=	multimedia audio
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Core set of typical audio and video gstreamer-plugins

USE_X_PREFIX=	yes
NO_BUILD=	yes

GST_DIR=	lib/gstreamer-${GST80_VERSION}
PLIST_FILES=	${GST_DIR}/.gstreamer-plugins-core.keep

WANT_GSTREAMER=	yes

.include <bsd.port.pre.mk>

# Audio plugins
USE_GSTREAMER80+=	mad vorbis

# Graphics plugins
USE_GSTREAMER80+=	libpng

# Misc plugins
USE_GSTREAMER80+=	pango

# Multimedia plugins
USE_GSTREAMER80+=	ffmpeg

.if ${OSVERSION} > 500035 || defined(WITH_XVID)
USE_GSTREAMER80+=	xvid
.endif

.if !defined(WITHOUT_DVD)
# Audio plugins
USE_GSTREAMER80+=	a52dec

# Multimedia plugins
USE_GSTREAMER80+=	dts dvd
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " Disable DVD plugins by defining WITHOUT_DVD"
	@${ECHO_MSG} ""
.if ${OSVERSION} < 500035 && !defined(WITH_XVID)
	@${ECHO_MSG} " Enable XVID plugins by defining WITH_XVID"
	@${ECHO_MSG} ""
.endif

do-install:
	if [ ! -d ${PREFIX}/${GST_DIR} ]; then \
		${MKDIR} ${PREFIX}/${GST_DIR} ; \
	fi
	${TOUCH} -f ${PREFIX}/${GST_DIR}/.gstreamer-plugins-core.keep

.include <bsd.port.post.mk>
