PORTNAME=	helvum
DISTVERSION=	0.4.0
PORTREVISION=	5
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GTK patchbay for PipeWire
WWW=		https://gitlab.freedesktop.org/ryuukyu/helvum

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgraphene-1.0.so:graphics/graphene \
		libpipewire-0.3.so:multimedia/pipewire

USES=		cargo desktop-file-utils gnome llvm meson pkgconfig
USE_GITLAB=	yes
USE_GNOME=	cairo gtk40
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	ryuukyu
GL_COMMIT=	69257ffa09e9ac844d22d85e288b97ac98b37665
MAKE_ENV=	${CARGO_ENV}
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's,"llvm-config,"${LLVM_CONFIG},' \
		${WRKSRC_crate_clang-sys}/build/common.rs \
		${WRKSRC_crate_clang-sys}/src/support.rs
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		${WRKSRC}/src/meson.build

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD || ${OSVERSION} < 1300134
LIB_DEPENDS+=	libepoll-shim.so:devel/libepoll-shim
LDFLAGS+=	-lepoll-shim
.endif

.include <bsd.port.mk>
