PORTNAME=	libsolv
DISTVERSION=	0.7.19
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Package dependency solver using a satisfiability algorithm

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.BSD

USES=		cmake localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	openSUSE

CMAKE_ON=	ENABLE_COMPLEX_DEPS

OPTIONS_DEFINE=			RPMDB RPMMD RPMPKG
OPTIONS_DEFAULT=		RPMDB RPMMD RPMPKG
OPTIONS_GROUP=			COMPRESSION
OPTIONS_GROUP_COMPRESSION=	BZIP2 LZMA ZCHUNK ZSTD
OPTIONS_SUB=			yes

# general options

RPMDB_DESC=			Build with rpm database support
RPMDB_CMAKE_BOOL=		ENABLE_RPMDB
RPMDB_LIB_DEPENDS=		librpmio.so:archivers/rpm4

RPMMD_DESC=			Build with rpmmd repository support
RPMMD_CMAKE_BOOL=		ENABLE_RPMMD
RPMMD_LIB_DEPENDS=		libexpat.so:textproc/expat2

RPMPKG_DESC=			Build with rpm package support
RPMPKG_CMAKE_BOOL=		ENABLE_RPMPKG

# compression options

COMPRESSION_DESC=		Enable compression:

BZIP2_DESC=			BZip2 support
BZIP2_CMAKE_BOOL=		ENABLE_BZIP2_COMPRESSION

LZMA_CMAKE_BOOL=		ENABLE_LZMA_COMPRESSION

ZSTD_CMAKE_BOOL=		ENABLE_ZCHUNK_COMPRESSION
ZSTD_LIB_DEPENDS=		libzstd.so:archivers/zstd

ZCHUNK_DESC=			Zchunk support
ZCHUNK_CMAKE_BOOL=		ENABLE_ZCHUNK_COMPRESSION WITH_SYSTEM_ZCHUNK
ZCHUNK_LIB_DEPENDS=		libzck.so:archivers/zchunk

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRPMDB} || ${PORT_OPTIONS:MRPMMD} || ${PORT_OPTIONS:MRPMPKG}
PLIST_FILES=	include/solv/pool_parserpmrichdep.h
.endif

.include <bsd.port.mk>
