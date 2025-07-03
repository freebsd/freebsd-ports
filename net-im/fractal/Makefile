PORTNAME=	fractal
DISTVERSION=	4.4.2
PORTREVISION=	22
CATEGORIES=	net-im
MASTER_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/archive/${DISTVERSION}/
# XXX USES=cargo omits the default source archive by default
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	GTK Matrix IM client
WWW=		https://gitlab.gnome.org/GNOME/fractal

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libgmp.so:math/gmp \
		libgspell-1.so:textproc/gspell \
		libhandy-0.0.so:x11-toolkits/libhandy0

USES=		cargo cpe desktop-file-utils gettext gnome gstreamer meson \
		pkgconfig python:build shebangfix ssl
CPE_VENDOR=	gnome
USE_GNOME=	cairo gdkpixbuf gtk30 gtksourceview4
USE_GSTREAMER=	bad editing-services

SHEBANG_FILES=	scripts
BINARY_ALIAS=	python3=${PYTHON_CMD}
GLIB_SCHEMAS=	org.gnome.Fractal.gschema.xml

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
CARGO_TARGET_DIR=	${WRKSRC}/${MESON_BUILD_DIR}/target
MAKE_ENV+=	${CARGO_ENV}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
LTO_UNSAFE=	yes
.endif

.include <bsd.port.mk>
