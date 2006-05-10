# New ports collection makefile for:	gstreamer-plugins-all
# Date created:		2004-12-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-plugins-all80/Makefile,v 1.2 2006/01/20 14:27:43 ahze Exp $
#

PORTNAME=	gstreamer-plugins-all80
PORTVERSION=	1.1.${GST80_VERSION}.${GST80_SHLIB_VERSION}
CATEGORIES=	multimedia
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Meta-port of all gstreamer plugins with options

NO_BUILD=	yes
USE_GSTREAMER80=	yes
OPTIONS=	# Hacky.. but it works the way it is set up...

.include <bsd.port.pre.mk>

# Weed out gst-plugins that can not be packaged. or are broken.
.if defined(PACKAGE_BUILDING)
WITHOUT_FAAC=	yes	# Mp4 Dolby license , no package
WITHOUT_LAME=	yes	# MP3 License , no package
.endif
WITHOUT_MPEG2ENC=yes	# Broken from updated mjpegtools
.if ${OSVERSION} < 500000
WITHOUT_LIBVISUAL=yes	# Broken on 4.x
WITHOUT_POLYPAUDIO=yes	# Broken on 4.x
.endif
WITHOUT_FAAD=yes	# Broken
# Shout & Shout2 Conflict
.if !defined(WITHOUT_SHOUT) && !defined(WITHOUT_SHOUT2)
WITHOUT_SHOUT=	yes
.endif
# Jpeg & Jpeg-mmx Conflict
.if ${ARCH}!="i386"
WITHOUT_JPEG-MMX=	yes
.else
.if !defined(WITHOUT_JPEG) && !defined(WITHOUT_JPEG-MMX)
WITHOUT_JPEG-MMX=	yes
.endif
.endif

# Remove core, yes
PLUGS=	${_USE_GSTREAMER80_ALL:S/core//:S/yes//}

.for all in ${PLUGS}
OPTIONS+=	${all:U} "${all} plugin " on
.endfor

.for f in ${PLUGS}
.if !defined(WITHOUT_${f:U})
USE_GSTREAMER80+=	${f}
.endif
.endfor

do-install:	# empty

.include <bsd.port.post.mk>
