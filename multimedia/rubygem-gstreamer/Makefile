# $FreeBSD$

PORTNAME=	gstreamer
PORTVERSION=	3.3.7
CATEGORIES=	multimedia rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby/GStreamer is a Ruby binding for GStreamer

LICENSE=	LGPL21+

LIB_DEPENDS=	libgstreamer-1.0.so:multimedia/gstreamer1
RUN_DEPENDS=	rubygem-gobject-introspection>=${PORTVERSION}:devel/rubygem-gobject-introspection

USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
