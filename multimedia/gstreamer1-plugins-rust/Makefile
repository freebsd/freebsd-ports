PORTNAME=	gstreamer1-plugins-rust
DISTVERSION=	0.8.4
PORTREVISION=	1
CATEGORIES=	multimedia

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	6da4192fe62c.patch:-p1 # https://gitlab.freedesktop.org/gstreamer/gst-plugins-rs/-/merge_requests/910

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Various GStreamer plugins written in Rust
WWW=		https://gitlab.freedesktop.org/gstreamer/gst-plugins-rs

LICENSE=	LGPL21+ MIT
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT
LICENSE_FILE_LGPL21+ =	${WRKSRC}/LICENSE-LGPLv2

BUILD_DEPENDS=	cargo-cbuild:devel/cargo-c

USES=		cargo gnome gstreamer meson pkgconfig ssl
USE_GITLAB=	yes
USE_GNOME=	glib20
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	gstreamer
GL_PROJECT=	gst-plugins-rs
GL_COMMIT=	18c9bd0355e0fc1ab20072d805807112945ad5bb
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

OPTIONS_DEFINE=	CAIRO CSOUND DAV1D GTK4 PANGO SODIUM
OPTIONS_DEFAULT=CAIRO CSOUND DAV1D GTK4 PANGO SODIUM
OPTIONS_EXCLUDE_aarch64=	CSOUND # https://github.com/neithanmo/csound-rs/commit/8962b89d7bda
OPTIONS_EXCLUDE_armv7=	CSOUND # https://github.com/neithanmo/csound-rs/commit/8962b89d7bda
OPTIONS_EXCLUDE_powerpc64le=	CSOUND
OPTIONS_EXCLUDE_powerpc64=	CSOUND
OPTIONS_EXCLUDE_powerpc=	CSOUND DAV1D
OPTIONS_SUB=	yes

CAIRO_USE=		GNOME=cairo
CAIRO_MESON_ENABLED=	videofx

CSOUND_DESC=		Audio filtering via Csound
CSOUND_LIB_DEPENDS=	libcsound64.so:audio/csound
CSOUND_CONFIGURE_ENV=	CSOUND_LIB_DIR="${LOCALBASE}/lib"
CSOUND_MESON_ENABLED=	csound

DAV1D_DESC=		AV1 video decoding via libdav1d
DAV1D_BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
DAV1D_LIB_DEPENDS=	libdav1d.so:multimedia/dav1d
DAV1D_MESON_ENABLED=	dav1d

GTK4_DESC=		${GTK3_DESC:S/3/4/}
GTK4_LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene
GTK4_USE=		GNOME=gtk40
GTK4_MESON_ENABLED=	gtk4

PANGO_USE=		GNOME=cairo,pango
PANGO_MESON_ENABLED=	closedcaption

SODIUM_DESC=		File encryption and decryption via libsodium
SODIUM_LIB_DEPENDS=	libsodium.so:security/libsodium
SODIUM_MESON_ON=	-Dsodium=system
SODIUM_MESON_OFF=	-Dsodium=disabled

post-patch:
	@${REINPLACE_CMD} -e 's,"llvm-config,&${LLVM_DEFAULT},' \
		${WRKSRC}/cargo-crates/clang-sys-*/build/common.rs \
		${WRKSRC}/cargo-crates/clang-sys-*/src/support.rs
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e "/'cargo'/s/]/, '--verbose', '--verbose'&/" \
		${WRKSRC}/cargo_wrapper.py

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gstreamer-1.0/*.so

.include <bsd.port.mk>
