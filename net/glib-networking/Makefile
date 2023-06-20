PORTNAME=	glib-networking
PORTVERSION=	2.76.0
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
		python:3.7+,build tar:xz
USE_GNOME=	glib20

BINARY_ALIAS=	python3=${PYTHON_VERSION}

OPTIONS_DEFINE=	GNUTLS PROXY
PROXY_DESC=	Proxy configuration support via libproxy
OPTIONS_SUB=	yes
OPTIONS_DEFAULT=	GNUTLS PROXY

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES_OFF=	ssl
GNUTLS_CONFIGURE_OFF=	-Dgnutls=disabled -Dopenssl=enabled

PROXY_LIB_DEPENDS=	libproxy.so:net/libproxy
PROXY_CONFIGURE_OFF=	-Dlibproxy=disabled -Denvironment_proxy=enabled

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd
	${RM} -r ${STAGEDIR}${PREFIX}/share/installed-tests

.include <bsd.port.mk>

GNUTLS_DESC+=	(OpenSSL if off)
