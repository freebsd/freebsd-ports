PORTNAME=	gstreamer1-plugins-all
PORTVERSION=	1.16
PORTREVISION=	2
CATEGORIES=	multimedia

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Meta-port of all GStreamer 1.x plugins

USES=		gstreamer metaport

# Weed out gst-plugins that can not be packaged. or are broken.
.if defined(PACKAGE_BUILDING)
# FAAC:    Mp4 Dolby license , no package
# LAME:    MP3 License , no package
# VDPAU:   Needs to be build agains running kernel
USE_GSTREAMER=	${_GST_PLUGINS_VER:Nfaac:Nlame:Nvdpau}
.else
USE_GSTREAMER=	${_GST_PLUGINS_VER}
.endif

.include <bsd.port.mk>
