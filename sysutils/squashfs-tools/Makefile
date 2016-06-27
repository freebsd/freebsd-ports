# Created by: Ashish SHUKLA <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	squashfs-tools
PORTVERSION=	4.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/squashfs/squashfs/${DISTNAME}/
DISTNAME=	squashfs${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Set of tools to manipulate squashfs images

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

PLIST_FILES=	bin/mksquashfs \
		bin/unsquashfs

OPTIONS_DEFINE=	XZ LZO LZMA DOCS
OPTIONS_DEFAULT=	XZ LZO LZMA
XZ_DESC=	Build with XZ support
LZO_DESC=	Build with LZO support
LZMA_DESC=	Build with LZMA support

WRKSRC=		${WRKDIR}/${DISTNAME}/squashfs-tools

USE_CSTD=	gnu89

USES=		alias cpe gmake
CPE_PRODUCT=	squashfs
CPE_VENDOR=	phillip_lougher

.include <bsd.port.options.mk>

PORTDOCS=	ACKNOWLEDGEMENTS CHANGES COPYING \
		PERFORMANCE.README README README-${PORTVERSION}

.if ${PORT_OPTIONS:MXZ}
MAKE_ARGS+=	XZ_SUPPORT=1
.endif

.if ${PORT_OPTIONS:MLZO}
MAKE_ARGS+=	LZO_SUPPORT=1 LZO_DIR=${LOCALBASE}
LIB_DEPENDS+=	liblzo2.so:archivers/lzo2
.endif

.if ${PORT_OPTIONS:MLZMA}
MASTER_SITES+=	SF/sevenzip/LZMA%20SDK/:lzma
DISTFILES+=	lzma922.tar.bz2:lzma
MAKE_ARGS+=	LZMA_SUPPORT=1 LZMA_DIR=${WRKDIR} EXTRA_CFLAGS="-D_7ZIP_ST"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|^\(XATTR\)|# \1|g" \
		${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC:H}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
