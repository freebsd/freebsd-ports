# New ports collection makefile for:    libgnomeuimm
# Date created:         22 May 2003
# Whom:                 Alexander Nedotsukov <bland@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	libgnomeuimm
PORTVERSION=	2.0.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gtkmm
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libgnomeui library

LIB_DEPENDS=	gnomemm-2.0:${PORTSDIR}/x11/libgnomemm \
		gnomecanvasmm-2.0:${PORTSDIR}/graphics/libgnomecanvasmm \
		gconfmm-2.0:${PORTSDIR}/devel/gconfmm \
		glademm-2.0:${PORTSDIR}/devel/libglademm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack libgnomeui
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES=  ${PATCHDIR}/extra-patch-old_gcc_bugs
.endif

.include <bsd.port.post.mk>
