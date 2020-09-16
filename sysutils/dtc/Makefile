# $FreeBSD$

PORTNAME=	dtc
PORTVERSION=	1.6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

PATCH_SITES=	https://github.com/dgibson/dtc/commit/
PATCHFILES+=	ca19c3db2b.patch:-p1 # https://github.com/dgibson/dtc/pull/41

MAINTAINER=	uboot@FreeBSD.org
COMMENT=	Device Tree Compiler

LICENSE=	GPLv2

LIB_DEPENDS=	libyaml.so:textproc/libyaml

USES=		bison compiler:c11 gmake pkgconfig shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	dtdiff

TEST_TARGET=	check
TEST_ENV=	STATSZ="stat -f %Uz"

USE_GITHUB=	yes
GH_ACCOUNT=	dgibson
GH_PROJECT=	dtc

MAKE_ARGS+=	PREFIX=${PREFIX} NO_PYTHON=yes \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_LIB="${INSTALL_LIB}"

.include <bsd.port.mk>
