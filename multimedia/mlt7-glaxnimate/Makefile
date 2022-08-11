MASTERDIR=	${.CURDIR:H}/mlt7
SLAVEPORT=	glaxnimate

PORTREVISION=	0
PKGNAMESUFFIX=	-glaxnimate

COMMENT=	2D animations plugin for the MLT multimedia framework
CATEGORIES=	multimedia kde

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	multi

LIB_DEPENDS=	libexif.so:graphics/libexif \
		libfftw3.so:math/fftw3

USES=		qt:5 xorg
USE_CXXSTD=	c++11
USE_QT=		core gui svg widgets xml \
		buildtools_build qmake_build
USE_XORG=	x11

# Only enable Qt binding, and disable everything else
CMAKE_ON=	MOD_GLAXNIMATE
CMAKE_OFF=	MOD_AVFORMAT MOD_DECKLINK MOD_FEEDS MOD_FREI0R MOD_GDK MOD_GTK2 \
		MOD_JACKRACK MOD_KDENLIVE MOD_LUMAS MOD_MOTION_EST MOD_NORMALIZE \
		MOD_OLDFILM MOD_OPENCV MOD_OPENGL MOD_PLUSGPL MOD_PLUS MOD_QT MOD_RESAMPLE \
		MOD_RTAUDIO MOD_RUBBERBAND MOD_SDL2 MOD_SOX MOD_VIDSTAB MOD_VMFX \
		MOD_VORBIS MOD_XINE MOD_XML \
		SWIG_CSHARP SWIG_JAVA SWIG_LUA SWIG_NODEJS SWIG_PERL \
		SWIG_PHP SWIG_PYTHON SWIG_RUBY SWIG_TCL

BUILD_WRKSRC=	${WRKDIR}/.build/src/modules/glaxnimate

# Dummy placeholder target.
common-post-install:
	@${TRUE}

.include "${MASTERDIR}/Makefile"
