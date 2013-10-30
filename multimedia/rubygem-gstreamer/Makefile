# $FreeBSD$

PORTNAME=	gstreamer
PORTVERSION=	2.0.2
CATEGORIES=	multimedia rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/GStreamer is a Ruby binding for GStreamer

RUN_DEPENDS=	rubygem-glib2>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-glib2 \
		rubygem-gobject-introspection>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-gobject-introspection
LIB_DEPENDS=	gstreamer-1.0:${PORTSDIR}/multimedia/gstreamer1

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
