# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glib-networking
PORTVERSION=	2.56.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Network-related giomodules for glib

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libp11-kit.so:security/p11-kit \
		libdbus-1.so:devel/dbus \
		libproxy.so:net/libproxy
RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

PORTSCOUT=	limitw:1,even

USES=		compiler:c11 gettext gnome localbase meson pkgconfig \
		python:3.6+,build tar:xz
USE_GNOME=	glib20
MESON_ARGS=	-Dca_certificates_path="${LOCALBASE}/share/certs/ca-root-nss.crt"

BINARY_ALIAS=	python3=${PYTHON_VERSION}

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd
	${RM} -r ${STAGEDIR}${PREFIX}/share/installed-tests

.include <bsd.port.mk>
