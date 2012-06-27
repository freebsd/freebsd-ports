# New ports collection makefile for:	gstreamer-plugins-all
# Date created:		2004-12-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/multimedia/gstreamer-plugins-all/Makefile,v 1.8 2006/01/25 18:54:32 ahze Exp $
#

PORTNAME=	gstreamer-plugins-all
PORTVERSION=	1.3.${GST_VERSION}.${GST_SHLIB_VERSION}
PORTREVISION=	13
CATEGORIES=	multimedia
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Meta-port of all gstreamer plugins with options

NO_BUILD=	yes
USE_GSTREAMER=	yes
.include "${.CURDIR}/../../Mk/bsd.gstreamer.mk"

.for all in ${_USE_GSTREAMER10_ALL}
OPTIONS_DEFINE+=	${all:U}
${all:U}_DESC=	${all} plugin
OPTIONS_DEFAULT+=	${all:U}
.endfor

.include <bsd.port.pre.mk>

# Weed out gst-plugins that can not be packaged. or are broken.
.if defined(PACKAGE_BUILDING)
PORT_OPTIONS:=	${PORT_OPTIONS:NFAAC} # Mp4 Dolby license , no package
PORT_OPTIONS:=	${PORT_OPTIONS:NLAME} # MP3 License , no package
PORT_OPTIONS:=	${PORT_OPTIONS:NPEG2ENC} # Broken
PORT_OPTIONS:=	${PORT_OPTIONS:NVDPAU} # Needs to be build agains running kernel
.endif

.if ${ARCH} != "i386"
PORT_OPTIONS:=	${PORT_OPTIONS:NSPC} # i386 only
.endif

.for f in ${OPTIONS_DEFINE}
.if ${PORT_OPTIONS:M${f:U}}
USE_GSTREAMER+=	${f:L}
.endif
.endfor

do-install:	# empty

.include <bsd.port.post.mk>
