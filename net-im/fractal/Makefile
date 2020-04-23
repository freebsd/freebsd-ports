# $FreeBSD$

PORTNAME=	fractal
DISTVERSION=	4.2.2
PORTREVISION=	4
CATEGORIES=	net-im
MASTER_SITES=	https://gitlab.gnome.org/World/fractal/uploads/${GL_HASH}/

MAINTAINER=	greg@unrelenting.technology
COMMENT=	GTK+ Matrix IM client

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# gmake for the gettext-sys crate
BUILD_DEPENDS=	cargo:lang/${RUST_DEFAULT} \
		gmake:devel/gmake
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libgmp.so:math/gmp \
		libgspell-1.so:textproc/gspell \
		libges-1.0.so:multimedia/gstreamer1-editing-services \
		libhandy-0.0.so:x11-toolkits/libhandy

USES=		gettext gnome meson pkgconfig python:3.5+,build ssl tar:xz
USE_GNOME=	cairo gtk30 gtksourceview4
USE_GSTREAMER1=	bad

GL_HASH=	9f2b34d98cfe3c002f3afbfcbf14bc7c
BINARY_ALIAS=		python3=${PYTHON_CMD}
GLIB_SCHEMAS=		org.gnome.Fractal.gschema.xml
INSTALLS_ICONS=		yes

# for the gettext-sys crate
MAKE_ENV+=	GETTEXT_BIN_DIR=${LOCALBASE}/bin \
		GETTEXT_LIB_DIR=${LOCALBASE}/lib \
		GETTEXT_INCLUDE_DIR=${LOCALBASE}/include

post-patch:
# Disable vendor checksums
	@${REINPLACE_CMD} -e 's/"files":{[^}]*}/"files":{}/' \
		${WRKSRC}/vendor/*/.cargo-checksum.json

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fractal

.include <bsd.port.mk>
