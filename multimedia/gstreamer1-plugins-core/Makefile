# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-plugins-core/Makefile,v 1.17 2006/07/17 01:39:57 ahze Exp $

PORTNAME=	gstreamer1-plugins-core
PORTVERSION=	${GST1_VERSION}${GST1_MINIMAL_VERSION}
PORTREVISION=	1
CATEGORIES=	multimedia audio
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Core set of typical audio and video gstreamer-plugins

NO_BUILD=	yes
GST_DIR=	lib/gstreamer-1.0
PLIST_FILES=	${GST_DIR}/.gstreamer-plugins-core.keep

USE_GSTREAMER1=yes

OPTIONS_DEFINE=	DVD
OPTIONS_DEFAULT=DVD
DVD_DESC=	Include DVD related plugins

.include <bsd.port.options.mk>

# Audio plugins
USE_GSTREAMER1+=	mad ogg vorbis

# Graphics plugins
USE_GSTREAMER1+=	png

# Misc plugins
USE_GSTREAMER1+=	pango

# Multimedia plugins
USE_GSTREAMER1+=	libav good theora

.if ${PORT_OPTIONS:MDVD}
# dvd related plugins plugins
USE_GSTREAMER1+=	a52dec dvdread resindvd dts
.endif

do-install:
	if [ ! -d ${PREFIX}/${GST_DIR} ]; then \
		${MKDIR} ${PREFIX}/${GST_DIR} ; \
	fi
	${TOUCH} -f ${PREFIX}/${GST_DIR}/.gstreamer-plugins-core.keep

.include <bsd.port.mk>
