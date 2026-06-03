PORTNAME=	amtk
DISTVERSION=	5.10.0
CATEGORIES=	x11-toolkits
DISTNAME=	libgedit-${PORTNAME}-${DISTVERSIONFULL}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Good Morning Toolkit
WWW=		https://gitlab.gnome.org/World/gedit/libgedit-amtk

LICENSE=	LGPL3

USES=		gettext-tools gnome meson pkgconfig tar:bz2
USE_GITLAB=	yes
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World/gedit
GL_PROJECT=	libgedit-amtk
USE_GNOME=	glib20 gtk30 introspection:build
USE_LDCONFIG=	yes

MESON_ARGS=	-Dgtk_doc=false \
		-Dtests=false

.include <bsd.port.mk>
