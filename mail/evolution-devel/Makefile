# New ports collection makefile for:	evolution
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	evolution
PORTVERSION=	0.1
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/evolution

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		xml.5:${PORTSDIR}/textproc/libxml \
		glade.3:${PORTSDIR}/devel/libglade \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		gnomeprint.9:${PORTSDIR}/print/gnomeprint \
		oaf.0:${PORTSDIR}/devel/oaf \
		bonobo.2:${PORTSDIR}/devel/bonobo \
		gnomevfs.0:${PORTSDIR}/devel/gnomevfs \
		unicode.0:${PORTSDIR}/devel/libunicode \
		gtkhtml.2:${PORTSDIR}/www/gtkhtml \
		ldap.1:${PORTSDIR}/net/openldap \
		capplet.4:${PORTSDIR}/sysutils/gnomecontrolcenter

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libical/configure
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

PLIST_SUB=	VERSION=${PORTVERSION}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
