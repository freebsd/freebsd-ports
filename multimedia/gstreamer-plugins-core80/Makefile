# New ports collection makefile for:	gstreamer-plugins-core
# Date created:		2004-11-15
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer-plugins-core
PORTVERSION=	0.8
PORTREVISION=	5
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

WANT_GSTREAMER=	yes

.include <bsd.port.pre.mk>

# Audio plugins
USE_GSTREAMER+=	mad vorbis

# Graphics plugins
USE_GSTREAMER+=	libpng

# Misc plugins
USE_GSTREAMER+=	gconf pango

# Multimedia plugins
USE_GSTREAMER+=	ffmpeg

.if ${OSVERSION} > 500035 || defined(WITH_XVID)
USE_GSTREAMER+=	xvid
.endif

.if !defined(WITHOUT_DVD)
# Audio plugins
USE_GSTREAMER+=	a52dec

# Multimedia plugins
USE_GSTREAMER+=	dts dvd
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
