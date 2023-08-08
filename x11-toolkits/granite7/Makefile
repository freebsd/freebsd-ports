PORTNAME=	granite
DISTVERSION=	7.2.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits
PKGNAMESUFFIX=	7

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Extensions of GTK 4.0 toolkit
WWW=		https://github.com/elementary/granite

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgee-0.8.so:devel/libgee
RUN_DEPENDS=	contractor:sysutils/contractor \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas \
		xdg-desktop-portal>0:deskutils/xdg-desktop-portal

USES=		gettext gnome meson pkgconfig python:build tar:xz vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
USE_GNOME=	cairo glib20 gtk40 gdkpixbuf2 introspection:build
USE_LDCONFIG=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}
PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.mk>
