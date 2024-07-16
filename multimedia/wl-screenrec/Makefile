PORTNAME=	wl-screenrec
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.4
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
	@${REINPLACE_CMD} -e 's,"llvm-config,"${LLVM_CONFIG},' \
		${WRKSRC_crate_clang-sys}/build/common.rs \
		${WRKSRC_crate_clang-sys}/src/support.rs

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
