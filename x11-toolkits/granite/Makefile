PORTNAME=	granite
DISTVERSION=	6.2.0
CATEGORIES=	x11-toolkits

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Extensions of GTK+3 toolkit

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee
RUN_DEPENDS=	contractor:sysutils/contractor \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		gettext gnome meson pkgconfig python:3.6+,build tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
USE_GNOME=	cairo glib20 gtk30 gdkpixbuf2 introspection:build
USE_LDCONFIG=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}
PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
