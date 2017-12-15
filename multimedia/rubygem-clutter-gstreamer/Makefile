# $FreeBSD$

PORTNAME=	clutter-gstreamer
PORTVERSION=	3.2.1
CATEGORIES=	multimedia rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/GStreamer is a Ruby binding for GStreamer

LICENSE=	LGPL21+

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
LIB_DEPENDS=	libclutter-gst-3.0.so:multimedia/clutter-gst3
RUN_DEPENDS=	rubygem-clutter>=${PORTSVERSION}:graphics/rubygem-clutter \
		rubygem-gdk_pixbuf2>=${PORTSVERSION}:graphics/rubygem-gdk_pixbuf2 \
		rubygem-gstreamer>=${PORTVERSION}:multimedia/rubygem-gstreamer

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
