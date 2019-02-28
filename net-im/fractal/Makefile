# $FreeBSD$

PORTNAME=	fractal
DISTVERSION=	3.30.0
PORTREVISION=	5
CATEGORIES=	net-im
MASTER_SITES=	https://gitlab.gnome.org/World/fractal/uploads/${GL_HASH}/

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GTK+ Matrix IM client

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# gmake for the backtrace-sys crate
BUILD_DEPENDS=	cargo:lang/${RUST_DEFAULT} \
		gmake:devel/gmake
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libgmp.so:math/gmp \
		libgspell-1.so:textproc/gspell

USES=		gettext gnome meson pkgconfig python:3.5+,build ssl tar:xz
USE_GNOME=	cairo gtk30 gtksourceview3
USE_GSTREAMER1=	bad

GL_HASH=	cc46d6b9702ce5d0b1f3073f516a58c3
BINARY_ALIAS=		python3=${PYTHON_CMD}
GLIB_SCHEMAS=		org.gnome.Fractal.gschema.xml
INSTALLS_ICONS=		yes
WITHOUT_FBSD10_FIX=	yes # changes libbacktrace conf script's checksum

# for the gettext-sys crate
MAKE_ENV+=	GETTEXT_BIN_DIR=${LOCALBASE}/bin \
		GETTEXT_LIB_DIR=${LOCALBASE}/lib \
		GETTEXT_INCLUDE_DIR=${LOCALBASE}/include

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fractal

.include <bsd.port.mk>
