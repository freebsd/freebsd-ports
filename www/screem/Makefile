# New ports collection makefile for:	SCREEM
# Date created:		05 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	screem
PORTVERSION= 	0.2.8
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.screem.org/src/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		xml.5:${PORTSDIR}/textproc/libxml \
		glade.4:${PORTSDIR}/devel/libglade \
		guile.6:${PORTSDIR}/lang/guile \
		wwwcore.1:${PORTSDIR}/www/libwww \
		Xpm.4:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=    gnomecc:${PORTSDIR}/sysutils/gnomecontrolcenter

USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_X_PREFIX=	yes

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share \
		--libdir=${PREFIX}/share

.include <bsd.port.mk>
