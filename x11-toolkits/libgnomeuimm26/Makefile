# New ports collection makefile for:    libgnomeuimm
# Date created:         22 May 2003
# Whom:                 Alexander Nedotsukov <bland@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	libgnomeuimm
PORTVERSION=	2.6.0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libgnomeui library

LIB_DEPENDS=	gnomemm-2.6.1:${PORTSDIR}/x11/libgnomemm26 \
		gnomecanvasmm-2.6.1:${PORTSDIR}/graphics/libgnomecanvasmm26 \
		gconfmm-2.6.1:${PORTSDIR}/devel/gconfmm26 \
		glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		gnomevfsmm-2.6.1:${PORTSDIR}/devel/gnome-vfsmm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

LATEST_LINK=	libgnomeuimm26

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GCC=	3.3
USE_REINPLACE=	yes
USE_GNOME=	gnomehack lthack libgnomeui
USE_INC_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static

PLIST_SUB=	VERSION="2.6" API_VERSION="2.6"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
