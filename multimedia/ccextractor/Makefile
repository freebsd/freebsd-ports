PORTREVISION=	2

COMMENT=	Subtitle extractor

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libgpac.so:multimedia/gpac-libgpac \
		libpng.so:graphics/png \
		libprotobuf-c.so:devel/protobuf-c \
		libutf8proc.so:textproc/utf8proc

ALL_TARGET=	ccextractor
CFLAGS+=	-I${LOCALBASE}/include/freetype2 \
		-I${LOCALBASE}/include/protobuf-c
LIBS+=		-lfreetype -lgpac -lmd -lpng -lprotobuf-c -lutf8proc -lz

# OCR broken with leptonica >= 1.83
# probably fixed in next version
OPTIONS_DEFINE=	HARDSUBX OCR RUST
OPTIONS_DEFAULT=	RUST
HARDSUBX_DESC=	Extraction of burnt subtitles (hard subtitles)
OCR_DESC=	Optical Character Recognition
RUST_DESC=	Build Rust-based components

HARDSUBX_IMPLIES=	OCR
HARDSUBX_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg4
HARDSUBX_CONFIGURE_ENABLE=	ffmpeg hardsubx
HARDSUBX_CFLAGS=	-I${LOCALBASE}/ffmpeg4/include
HARDSUBX_LDFLAGS=	-L${LOCALBASE}/ffmpeg4/lib

OCR_LIB_DEPENDS=	libtesseract.so:graphics/tesseract \
		libleptonica.so:graphics/leptonica \
		libarchive.so:archivers/libarchive \
		libcurl.so:ftp/curl
OCR_CONFIGURE_ENABLE=	ocr

RUST_USES=	cargo llvm
RUST_CONFIGURE_WITH=	rust
CARGO_SRC_SUBDIR=	../src/rust
CARGO_TARGET_DIR=	${WRKSRC}/rust

.include "Makefile.master"
