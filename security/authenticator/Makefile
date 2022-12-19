PORTNAME=	authenticator
DISTVERSION=	4.1.6
PORTREVISION=	3
CATEGORIES=	security

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Generate Two-Factor Codes
WWW=		https://gitlab.gnome.org/World/Authenticator

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}
LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene \
		libzbar.so:graphics/zbar \
		libpipewire-0.3.so:multimedia/pipewire
RUN_DEPENDS=	${LOCALBASE}/lib/gstreamer-1.0/libgstgtk4.so:multimedia/gstreamer1-plugins-rust

USES=		cargo desktop-file-utils gettext gnome gstreamer meson pkgconfig sqlite ssl
USE_GITLAB=	yes
USE_GNOME=	gdkpixbuf2 gtk40 libadwaita
USE_GSTREAMER=	zbar
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_PROJECT=	Authenticator
GL_COMMIT=	fc8624342b3b4aa599b4efdefdda84514c223b18
CARGO_ENV=	ZBAR_INCLUDE_DIRS="${LOCALBASE}/include" ZBAR_LIB_DIRS="${LOCALBASE}/lib"
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
GLIB_SCHEMAS=	com.belmoussaoui.Authenticator.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's,"llvm-config,&${LLVM_DEFAULT},' \
		${WRKSRC}/cargo-crates/clang-sys-*/build/common.rs \
		${WRKSRC}/cargo-crates/clang-sys-*/src/support.rs
	@${REINPLACE_CMD} -e '/gstreamer.*bad/d' \
		${WRKSRC}/meson.build
# Make each cargo subcommand very verbose
# Add explicit <triple> subdir for --target from USES=cargo
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		-e "/cp/s,'src',& / '${CARGO_BUILD_TARGET}'," \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
