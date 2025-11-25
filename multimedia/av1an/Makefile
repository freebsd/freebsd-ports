PORTNAME=	av1an
DISTVERSION=	0.5.0
CATEGORIES=	multimedia

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line encoding framework with per scene quality
WWW=		https://github.com/rust-av/Av1an

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${BUILD_DEPENDS_${ARCH}}
BUILD_DEPENDS_amd64=	nasm:devel/nasm
LIB_DEPENDS=	libavformat.so:multimedia/ffmpeg \
		libvapoursynth-script.so:multimedia/vapoursynth

USES=		cargo llvm localbase:ldflags
USE_GITHUB=	yes
GH_TAGNAME=	0.5
GH_ACCOUNT=	rust-av
GH_PROJECT=	Av1an
PLIST_FILES=	bin/${PORTNAME}

# XXX https://github.com/rust-lang/cargo/issues/4101
CARGO_INSTALL_PATH=	${PORTNAME}

.include <bsd.port.mk>
