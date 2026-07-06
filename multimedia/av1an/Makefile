PORTNAME=	av1an
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.2
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
TEST_DEPENDS=	ffms2>=0:multimedia/ffms2 \
		mkvmerge:multimedia/mkvtoolnix \
		rav1e:multimedia/rav1e \
		vapoursynth-l-smash-works>=0:multimedia/vapoursynth-l-smash-works \
		x264:multimedia/x264

USES=		cargo llvm localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	rust-av
GH_PROJECT=	Av1an

# XXX https://github.com/rust-lang/cargo/issues/4101
CARGO_INSTALL_PATH=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
