PORTNAME=	gstreamer
PORTVERSION=	4.3.3
CATEGORIES=	multimedia rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby binding of GStreamer
WWW=		https://ruby-gnome.github.io/ \
		https://github.com/ruby-gnome/ruby-gnome

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libgstreamer-1.0.so:multimedia/gstreamer1
RUN_DEPENDS=	rubygem-gobject-introspection>=${PORTVERSION}<${PORTVERSION}_99:devel/rubygem-gobject-introspection

USES=		gem

.include <bsd.port.mk>
