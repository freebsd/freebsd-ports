# New ports collection makefile for:	gnomeutils
# Version required:			1.0.50
# Date created:				03 July 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	gnome-utils-1.0.50
PKGNAME=	gnomeutils-1.0.50
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-utils

MAINTAINER=	nakai@FreeBSD.org

BUILD_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore
LIB_DEPENDS=	obgnome.1:${PORTSDIR}/lang/gnomeobjc

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${PREFIX}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gtt.1

.include <bsd.port.mk>
