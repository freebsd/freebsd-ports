PORTNAME=	gstreamer1-plugins-core
PORTVERSION=	${_GST_VERSION}
CATEGORIES=	multimedia audio
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Core set of typical audio and video GStreamer plugins
WWW=		https://gstreamer.freedesktop.org/

USES=		gstreamer
# Audio plugins
USE_GSTREAMER+=	mpg123 ogg vorbis

# Graphics plugins
USE_GSTREAMER+=	png

# Misc plugins
USE_GSTREAMER+=	pango

# Multimedia plugins
USE_GSTREAMER+=	libav good theora

NO_ARCH=	yes
NO_BUILD=	yes
GST_DIR=	lib/gstreamer-${_GST1_LIB_VER}
PLIST_FILES=	${GST_DIR}/.gstreamer-plugins-core.keep

OPTIONS_DEFINE=	DVD
OPTIONS_DEFAULT=DVD

DVD_DESC=	Include DVD related plugins
DVD_USE=	GSTREAMER=a52dec,dvdread,resindvd,dts

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${GST_DIR}
	${TOUCH} -f ${STAGEDIR}${PREFIX}/${GST_DIR}/.gstreamer-plugins-core.keep

.include <bsd.port.mk>
