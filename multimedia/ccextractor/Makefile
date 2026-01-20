PORTNAME=	ccextractor
DISTVERSION=	0.96.5
CATEGORIES=	multimedia converters
MASTER_SITES=	https://github.com/CCExtractor/ccextractor/releases/download/v${DISTVERSION}/:master
DISTFILES=	ccextractor.${DISTVERSION}.tar.gz:master

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Subtitle extractor
WWW=		https://ccextractor.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgpac.so:multimedia/gpac \
		libpng.so:graphics/png \
		libprotobuf-c.so:devel/protobuf-c \
		libutf8proc.so:textproc/utf8proc
RUN_DEPENDS=	${LOCALBASE}/share/fonts/noto/NotoSans-Regular.ttf:x11-fonts/noto-sans

USES=		autoreconf cargo iconv localbase:ldflags llvm pkgconfig

GNU_CONFIGURE=	yes
ALL_TARGET=	ccextractor
CFLAGS+=	-fcommon -DUNIX \
		-I${LOCALBASE}/include/freetype2 \
		-I${LOCALBASE}/include/protobuf-c \
		-I${ICONV_INCLUDE_PATH}
LIBS+=		-lfreetype -lgpac -lmd -lpng -lprotobuf-c -lutf8proc -lz ${ICONV_LIB}
CARGO_SRC_SUBDIR=	../src/rust
CARGO_TARGET_DIR=	${WRKSRC}/rust

PATCH_WRKSRC=	${WRKDIR}/ccextractor
WRKSRC=		${PATCH_WRKSRC}/linux
PLIST_FILES=	bin/${ALL_TARGET}

OPTIONS_DEFINE=	HARDSUBX OCR
OPTIONS_DEFAULT=	HARDSUBX OCR
HARDSUBX_DESC=	Extraction of burnt subtitles (hard subtitles)
OCR_DESC=	Optical Character Recognition

HARDSUBX_IMPLIES=	OCR
HARDSUBX_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
HARDSUBX_CONFIGURE_ENABLE=	ffmpeg hardsubx
HARDSUBX_VARS=	CARGO_FEATURES+=hardsubx_ocr

OCR_LIB_DEPENDS=	libtesseract.so:graphics/tesseract \
		libleptonica.so:graphics/leptonica \
		libarchive.so:archivers/libarchive \
		libcurl.so:ftp/curl
OCR_CONFIGURE_ENABLE=	ocr

.include <bsd.port.options.mk>

# ensure we do not bundle any dependencies by accident
post-extract:
	${RM} -r ${PATCH_WRKSRC}/src/thirdparty

pre-configure:
	${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},' \
		${PATCH_WRKSRC}/src/lib_ccx/params.c

pre-build:
	(cd ${WRKSRC}/../src/lib_ccx && \
	echo "#ifndef CCX_CCEXTRACTOR_COMPILE_REAL_H" >compile_info_real.h ;\
	echo "#define CCX_CCEXTRACTOR_COMPILE_REAL_H" >>compile_info_real.h ;\
	echo "#define GIT_COMMIT \"${PKGVERSION} (FreeBSD ports)\"" >>compile_info_real.h ;\
	echo "#define COMPILE_DATE \"$$(date -u +%Y-%m-%d)\"" >>compile_info_real.h ;\
	echo "#endif" >>compile_info_real.h)
	${CARGO_CARGO_RUN} build \
		--manifest-path ${CARGO_CARGOTOML} \
		--verbose \
		--verbose \
		${CARGO_BUILD_ARGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${ALL_TARGET} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
