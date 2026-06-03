PORTNAME=	accountsservice
DISTVERSION=	26.13.3
PORTREVISION=	1
CATEGORIES=	sysutils devel

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	D-Bus interface for user account query and manipulation
WWW=		https://gitlab.freedesktop.org/accountsservice/accountsservice

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dbus>0:devel/dbus
LIB_DEPENDS=	libpolkit-gobject-1.so:sysutils/polkit \
		libjson-c.so:devel/json-c \
		libconsolekit.so:sysutils/consolekit2

USES=		cpe gettext-tools gnome meson pkgconfig tar:bz2
CPE_VENDOR=	freedesktop
USE_GNOME=	glib20 introspection:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Dconsolekit=true \
		-Dwtmpfile=/var/log/utx.log \
		-Dgdmconffile=${LOCALBASE}/etc/gdm/custom.conf \
		-Dlightdmconffile=${LOCALBASE}/etc/lightdm/lightdm.conf \
		-Dsystemdsystemunitdir=no \
		-Dtests=false

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	arrowd
GL_TAGNAME=	dab9a3e353851bb066c7feb8a12a59150dbdc009

OPTIONS_DEFINE=		VAPI
OPTIONS_DEFAULT=	VAPI
OPTIONS_SUB=		yes

VAPI_USES=		vala:build
VAPI_MESON_TRUE=	vapi

post-patch:
	${ECHO_CMD} "#!${SH}" > ${WRKSRC}/generate-version.sh
	${ECHO_CMD} "${ECHO_CMD} ${PORTVERSION}" >> ${WRKSRC}/generate-version.sh

.include <bsd.port.mk>
