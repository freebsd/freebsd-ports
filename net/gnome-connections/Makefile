PORTNAME=	gnome-connections
PORTVERSION=	47.2.1
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Remote desktop client for GNOME
WWW=		https://apps.gnome.org/app/org.gnome.Connections/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		gtk-frdp does not build with freerdp 3.25.0
# https://gitlab.gnome.org/GNOME/gtk-frdp/-/work_items/56

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgtk-vnc-2.0.so:net/gtk-vnc \
		libhandy-1.so:x11-toolkits/libhandy \
		libfreerdp3.so:net/freerdp3 \
		libsecret-1.so:security/libsecret

USES=		desktop-file-utils fuse:3 gettext gnome meson pkgconfig \
		shared-mime-info tar:xz vala:build
USE_GNOME=	glib20 gtk30 introspection:build libxml2
GLIB_SCHEMAS=	org.gnome.Connections.gschema.xml

USE_LDCONFIG=	yes

.include <bsd.port.mk>
