# New ports collection makefile for:	gstreamer-plugins-all
# Date created:		2004-12-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-plugins-all/Makefile,v 1.8 2006/01/25 18:54:32 ahze Exp $
#

PORTNAME=	gstreamer-plugins-all
PORTVERSION=	1.3.${GST_VERSION}.${GST_SHLIB_VERSION}
PORTREVISION=	9
CATEGORIES=	multimedia
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Meta-port of all gstreamer plugins with options

NO_BUILD=	yes
USE_GSTREAMER=	yes
OPTIONS=	# Hacky.. but it works the way it is set up...

.include <bsd.port.pre.mk>

# Weed out gst-plugins that can not be packaged. or are broken.
.if defined(PACKAGE_BUILDING)
WITHOUT_FAAC=	yes	# Mp4 Dolby license , no package
WITHOUT_LAME=	yes	# MP3 License , no package
WITHOUT_SWFDEC=	yes	# Broken
WITHOUT_MPEG2ENC=	yes	# Broken
.endif
.if ${ARCH}!="i386"
WITHOUT_SPC=	yes	# i386 only
.endif

# Remove core, yes
PLUGS=	${_USE_GSTREAMER10_ALL}

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
