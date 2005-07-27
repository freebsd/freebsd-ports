# New ports collection makefile for:	gstreamer-plugins-all
# Date created:		2004-12-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gstreamer-plugins-all
PORTVERSION=	1.0.${GST_VERSION}.${GST_SHLIB_VERSION}
CATEGORIES=	multimedia
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Meta-port of all gstreamer plugins with options

NO_BUILD=	yes
USE_GSTREAMER=	yes
OPTIONS=	# Hacky.. but it works the way it is set up...

.include <bsd.port.pre.mk>

WITHOUT_CAIRO=	yes
# Weed out gst-plugins that can not be packaged. or are broken.
.if defined(PACKAGE_BUILDING)
WITHOUT_FAAC=	yes	# Mp4 Dolby license , no package
WITHOUT_LAME=	yes	# MP3 License , no package
.endif
.if ${OSVERSION} < 500000
WITHOUT_LIBVISUAL=yes	# Broken on 4.x
WITHOUT_POLYPAUDIO=yes	# Broken on 4.x
WITHOUT_SWFDEC=	yes	# Depeneds on liboil, does not build on 4.x
.endif
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
PLUGS=	${_USE_GSTREAMER_ALL:S/core//:S/yes//}

.for all in ${PLUGS}
OPTIONS+=	${all:U} "${all} plugin " on
.endfor

.for f in ${PLUGS}
.if !defined(WITHOUT_${f:U})
USE_GSTREAMER+=	${f}
.endif
.endfor

do-install:	# empty

.include <bsd.port.post.mk>
