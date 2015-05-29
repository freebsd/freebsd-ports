# Created by: Anders F Bjorklund <afb@users.sourceforge.net>
# $FreeBSD$
#  $MCom: ports/ports-mgmt/gnome-packagekit/Makefile,v 1.25 2011/06/14 20:18:46 mezz Exp $

PORTNAME=	gnome-packagekit
PORTVERSION=	2.32.0
PORTREVISION=	5
CATEGORIES=	ports-mgmt sysutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	PackageKit client programs for the GNOME desktop

BROKEN=		Uses unknown GNOME component gnomemenus
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-06-29

BUILD_DEPENDS=	${LOCALBASE}/bin/docbook2man:${PORTSDIR}/textproc/docbook-utils
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libpackagekit-glib2.so:${PORTSDIR}/ports-mgmt/packagekit \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique \
		libupower-glib.so:${PORTSDIR}/sysutils/upower \
		libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra

IGNORE=		Packagekit needs attention before this port can be updated.

USE_GNOME=	gnomeprefix intlhack gconf2 gnomemenus gnomedocutils
USES=		desktop-file-utils gettext iconv pathfix gmake pkgconfig \
		python:2,build tar:bzip2
GCONF_SCHEMAS=	gnome-packagekit.schemas
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

pre-configure:
	@${REINPLACE_CMD} -E -e 's/.*CPPFLAGS.*-Werror/#$$&/' \
		-e 's|-Wmissing-include-dirs||g' ${WRKSRC}/configure

.include <bsd.port.mk>
