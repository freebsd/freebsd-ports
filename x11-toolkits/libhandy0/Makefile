PORTNAME=	libhandy
PORTVERSION=	0.0.13
PORTREVISION=	3
CATEGORIES=	x11-toolkits gnome
DIST_SUBDIR=	gnome
PKGNAMESUFFIX=	0

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Building blocks for modern adaptive GNOME apps
WWW=		https://gitlab.gnome.org/GNOME/libhandy/

LICENSE=	LGPL21

USES=		compiler:c11 gettext gnome meson pkgconfig vala:build
USE_GNOME=	cairo gdkpixbuf2 gtk30 introspection:build

USE_LDCONFIG=	yes
MESON_ARGS=	-Dtests=false \
		-Dglade_catalog=disabled

USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org/
GL_ACCOUNT=	GNOME
GL_TAGNAME=	7a193d7692c9c76a1a94f17c4d30b585f77d177c

.include <bsd.port.mk>
