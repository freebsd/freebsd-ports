PORTNAME=	wl-screenrec
PORTVERSION=	s20230709
CATEGORIES=	multimedia wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	High performance wlroots screen recording, featuring hardware encoding
WWW=		https://github.com/russelltg/wl-screenrec

LICENSE=	APACHE20

LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg

USES=		cargo llvm
USE_GITHUB=	yes
GH_ACCOUNT=	russelltg
GH_TAGNAME=	2d66770
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's,"llvm-config,"${LLVM_CONFIG},' \
		${WRKSRC_crate_clang-sys}/build/common.rs \
		${WRKSRC_crate_clang-sys}/src/support.rs

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
