# Created by: Conrad Meyer <cem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lkl
DISTVERSIONPREFIX=	v
DISTVERSION=	4.8-493
PORTREVISION=	3
DISTVERSIONSUFFIX=	-g4b77c32b1a88
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	cem@FreeBSD.org
COMMENT=	Full-featured Linux BTRFS, Ext4, XFS as a FUSE module

LICENSE=	GPLv2

BUILD_DEPENDS=	gnubc>0:math/gnubc

USES=		fuse gmake python:build shebangfix
SHEBANG_FILES=	../../arch/lkl/scripts/headers_install.py
USE_BINUTILS=	yes
USE_GCC=	yes
USE_GITHUB=	yes
GH_PROJECT=	linux

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=No one has added other architecture ld formats yet

IGNORE_FreeBSD_10=	requires FreeBSD 11 or newer

WRKSRC_SUBDIR=	tools/lkl
ALL_TARGET=	lklfuse
MAKE_JOBS_UNSAFE=yes
MAKE_ARGS+=	V=1
# Need ports versions of 'bc', 'ld' to build!
MAKE_ARGS+=	PATH="${LOCALBASE}/bin:${PATH}" CC="${CC}" HOSTCC="${CC}"

PLIST_FILES=	bin/lklfuse lib/liblkl.a

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lklfuse ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/liblkl.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
