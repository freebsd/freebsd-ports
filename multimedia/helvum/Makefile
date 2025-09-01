PORTNAME=	helvum
DISTVERSION=	0.5.1
PORTREVISION=	18
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK patchbay for PipeWire
WWW=		https://gitlab.freedesktop.org/ryuukyu/helvum

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene \
		libpipewire-0.3.so:multimedia/pipewire

USES=		cargo gnome llvm meson pkgconfig
USE_GITLAB=	yes
USE_GNOME=	cairo gtk40 libadwaita
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	ryuukyu
MAKE_ENV=	${CARGO_ENV}
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/org.pipewire.Helvum.desktop \
		share/icons/hicolor/scalable/apps/org.pipewire.Helvum.svg \
		share/icons/hicolor/symbolic/apps/org.pipewire.Helvum-symbolic.svg \
		share/metainfo/org.pipewire.Helvum.metainfo.xml

post-patch:
	@${REINPLACE_CMD} -e 's,"llvm-config,"${LLVM_CONFIG},' \
		${WRKSRC_crate_clang-sys}/build/common.rs \
		${WRKSRC_crate_clang-sys}/src/support.rs
	@${REINPLACE_CMD} -e '/update_desktop_database/d' \
		${WRKSRC}/meson.build
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
