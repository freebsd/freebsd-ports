PORTNAME=	accountsservice
PORTVERSION=	23.13.9
PORTREVISION=	2
CATEGORIES=	sysutils devel
MASTER_SITES=	https://www.freedesktop.org/software/${PORTNAME}/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	D-Bus interface for user account query and manipulation
WWW=		https://gitlab.freedesktop.org/accountsservice/accountsservice

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dbus>0:devel/dbus
LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit \
		libconsolekit.so:sysutils/consolekit2

USES=		cpe gettext gnome meson pkgconfig tar:xz
CPE_VENDOR=	freedesktop
USE_GNOME=	glib20 intltool libxslt introspection:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Dconsolekit=true \
		-Dgdmconffile=${LOCALBASE}/etc/gdm/custom.conf \
		-Dlightdmconffile=${LOCALBASE}/etc/lightdm/lightdm.conf \
		-Dsystemdsystemunitdir=no \
		-Dvapi=false \
		-Dtests=false

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	arrowd
GL_TAGNAME=	665c4390164f47283f234970087105e52245ae67

.include <bsd.port.mk>
