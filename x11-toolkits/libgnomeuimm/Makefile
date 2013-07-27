# Created by: Alexander Nedotsukov <bland@mail.ru>
# $FreeBSD$

PORTNAME=	libgnomeuimm
PORTVERSION=	2.0.0
PORTREVISION=	13
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	SF/gtkmm/OldFiles
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libgnomeui library

LIB_DEPENDS=	gnomemm-2.0:${PORTSDIR}/x11/libgnomemm \
		gnomecanvasmm-2.0:${PORTSDIR}/graphics/libgnomecanvasmm \
		gconfmm-2.0:${PORTSDIR}/devel/gconfmm \
		glademm-2.0:${PORTSDIR}/devel/libglademm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USES=		gmake pathfix
USE_GNOME=	libgnomeui
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static

.include <bsd.port.mk>
