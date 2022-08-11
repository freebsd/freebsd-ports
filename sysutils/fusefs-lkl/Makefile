PORTNAME=	lkl
DISTVERSION=	4.16.g20180628
PORTREVISION=	3
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	cem@FreeBSD.org
COMMENT=	Full-featured Linux BTRFS, Ext4, XFS as a FUSE module

LICENSE=	GPLv2

BUILD_DEPENDS=	gnubc>0:math/gnubc \
		gnustat:sysutils/coreutils \
		gsed:textproc/gsed

USES=		bison:build fuse gmake python:build shebangfix
SHEBANG_FILES=	../../arch/lkl/scripts/headers_install.py
BINARY_ALIAS=	sed=gsed \
		stat=gnustat
USE_BINUTILS=	yes
USE_GCC=	yes
USE_GITHUB=	yes
GH_PROJECT=	linux
GH_TAGNAME=	86dd3afb590eccc1903611bdaa8bac87757eb80d

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=ld formats not available for other architectures

WRKSRC_SUBDIR=	tools/lkl
MAKE_JOBS_UNSAFE=yes
MAKE_ARGS+=	V=1
# Need ports versions of 'bc', 'ld' to build!
MAKE_ARGS+=	PATH="${LOCALBASE}/bin:${PATH}" CC="${CC}" HOSTCC="${CC}"

PLIST_FILES=	bin/lklfuse lib/liblkl.a

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lklfuse ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/liblkl.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
