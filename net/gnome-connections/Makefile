PORTNAME=	gnome-connections
PORTVERSION=	47.2.1
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Remote desktop client for GNOME
WWW=		https://apps.gnome.org/app/org.gnome.Connections/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libgtk-vnc-2.0.so:net/gtk-vnc \
		libhandy-1.so:x11-toolkits/libhandy \
		libfreerdp3.so:net/freerdp3 \
		libsecret-1.so:security/libsecret

USES=		desktop-file-utils fuse:3 gettext gnome meson pkgconfig \
		shared-mime-info tar:xz vala:build
USE_GNOME=	glib20 gtk30 introspection:build libxml2
USE_LDCONFIG=	yes

GLIB_SCHEMAS=	org.gnome.Connections.gschema.xml

.include <bsd.port.mk>
