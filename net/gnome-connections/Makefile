PORTNAME=	gnome-connections
PORTVERSION=	42.1.2
PORTREVISION=	3
CATEGORIES=	net gnome
MASTER_SITES=	GNOME/sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+)\..*/\1/}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Remote desktop client for GNOME
WWW=		https://apps.gnome.org/app/org.gnome.Connections/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgtk-vnc-2.0.so:net/gtk-vnc \
		libhandy-1.so:x11-toolkits/libhandy \
		libfreerdp2.so:net/freerdp \
		libsecret-1.so:security/libsecret

USES=		desktop-file-utils shared-mime-info gettext gnome meson \
		python:env pkgconfig tar:xz vala:build
USE_GNOME=	glib20 gtk30

BINARY_ALIAS=	python3=${PYTHON_VERSION}

.include <bsd.port.mk>
