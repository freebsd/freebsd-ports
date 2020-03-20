# Created by: John Hixson <jhixson@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lizardfs
PORTVERSION=	3.12.0
DISTVERSIONPREFIX=	v
PORTREVISION=	10
CATEGORIES=	sysutils

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Open Source Distribruted Filesystem

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_13=	fails to build

BUILD_DEPENDS=	a2x:textproc/asciidoc \
		spdlog>=1.4.2:devel/spdlog
LIB_DEPENDS=	libboost_system.so:devel/boost-libs \
		libfmt.so:devel/libfmt

USES=	cmake compiler:c11 fuse python shebangfix
USE_RC_SUBR=	mfscgiserv \
	mfschunkserver \
	mfsmaster \
	mfsmetalogger \
	mfspingserv

GH_ACCOUNT=	lizardfs

USERS=	mfs
GROUPS=	mfs

SHEBANG_FILES=	src/cgi/cgiserv.py.in \
	src/cgi/lizardfs-cgiserver.py.in \
	src/cgi/mfs.cgi.in \
	src/cgi/chart.cgi.in

USE_GITHUB=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-DSPDLOG_FMT_EXTERNAL=1
LDFLAGS+=	-L${LOCALBASE}/lib -lfmt
CMAKE_BUILD_TYPE=	Release
CMAKE_ARGS=	-DMAN_SUBDIR=man \
	-DENABLE_WERROR=OFF \
	-DENABLE_LIGHTMFS=ON \
	-DENABLE_DEBIAN_PATHS=OFF \
	-DENABLE_UTILS=ON \
	-DENABLE_TESTS=OFF \
	-DENABLE_DOCS=ON \
	-DENABLE_VERBOSE_ASCIIDOC=ON \
	-DENABLE_TCMALLOC=OFF \
	-DENABLE_POLONAISE=OFF \
	-DENABLE_CLIENT_LIB=ON \
	-DENABLE_URAFT=ON \
	-DENABLE_TRACES=OFF \
	-DENABLE_CRC=ON \
	-DENABLE_REQUEST_LOG=OFF \
	-DENABLE_NFS_GANESHA=OFF

.include <bsd.port.mk>
