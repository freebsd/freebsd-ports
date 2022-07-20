MASTERDIR=	${.CURDIR:H}/mlt6
SLAVEPORT=	python

PORTREVISION=	3
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python bindings for the MLT multimedia framework
CATEGORIES=	multimedia python

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	multi

BUILD_DEPENDS=	swig:devel/swig
LIB_DEPENDS=	libexif.so:graphics/libexif \
		libfftw3.so:math/fftw3

PORTEXAMPLES=	*

USES=		gettext-runtime python:3.6+ shebangfix
USE_PYTHON=	flavors

# Only enable python swig binding, and disable everything else
CMAKE_ON=	SWIG_PYTHON
CMAKE_OFF=	MOD_AVFORMAT MOD_DECKLINK MOD_FEEDS MOD_FREI0R MOD_GDK MOD_GTK2 \
		MOD_JACKRACK MOD_KDENLIVE MOD_LUMAS MOD_MOTION_EST MOD_NORMALIZE \
		MOD_OLDFILM MOD_OPENCV MOD_OPENGL MOD_PLUSGPL MOD_PLUS MOD_RESAMPLE \
		MOD_RTAUDIO MOD_RUBBERBAND MOD_SDL2 MOD_SOX MOD_VIDSTAB MOD_VMFX \
		MOD_VORBIS MOD_XINE MOD_XML \
		SWIG_CSHARP SWIG_JAVA SWIG_LUA SWIG_NODEJS SWIG_PERL \
		SWIG_PHP SWIG_RUBY SWIG_TCL \
		MOD_QT

# Enforce the correct python version
CMAKE_ARGS=	-DPython3_EXECUTABLE="${PYTHON_CMD}"

OPTIONS_DEFINE=	EXAMPLES

SHEBANG_FILES=	src/swig/python/codecs.py \
		src/swig/python/switcher.py \
		src/swig/python/getimage.py \
		src/swig/python/test_animation.py \
		src/swig/python/webvfx_generator.py \
		src/swig/python/play.py \
		src/swig/python/waveforms.py

BUILD_WRKSRC=	${WRKDIR}/.build/src/swig/python

common-post-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -d \
		${PYTHONPREFIX_SITELIBDIR} -f ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d \
		${PYTHONPREFIX_SITELIBDIR} -f ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${PYTHON_VER}
.for f in codecs getimage play switcher waveforms webvfx_generator
	${INSTALL_DATA} ${WRKSRC}/src/swig/python/${f}.py ${STAGEDIR}${EXAMPLESDIR}/${PYTHON_VER}/
.endfor

.include "${MASTERDIR}/Makefile"
