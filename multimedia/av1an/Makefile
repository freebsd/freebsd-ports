PORTNAME=	av1an
DISTVERSION=	0.3.1
PORTREVISION=	10
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	2fc2ea51f2b6.patch:-p1 # https://github.com/master-of-zen/Av1an/pull/557

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

post-patch:
	@${REINPLACE_CMD} -e 's,"llvm-config,&${LLVM_VERSION},' \
		${WRKSRC}/cargo-crates/clang-sys-*/build/common.rs \
		${WRKSRC}/cargo-crates/clang-sys-*/src/support.rs

.include <bsd.port.mk>
