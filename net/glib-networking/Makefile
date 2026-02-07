PORTNAME=	glib-networking
PORTVERSION=	2.80.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Network-related giomodules for glib

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gnome localbase meson pkgconfig \
		python:build tar:xz
USE_GNOME=	glib20

BINARY_ALIAS=	python3=${PYTHON_VERSION}

OPTIONS_DEFINE=	OPENSSL PROXY
PROXY_DESC=	Proxy configuration support via libproxy
OPTIONS_SUB=	yes
OPTIONS_DEFAULT=	PROXY

OPENSSL_LIB_DEPENDS_OFF=	libgnutls.so:security/gnutls
OPENSSL_USES=			ssl
OPENSSL_MESON_ENABLED=		openssl
OPENSSL_MESON_DISABLED=		gnutls

PROXY_LIB_DEPENDS=	libproxy.so:net/libproxy
PROXY_MESON_ENABLED=	libproxy
PROXY_MESON_DISABLED=	environment_proxy

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd

.include <bsd.port.mk>

OPENSSL_DESC+=	(instead of GnuTLS)
