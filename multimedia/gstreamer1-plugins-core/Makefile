PORTNAME=	gstreamer1-plugins-core
PORTVERSION=	1.16
CATEGORIES=	multimedia audio
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Core set of typical audio and video GStreamer plugins

NO_ARCH=	yes
NO_BUILD=	yes
GST_DIR=	lib/gstreamer-1.0
PLIST_FILES=	${GST_DIR}/.gstreamer-plugins-core.keep

USES=		gstreamer

OPTIONS_DEFINE=	DVD
OPTIONS_DEFAULT=DVD
DVD_DESC=	Include DVD related plugins

.include <bsd.port.options.mk>

# Audio plugins
USE_GSTREAMER+=	mpg123 ogg vorbis

# Graphics plugins
USE_GSTREAMER+=	png

# Misc plugins
USE_GSTREAMER+=	pango

# Multimedia plugins
USE_GSTREAMER+=	libav good theora

.if ${PORT_OPTIONS:MDVD}
# dvd related plugins plugins
USE_GSTREAMER+=	a52dec dvdread resindvd dts
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${GST_DIR}
	${TOUCH} -f ${STAGEDIR}${PREFIX}/${GST_DIR}/.gstreamer-plugins-core.keep

.include <bsd.port.mk>
