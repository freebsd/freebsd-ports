PORTNAME=	wl-screenrec
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	multimedia wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	High performance wlroots screen recording, featuring hardware encoding
WWW=		https://github.com/russelltg/wl-screenrec

LICENSE=	APACHE20

LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libavformat.so:multimedia/ffmpeg

USES=		cargo llvm
USE_GITHUB=	yes
GH_ACCOUNT=	russelltg
PLIST_FILES=	bin/${PORTNAME}

post-patch:
# Extract (snapshot) version from the port instead of Cargo.toml
	@${REINPLACE_CMD} -i .nogit -e '/^version/s/0\.1\.0/&-${DISTVERSION}-g${GH_TAGNAME}/' \
		${WRKSRC}/Cargo.toml
	@${REINPLACE_CMD} -e 's,"llvm-config,"${LLVM_CONFIG},' \
		${WRKSRC_crate_clang-sys}/build/common.rs \
		${WRKSRC_crate_clang-sys}/src/support.rs

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
