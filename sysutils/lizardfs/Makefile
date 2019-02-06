# Created by: John Hixson <jhixson@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lizardfs
PORTVERSION=	3.12.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	Open Source Distribruted Filesystem

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	a2x:textproc/asciidoc \
	spdlog>=1.3.0:devel/spdlog
LIB_DEPENDS=	libboost_system.so:devel/boost-libs

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
