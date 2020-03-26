# $FreeBSD$

PORTNAME=	vapoursynth
DISTVERSION=	R49
CATEGORIES=	multimedia

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Video processing framework with simplicity in mind

LICENSE=	LGPL21+

USE_GITHUB=	yes

USES=		autoreconf gmake libtool localbase pathfix pkgconfig
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
DATADIR=	${PREFIX}/lib/vapoursynth

OPTIONS_DEFINE=	DEBUG DOCS FRAME_GUARD
OPTIONS_DEFAULT=${OPTIONS_GROUP_COMPS} ${OPTIONS_GROUP_PLUGINS}
OPTIONS_SUB=	yes

OPTIONS_DEFINE_amd64=	SIMD
OPTIONS_DEFINE_i386=	SIMD
OPTIONS_DEFAULT_amd64=	SIMD

OPTIONS_GROUP=		COMPS PLUGINS
COMPS_DESC=		Components
OPTIONS_GROUP_COMPS=	CORE PYTHON VSPIPE VSSCRIPT
PLUGINS_DESC=		Plugins
OPTIONS_GROUP_PLUGINS=	ASS EEDI3 IMAGEMAGICK MISCFILTERS MORPHO TESSERACT \
			REMOVEGRAIN VINVERSE VIVTC

# General options

DEBUG_CONFIGURE_ENABLE=		debug

DOCS_BUILD_DEPENDS=		sphinx-build:textproc/py-sphinx
DOCS_USES=			makeinfo
DOCS_INFO=			VapourSynth
DOCS_PORTDOCS=			*

FRAME_GUARD_DESC=		Check integrity after each filter
FRAME_GUARD_CONFIGURE_ENABLE=	guard-pattern

# VSSCRIPT or REMOVEGRAIN
SIMD_BUILD_DEPENDS=		nasm:devel/nasm
SIMD_CONFIGURE_ENABLE=		x86-asm

# COMPS group

CORE_DESC=			Core library
CORE_BUILD_DEPENDS=		sekrit-twc-zimg>=2.9.3:graphics/sekrit-twc-zimg
CORE_LIB_DEPENDS=		libzimg.so:graphics/sekrit-twc-zimg
CORE_USES=			compiler:c++11-lib
CORE_CONFIGURE_ENABLE=		core

PYTHON_USES=			python:3.3+
PYTHON_USE=			python=cython
PYTHON_VARS=			BINARY_ALIAS=cython=cython-${PYTHON_VER}
PYTHON_CONFIGURE_ENABLE=	python-module
PYTHON_IMPLIES=			CORE

VSPIPE_DESC=			Command line interface
VSPIPE_USES=			compiler:c++11-lib
VSPIPE_CONFIGURE_ENABLE=	vspipe
VSPIPE_IMPLIES=			VSSCRIPT

VSSCRIPT_DESC=			Scripting library
VSSCRIPT_USES=			compiler:c++11-lib python:3.3+
VSSCRIPT_CONFIGURE_ENABLE=	vsscript

# PLUGINS group

ASS_DESC=			Subtitles rendering via libass
ASS_LIB_DEPENDS=		libavcodec.so:multimedia/ffmpeg \
				libass.so:multimedia/libass
ASS_USES=			iconv
ASS_CONFIGURE_ENABLE=		subtext

EEDI3_DESC=			Very slow edge directed interpolation
EEDI3_CONFIGURE_ENABLE=		eedi3

IMAGEMAGICK_LIB_DEPENDS=	libMagick++-7.so:graphics/ImageMagick7
IMAGEMAGICK_USES=		compiler:c++11-lib
IMAGEMAGICK_CONFIGURE_ENABLE=	imwri

TESSERACT_DESC=			Optical Character Recognition via Tesseract
TESSERACT_LIB_DEPENDS=		libtesseract.so:graphics/tesseract
TESSERACT_CONFIGURE_ENABLE=	ocr

MISCFILTERS_DESC=		Miscellaneous filters
MISCFILTERS_CONFIGURE_ENABLE=	miscfilters

MORPHO_DESC=			Morphological filter
MORPHO_CONFIGURE_ENABLE=	morpho

REMOVEGRAIN_DESC=		3x3 median and convolution denoising
REMOVEGRAIN_CONFIGURE_ENABLE=	removegrain

VINVERSE_DESC=			Remove residual combing
VINVERSE_CONFIGURE_ENABLE=	vinverse

VIVTC_DESC=			Field matching, inverse telecine and decimation
VIVTC_CONFIGURE_ENABLE=		vivtc

post-patch:
	@${REINPLACE_CMD} -e 's/x86_64/&|amd64/' \
		-e '/AC_SEARCH.*libiconv/d' \
		-e '/test/s/[^ ]*libiconv.*-a //' \
		${WRKSRC}/configure.ac

post-build-DOCS-on:
	@${DO_MAKE_BUILD} html texinfo -C${WRKSRC}/doc
	@${DO_MAKE_BUILD} info -C${WRKSRC}/doc/_build/texinfo
	@if [ -n "${PORT_OPTIONS:MVSPIPE}" ]; then \
		${DO_MAKE_BUILD} man -C${WRKSRC}/doc; \
	fi

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/doc/_build/texinfo/VapourSynth.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}
	(cd ${WRKSRC}/doc/_build/html && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})
	@if [ -n "${PORT_OPTIONS:MVSPIPE}" ]; then \
		${INSTALL_MAN} -v ${WRKSRC}/doc/_build/man/vspipe.1 \
			${STAGEDIR}${PREFIX}/share/man/man1; \
	fi

.include <bsd.port.mk>
