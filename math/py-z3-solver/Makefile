PORTNAME=	z3-solver
DISTVERSIONPREFIX=	z3-
DISTVERSION=	4.8.17
CATEGORIES=	math
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python binding for Z3 Theorem Prover

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../../../LICENSE.txt

BROKEN_riscv64=	fails to configure, see https://github.com/Z3Prover/z3/issues/6183

BUILD_DEPENDS=	cmake:devel/cmake

USES=		compiler:c++11-lang python:3.6+
USE_PYTHON=	distutils autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	Z3Prover
GH_PROJECT=	z3

CFLAGS_armv7=	-fPIC
CFLAGS_powerpc=	-fPIC

WRKSRC_SUBDIR=	src/api/python

# CAVEAT: There should have LIB_DEPENDS=libz3.so:math/z3, but currently it rebuilds all code, see https://github.com/Z3Prover/z3/issues/1767

post-patch: # https://github.com/Z3Prover/z3/issues/2131
	@${REINPLACE_CMD} 's|…|...|' ${WRKSRC}/../../ast/recfun_decl_plugin.h

.include <bsd.port.mk>
