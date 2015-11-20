# Created by: Conrad Meyer <cem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lkl
PORTVERSION=	4.3.0
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	cem@FreeBSD.org
COMMENT=	Full-featured Linux BTRFS, Ext4, XFS as a FUSE module

LICENSE=	GPLv2

BUILD_DEPENDS+=	gnubc>0:${PORTSDIR}/math/gnubc
LIB_DEPENDS+=	libfuse.so:${PORTSDIR}/sysutils/fusefs-libs

USES=		fuse gmake
USE_BINUTILS=	yes
USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	lkl
GH_PROJECT=	linux
GH_TAGNAME=	64a367f522c6ec4fbed0193589d7733b06ab7968

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=No one has added other architecture ld formats yet

WRKSRC_SUBDIR=	tools/lkl
ALL_TARGET=	lklfuse
MAKE_JOBS_UNSAFE=yes
MAKE_ARGS+=	V=1

PLIST_FILES=	bin/lklfuse lib/liblkl.a

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lklfuse ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/liblkl.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
