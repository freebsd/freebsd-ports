PORTNAME=	fprintd
DISTVERSIONPREFIX=v
DISTVERSION=	1.94.4
PORTREVISION=	0
CATEGORIES=	security

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Daemon that provides fingerprint scanning functionality over D-Bus
WWW=		https://gitlab.freedesktop.org/libfprint/fprintd

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfprint-2.so:security/libfprint \
		libdbus-1.so:devel/dbus \
		libdbus-glib-1.so:devel/dbus-glib \
		libbasu.so:devel/basu \
		libpolkit-gobject-1.so:sysutils/polkit

USES=		gettext gmake gnome libtool pkgconfig meson
USE_RC_SUBR=	fprintd
USE_GNOME=	intltool glib20

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	libfprint

MESON_ARGS=	-Dlibsystemd=basu -Dsystemd=false -Dpam_modules_dir=${PREFIX}/lib

.include <bsd.port.mk>
