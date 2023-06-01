PORTNAME=	squashfs-tools
PORTVERSION=	4.6.1
CATEGORIES=	sysutils
MASTER_SITES=	SF/squashfs/squashfs/squashfs${PORTVERSION}
DISTFILES=	squashfs${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Set of tools to manipulate squashfs images
WWW=		https://squashfs.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

BUILD_DEPENDS=	gsed:textproc/gsed help2man:misc/help2man

USES=		alias cpe gmake
BINARY_ALIAS=	sed=gsed

PLIST_FILES=	bin/mksquashfs bin/sqfscat bin/sqfstar bin/unsquashfs \
		man/man1/mksquashfs.1.gz man/man1/sqfscat.1.gz \
		man/man1/sqfstar.1.gz man/man1/unsquashfs.1.gz

OPTIONS_DEFINE=	DOCS LZ4 LZMA LZO XZ ZSTD
OPTIONS_DEFAULT=	LZ4 LZMA LZO XZ ZSTD
LZMA_DESC=	LZMA1 compression support (obsolete)
XZ_DESC=	XZ (LZMA2) compression support

WRKSRC=		${WRKDIR}/${DISTNAME}/squashfs-tools

CPE_PRODUCT=	squashfs
CPE_VENDOR=	squashfs_project

PORTDOCS=	ACKNOWLEDGEMENTS ACTIONS-README CHANGES \
		README-${PORTVERSION} TECHNICAL-INFO USAGE-* \
		pseudo-file.example

LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_MAKE_ARGS=	LZ4_SUPPORT=1

LZMA_MASTER_SITES=	SF/sevenzip/LZMA%20SDK/:lzma
LZMA_DISTFILES=	lzma922.tar.bz2:lzma
LZMA_MAKE_ARGS=	LZMA_SUPPORT=1 LZMA_DIR=${WRKDIR} EXTRA_CFLAGS=-D_7ZIP_ST

LZO_LIB_DEPENDS=	liblzo2.so:archivers/lzo2
LZO_MAKE_ARGS=	LZO_SUPPORT=1 LZO_LIBDIR=-L${LOCALBASE}/lib

XZ_MAKE_ARGS=	XZ_SUPPORT=1

ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_MAKE_ARGS=	ZSTD_SUPPORT=1

post-patch:
	@${REINPLACE_CMD} -e '/^#include "squashfs_fs\.h"/ { x; \
		s,^,typedef struct __sFILE FILE;,; G; }' \
			${WRKSRC}/lzma_wrapper.c

post-install:
	@${LN} -f ${WRKSRC:H}/examples/pseudo-file.example ${WRKSRC:H}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC:H}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
