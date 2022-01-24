PORTNAME=	fractal
DISTVERSION=	4.4.0
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	https://gitlab.gnome.org/World/fractal/uploads/${GL_HASH}/

PATCH_SITES=	https://gitlab.gnome.org/GNOME/${PORTNAME}/-/commit/
PATCHFILES+=	6fa1a23596d6.patch:-p1 # https://gitlab.gnome.org/GNOME/fractal/-/merge_requests/867

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
		libhandy-0.0.so:x11-toolkits/libhandy0

USES=		cpe gettext gnome meson pkgconfig python:3.5+,build ssl tar:xz
CPE_VENDOR=	gnome
USE_GNOME=	cairo gtk30 gtksourceview4
USE_GSTREAMER1=	bad editing-services

GL_HASH=	d4168ac40fd681240964705e000dd353
BINARY_ALIAS=		python3=${PYTHON_CMD}
GLIB_SCHEMAS=		org.gnome.Fractal.gschema.xml

# for the gettext-sys crate
MAKE_ENV+=	GETTEXT_BIN_DIR=${LOCALBASE}/bin \
		GETTEXT_LIB_DIR=${LOCALBASE}/lib \
		GETTEXT_INCLUDE_DIR=${LOCALBASE}/include \
		RUSTFLAGS="${RUSTFLAGS} -C linker=${CC:Q} ${LDFLAGS:C/.+/-C link-arg=&/}"

post-patch:
# Disable vendor checksums
	@${REINPLACE_CMD} -e 's/"files":{[^}]*}/"files":{}/' \
		${WRKSRC}/vendor/*/.cargo-checksum.json

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fractal

.include <bsd.port.mk>
