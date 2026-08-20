PORTNAME=	rshim-user-space
DISTVERSION=	2.8.5
PORTEPOCH=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/Mellanox/${PORTNAME}/releases/download/rshim-${DISTVERSION}/
DISTNAME=	rshim-src-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Userspace daemon for the Mellanox BlueField SoC
WWW=		https://github.com/Mellanox/rshim-user-space/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libepoll-shim-interpose.so:devel/libepoll-shim \
		libpci.so:devel/libpci
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf compiler:c11 pkgconfig python:build,run shebangfix

SHEBANG_FILES=	scripts/bf-pldm-ver \
		scripts/bfb-install \
		scripts/bfb-tool \
		scripts/mlx-mkbfb \
		third_party/PLDM-unpack/fwpkg_unpack.py

GNU_CONFIGURE=	yes

NO_WRKSUBDIR=	yes

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD || !exists(/usr/lib/libcuse.so)
IGNORE=		not supported on this operating system combination
.endif

.include <bsd.port.mk>
