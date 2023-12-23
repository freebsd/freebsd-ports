PORTNAME=	granite
DISTVERSION=	6.2.0
PORTREVISION=	2
CATEGORIES=	x11-toolkits

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Extensions of GTK 3 toolkit
WWW=		https://github.com/elementary/granite

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgee-0.8.so:devel/libgee
RUN_DEPENDS=	contractor:sysutils/contractor \
		gsettings-desktop-schemas>0:devel/gsettings-desktop-schemas

USES=		gettext gnome meson pkgconfig python:build tar:xz vala:build
USE_GITHUB=	yes
GH_ACCOUNT=	elementary
USE_GNOME=	cairo glib20 gtk30 gdkpixbuf2 introspection:build
USE_LDCONFIG=	yes

BINARY_ALIAS=	python3=${PYTHON_CMD}
PORTSCOUT=	limit:^6
PLIST_SUB=	DISTVERSION=${DISTVERSION}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
