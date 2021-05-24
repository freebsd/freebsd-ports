# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	accountsservice
PORTVERSION=	0.6.55
CATEGORIES=	sysutils devel
MASTER_SITES=	http://www.freedesktop.org/software/${PORTNAME}/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	D-Bus interface for user account query and manipulation

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dbus>0:devel/dbus
LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit

USE_GNOME=	glib20 intltool introspection:build libxslt
USES=		cpe gettext gnome localbase:ldflags meson \
		pkgconfig tar:xz
CPE_VENDOR=	ray_stode
USE_LDCONFIG=	yes
MESON_ARGS=	-Dsystemdsystemunitdir=no \
		-Dgdmconffile=${LOCALBASE}/etc/gdm/custom.conf \
		-Dsystemd=false \
		-Delogind=false \
		-Dlocalstatedir=/var

.include <bsd.port.mk>
