PORTNAME=	wl-screenrec
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.5 # see PORTSCOUT comment below
PORTREVISION=	11
CATEGORIES=	multimedia wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High performance wlroots screen recording, featuring hardware encoding
WWW=		https://github.com/russelltg/wl-screenrec

LICENSE=	APACHE20

BROKEN_i386=	https://github.com/zmwangx/rust-ffmpeg-sys/issues/96

LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libavformat.so:multimedia/ffmpeg

USES=		cargo llvm
USE_GITHUB=	yes
GH_ACCOUNT=	russelltg
PLIST_FILES=	bin/${PORTNAME} \
		share/bash-completion/completions/${PORTNAME} \
		share/fish/vendor_completions.d/${PORTNAME}.fish \
		share/zsh/site-functions/_${PORTNAME}

# https://github.com/russelltg/wl-screenrec/issues/99
PORTSCOUT=	ignore:1

post-patch:
	@${REINPLACE_CMD} -e 's,"llvm-config,"${LLVM_CONFIG},' \
		${WRKSRC_crate_clang-sys}/build/common.rs \
		${WRKSRC_crate_clang-sys}/src/support.rs

post-install:
.for _shell in bash fish zsh
	@${ECHO_MSG} "Generating ${STAGEDIR}${PREFIX}/${PLIST_FILES:M*${_shell}*}"
	${CARGO_TARGET_DIR}/*/${PORTNAME} \
		--generate-completions ${_shell} \
		>${STAGEDIR}${PREFIX}/${PLIST_FILES:M*${_shell}*}
.endfor

.include <bsd.port.mk>
