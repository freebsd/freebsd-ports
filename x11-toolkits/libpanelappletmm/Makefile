# New ports collection makefile for:    libpanelappletmm
# Date created:         3 Dec 2003
# Whom:                 Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libpanelappletmm
PORTVERSION=	2.6.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	gnome2

MAINTAINER=	bland@FreeBSD.org
COMMENT=	C++ wrapper for libpanelapplet library

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gconfmm-2.6.1:${PORTSDIR}/devel/gconfmm26 \
		gnomemm-2.6.1:${PORTSDIR}/x11/libgnomemm26
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GCC=	3.4
USE_GNOME=	gnomehack lthack gnomepanel
USE_INC_LIBTOOL_VER=13
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-static

PLIST_SUB=	VERSION="2.6" API_VERSION="2.6"

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples//' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|\(-lglibmm\)|-L\$$(GMM_PROCDIR)/../.. \1|" \
		${WRKSRC}/tools/extra_defs_gen/Makefile.in

.include <bsd.port.mk>
