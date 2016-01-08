# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gstreamer-plugins-all
PORTVERSION=	1.3.${GST_VERSION}.${GST_SHLIB_VERSION}
PORTREVISION=	16
CATEGORIES=	multimedia

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Meta-port of all gstreamer plugins with options

USES=		metaport
USE_GSTREAMER=	yes

.include "${.CURDIR}/../../Mk/bsd.gstreamer.mk"

ALL_PLUGINS:=	${_GSTREAMER_PLUGINS}
# Weed out gst-plugins that can not be packaged. or are broken.
.if defined(PACKAGE_BUILDING)
# FAAC:    Mp4 Dolby license , no package
# LAME:    MP3 License , no package
# VDPAU:   Needs to be build agains running kernel
DEF_PLUGINS:=	${_GSTREAMER_PLUGINS:Nfaac:Nlame:Nvdpau}
.else
DEF_PLUGINS:=	${_GSTREAMER_PLUGINS}
.endif

.for all in ${ALL_PLUGINS}
${all:tu}_DESC=	${all} plugin
${all:tu}_USE=	GSTREAMER=${all}
.endfor

# Pull out i386-only plugins, add back conditionally
ALL_PLUGINS:=	${ALL_PLUGINS:Nspc}
DEF_PLUGINS:=	${DEF_PLUGINS:Nspc}

OPTIONS_DEFINE=	${ALL_PLUGINS:tu}
OPTIONS_DEFAULT=	${DEF_PLUGINS:tu}

OPTIONS_DEFAULT_i386=	SPC
OPTIONS_DEFAULT_i386=	SPC

.include <bsd.port.mk>
