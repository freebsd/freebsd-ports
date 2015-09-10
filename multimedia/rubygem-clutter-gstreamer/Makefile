# $FreeBSD$

PORTNAME=	clutter-gstreamer
PORTVERSION=	2.2.5
CATEGORIES=	multimedia rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/GStreamer is a Ruby binding for GStreamer

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-clutter>=${PORTSVERSION}:${PORTSDIR}/graphics/rubygem-clutter \
		rubygem-gstreamer>=${PORTVERSION}:${PORTSDIR}/multimedia/rubygem-gstreamer

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
