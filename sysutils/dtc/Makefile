PORTNAME=	dtc
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.1
CATEGORIES=	sysutils

PATCH_SITES=	https://github.com/dgibson/dtc/commit/
PATCHFILES=	1b75550436433e150164715dedb417e4d234df6c.patch:-p1

MAINTAINER=	uboot@FreeBSD.org
COMMENT=	Device Tree Compiler
WWW=		https://git.kernel.org/cgit/utils/dtc/dtc.git

LICENSE=	GPLv2

LIB_DEPENDS=	libyaml.so:textproc/libyaml

USES=		bison compiler:c11 cpe meson pkgconfig shebangfix
CPE_VENDOR=	${PORTNAME}_project
SHEBANG_FILES=	dtdiff
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dgibson

MESON_ARGS=	--default-library=shared \
		-Dpython=disabled \
		-Dvalgrind=disabled

OPTIONS_DEFINE=		TEST

TEST_MESON_TRUE=	tests

.include <bsd.port.mk>
