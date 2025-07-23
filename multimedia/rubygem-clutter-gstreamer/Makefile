PORTNAME=	clutter-gstreamer
PORTVERSION=	4.3.0
CATEGORIES=	multimedia rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of Clutter-GStreamer
WWW=		https://ruby-gnome.github.io/ \
		https://github.com/ruby-gnome/ruby-gnome

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
LIB_DEPENDS=	libclutter-gst-3.0.so:multimedia/clutter-gst3
RUN_DEPENDS=	rubygem-clutter>=${PORTSVERSION}:graphics/rubygem-clutter \
		rubygem-gdk_pixbuf2>=${PORTSVERSION}:graphics/rubygem-gdk_pixbuf2 \
		rubygem-gstreamer>=${PORTVERSION}<${PORTVERSION}_99:multimedia/rubygem-gstreamer

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
