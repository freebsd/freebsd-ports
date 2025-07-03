PORTNAME=	av1an
DISTVERSION=	0.4.4
PORTREVISION=	5
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Command-line encoding framework with per scene quality
WWW=		https://github.com/master-of-zen/Av1an

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm
LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libvapoursynth-script.so:multimedia/vapoursynth

USES=		cargo llvm
USE_GITHUB=	yes
GH_ACCOUNT=	master-of-zen
GH_PROJECT=	Av1an
PLIST_FILES=	bin/${PORTNAME}

# XXX https://github.com/rust-lang/cargo/issues/4101
CARGO_INSTALL_PATH=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's,"llvm-config,"${LLVM_CONFIG},' \
		${WRKSRC_crate_clang-sys}/build/common.rs \
		${WRKSRC_crate_clang-sys}/src/support.rs

.include <bsd.port.mk>
