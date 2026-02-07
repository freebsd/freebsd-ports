PORTNAME=	goldendict-ng
DISTVERSIONPREFIX=	v
DISTVERSION=	26.1.1
DISTVERSIONSUFFIX=	-Release.5491ffca
CATEGORIES=	textproc

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Advanced dictionary lookup program, supporting many formats
WWW=		https://xiaoyifang.github.io/goldendict-ng/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libfmt.so:devel/libfmt \
		libhunspell-1.7.so:textproc/hunspell \
		liblzo2.so:archivers/lzo2 \
		libopencc.so:chinese/opencc \
		libtomlplusplus.so:devel/tomlplusplus \
		libvorbis.so:audio/libvorbis \
		libxapian.so:databases/xapian-core \
		libzim.so:devel/libzim

USES=		cmake compiler:c++17-lang desktop-file-utils gl pkgconfig qt:6 \
		xorg
USE_GITHUB=	yes
GH_ACCOUNT=	xiaoyifang
USE_GL=		opengl
USE_QT=		5compat base declarative multimedia positioning svg webchannel \
		webengine tools:build
USE_XORG=	ice sm x11 xext xorgproto xtst

CMAKE_ON=		USE_ALTERNATIVE_NAME USE_SYSTEM_FMT USE_SYSTEM_TOML
CMAKE_OFF=		WITH_FFMPEG_PLAYER
CONFIGURE_WRKSRC=	${WRKSRC}/build_dir

OPTIONS_DEFINE=		EPWING SPEECH

EPWING_DESC=	Japanese EPWING dictionary format support
SPEECH_DESC=	Text to speech support

EPWING_LIB_DEPENDS=	libeb.so:japanese/eb
EPWING_CMAKE_OFF=	-DWITH_EPWING_SUPPORT=OFF
SPEECH_USE=		QT=speech
SPEECH_CMAKE_ON=	-DWITH_TTS=ON

.include <bsd.port.mk>
