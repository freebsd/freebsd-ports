PORTNAME=	gstreamer1-plugins-rust
DISTVERSION=	${gst-rust_VERSION}
PORTREVISION=	1
CATEGORIES=	multimedia

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Various GStreamer plugins written in Rust
WWW=		https://gitlab.freedesktop.org/gstreamer/gst-plugins-rs

LICENSE=		APACHE20 LGPL21+ MIT MPL20
LICENSE_COMB=		multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_LGPL21+ =	${WRKSRC}/LICENSE-LGPLv2
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_MPL20=	${WRKSRC}/LICENSE-MPL-2.0

BUILD_DEPENDS=	cargo-cbuild:devel/cargo-c \
		${PY_TOMLI}

USES=		cargo gnome gstreamer meson pkgconfig python:build shebangfix ssl
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	gstreamer
GL_PROJECT=	gst-plugins-rs
USE_GNOME=	glib20
USE_GSTREAMER=	webrtc

SHEBANG_FILES=	dependencies.py

MESON_ARGS=	-Ddoc=disabled -Dskia=disabled
# vvdec support requires multimedia/vvdec version 3.0.0 or higher, which is not
# in the ports tree as of time of writing (2025-08-02).
MESON_ARGS+=	-Dvvdec=disabled

CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

MAKE_ENV=	${CARGO_ENV}

.if ${MACHINE_ARCH} == i386 || "${MACHINE_ARCH:Marmv?}" != ""
# https://github.com/rust-lang/rust/issues/85598
LTO_UNSAFE=	yes
CARGO_ENV+=	CARGO_PROFILE_RELEASE_LTO=false
.endif

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=		ASM CAIRO CSOUND DAV1D GTK4 PANGO SODIUM WEBP
OPTIONS_DEFAULT=	ASM CAIRO CSOUND DAV1D GTK4 PANGO SODIUM WEBP
OPTIONS_EXCLUDE_aarch64=	CSOUND # https://github.com/neithanmo/csound-rs/commit/8962b89d7bda
OPTIONS_EXCLUDE_armv7=		CSOUND # https://github.com/neithanmo/csound-rs/commit/8962b89d7bda
OPTIONS_EXCLUDE_powerpc=	CSOUND DAV1D
OPTIONS_EXCLUDE_powerpc64=	CSOUND
OPTIONS_EXCLUDE_powerpc64le=	CSOUND
OPTIONS_SUB=		yes

ASM_BUILD_DEPENDS=	nasm:devel/nasm

CAIRO_USE=		GNOME=cairo
CAIRO_MESON_ENABLED=	videofx

CSOUND_DESC=		Audio filtering via Csound
CSOUND_LIB_DEPENDS=	libcsound64.so:audio/csound
CSOUND_CONFIGURE_ENV=	CSOUND_LIB_DIR="${LOCALBASE}/lib"
CSOUND_MESON_ENABLED=	csound

DAV1D_DESC=		AV1 video decoding via libdav1d
DAV1D_LIB_DEPENDS=	libdav1d.so:multimedia/dav1d
DAV1D_MESON_ENABLED=	dav1d

GTK4_LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene
GTK4_USE=		GNOME=gtk40 GSTREAMER=gl
GTK4_MESON_ENABLED=	gtk4

PANGO_USE=		GNOME=cairo,pango
PANGO_MESON_ENABLED=	closedcaption onvif

SODIUM_DESC=		File encryption and decryption via libsodium
SODIUM_LIB_DEPENDS=	libsodium.so:security/libsodium
SODIUM_MESON_ENABLED=	sodium
SODIUM_MESON_ON=	-Dsodium-source=system

WEBP_LIB_DEPENDS=	libwebpdemux.so:graphics/webp
WEBP_MESON_ENABLED=	webp

post-patch:
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -Ee "/cargo.*'c?(build|test)'/s/]/, '--verbose', '--verbose'&/" \
		${WRKSRC}/cargo_wrapper.py

.include <bsd.port.mk>
