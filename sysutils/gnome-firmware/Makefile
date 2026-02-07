PORTNAME=	gnome-firmware
DISTVERSION=	49.0
CATEGORIES=	sysutils

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Manage firmware on devices supported by fwupd
WWW=		https://gitlab.gnome.org/World/gnome-firmware

LICENSE=	GPLv2+

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libfwupd.so:sysutils/fwupd \
		libxmlb.so:textproc/libxmlb

USES=		desktop-file-utils gettext-tools gnome meson pkgconfig
USE_GNOME=	gdkpixbuf gtk40 libadwaita
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_PROJECT=	gnome-firmware
GLIB_SCHEMAS=	org.gnome.Firmware.gschema.xml

.include <bsd.port.mk>
