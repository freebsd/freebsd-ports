PORTNAME=	libproxy
DISTVERSION=	0.5.10
CATEGORIES=	net devel

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Library that provides automatic proxy configuration management
WWW=		https://libproxy.github.io/libproxy/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gnome meson pkgconfig

CPE_VENDOR=	libproxy_project
USE_GITHUB=	yes

USE_GNOME=	glib20 introspection

MESON_ARGS=	-Dtests=true \
		-Dconfig-windows=false \
		-Dconfig-osx=false \
		-Dintrospection=true \
		-Drelease=true
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	CURL DOCS VAPI
OPTIONS_GROUP=	CONFIG PACRUNNER
OPTIONS_GROUP_CONFIG=	ENV GNOME KDE SYSCONFIG XDP
OPTIONS_GROUP_PACRUNNER=	DUKTAPE
OPTIONS_DEFAULT=	CURL ENV GNOME KDE SYSCONFIG VAPI XDP
OPTIONS_SUB=	yes

ENV_DESC=	Environment configuration support
DUKTAPE_DESC=	PAC Runner Duktape support
SYSCONFIG_DESC=	sysconfig configuration support
XDP_DESC=	XDG Desktop Portal (Flatpak) support

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_MESON_TRUE=	curl

DOCS_BUILD_DEPENDS=	gi-docgen:textproc/py-gi-docgen
DOCS_MESON_TRUE=	docs

DUKTAPE_LIB_DEPENDS=	libduktape.so:lang/duktape-lib
DUKTAPE_MESON_TRUE=	pacrunner-duktape

ENV_MESON_TRUE=		config-env

GNOME_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:devel/gsettings-desktop-schemas
GNOME_RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:devel/gsettings-desktop-schemas
GNOME_MESON_TRUE=	config-gnome

KDE_MESON_TRUE=		config-kde

SYSCONFIG_MESON_TRUE=	config-sysconfig

VAPI_USES=		vala:build
VAPI_MESON_TRUE=	vapi

XDP_MESON_TRUE=		config-xdp

.include <bsd.port.mk>
