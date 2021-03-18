# Created by: Ashish SHUKLA <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	squashfs-tools
PORTVERSION=	4.4
CATEGORIES=	sysutils
MASTER_SITES=	SF/squashfs/squashfs/${DISTNAME}/
DISTNAME=	squashfs${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Set of tools to manipulate squashfs images

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

USES=		alias cpe gmake

PLIST_FILES=	bin/mksquashfs \
		bin/unsquashfs

OPTIONS_DEFINE=	DOCS LZ4 LZMA LZO XZ ZSTD
OPTIONS_DEFAULT=	LZ4 LZMA LZO XZ ZSTD
LZMA_DESC=	LZMA1 compression support (obsolete)
XZ_DESC=	XZ (LZMA2) compression support

WRKSRC=		${WRKDIR}/${DISTNAME}/squashfs-tools

CPE_PRODUCT=	squashfs
CPE_VENDOR=	phillip_lougher

USE_CSTD=	gnu89

# Fix build with clang11
CFLAGS+=	-fcommon

PORTDOCS=	ACKNOWLEDGEMENTS CHANGES README-${PORTVERSION} USAGE \
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

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC:H}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
