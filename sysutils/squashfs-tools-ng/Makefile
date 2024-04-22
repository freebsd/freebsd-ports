PORTNAME=	squashfs-tools-ng
PORTVERSION=	1.3.0
CATEGORIES=	sysutils
MASTER_SITES=	https://infraroot.at/pub/squashfs/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	New set of tools and libraries to work with SquashFS images
WWW=		https://infraroot.at/projects/squashfs-tools-ng/

LICENSE=	GPLv3+ LGPL3+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/COPYING.md

USES=		libtool pkgconfig tar:xz
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS LZ4 LZO TOOLS ZSTD
OPTIONS_DEFAULT=	LZ4 LZO TOOLS ZSTD
OPTIONS_SUB=	yes
TOOLS_DESC=	Build the tools, not just the library

LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_CONFIGURE_OFF=	--without-lz4

LZO_LIB_DEPENDS=	liblzo2.so:archivers/lzo2
LZO_CONFIGURE_ENV=	LZO_CFLAGS="-I${LOCALBASE}/include" \
			LZO_LIBS="-L${LOCALBASE}/lib -llzo2"
LZO_CONFIGURE_OFF=	--without-lzo

TOOLS_CONFIGURE_OFF=	--without-tools

ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_CONFIGURE_OFF=	--without-zstd

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${WRKSRC}/README.md \
		${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
