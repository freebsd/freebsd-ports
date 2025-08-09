PORTNAME=	cado-nfs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0-20240408
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of the Number Field Sieve Algorithm
WWW=		https://cado-nfs.gitlabpages.inria.fr/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		bash:shells/bash
LIB_DEPENDS=	libecm.so:math/gmp-ecm \
		libfmt.so:devel/libfmt \
		libgf2x.so:math/gf2x \
		libgmp.so:math/gmp \
		libhwloc.so:devel/hwloc2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		cmake:noninja compiler:c++11-lang gmake perl5 python shebangfix # noninja because: bad $-escape (literal $ must be written as $$)

USE_GITLAB=	yes
GL_SITE=	https://gitlab.inria.fr
GL_TAGNAME=	58d113d3608e41378753cd949b077f7c80449279

SHEBANG_GLOB=	*.py

CXXFLAGS_i386=	-msse2 # workaround for error: always_inline function '_mm_setzero_si128' requires target feature 'sse2', but would be inlined into function 'gf2x_mul4' that is compiled without support for 'sse2'

TEST_TARGET=	check # 'test' does the same but is less verbose

BINARY_ALIAS=	python3=${PYTHON_CMD}

.include <bsd.port.options.mk>

.if ${ARCH} == amd64
PLIST_SUB=	LINGEN_PZ=""
.else
PLIST_SUB=	LINGEN_PZ="@comment "
.endif

.include <bsd.port.mk>
