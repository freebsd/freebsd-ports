# $FreeBSD$

PORTNAME=	fprintd
PORTVERSION=	0.6.0
CATEGORIES=	security
MASTER_SITES=	http://people.freedesktop.org/~hadess/

MAINTAINER=	la5lbtyi@aon.at
COMMENT=	Daemon that provides fingerprint scanning functionality over D-Bus

LICENSE=	GPLv2

LIB_DEPENDS=	libfprint.so:security/libfprint \
		libdbus-glib-1.so:devel/dbus-glib \
		libpolkit-gobject-1.so:sysutils/polkit

GNU_CONFIGURE=	yes
USES=		tar:xz gmake libtool pkgconfig
USE_GNOME=	intltool glib20

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
