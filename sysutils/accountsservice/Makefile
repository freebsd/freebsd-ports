# Created by: Koop Mast <kwm@FreeBSD.org>

PORTNAME=	accountsservice
PORTVERSION=	0.6.55
PORTREVISION=	1
CATEGORIES=	sysutils devel
MASTER_SITES=	http://www.freedesktop.org/software/${PORTNAME}/

PATCH_SITES=	https://gitlab.freedesktop.org/${PORTNAME}/${PORTNAME}/-/commit/
PATCHFILES+=	ac9b14f1c1bb.patch:-p1 # https://gitlab.freedesktop.org/accountsservice/accountsservice/-/merge_requests/82

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	D-Bus interface for user account query and manipulation

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dbus>0:devel/dbus
LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit

USES=		cpe gettext gnome localbase:ldflags meson pkgconfig tar:xz
CPE_VENDOR=	freedesktop
USE_GNOME=	glib20 intltool libxslt introspection:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Delogind=false \
		-Dgdmconffile=${LOCALBASE}/etc/gdm/custom.conf \
		-Dlocalstatedir=/var \
		-Dsystemd=false \
		-Dsystemdsystemunitdir=no

.include <bsd.port.mk>
