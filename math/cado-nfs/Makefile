PORTNAME=	cado-nfs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0.20220722
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of the Number Field Sieve Algorithm

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_BUILD=	libfmt # bundled libfmt conflicts with package-installed headers

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		bash:shells/bash \
		gmake:devel/gmake
LIB_DEPENDS=	libecm.so:math/gmp-ecm \
		libgf2x.so:math/gf2x \
		libgmp.so:math/gmp \
		libhwloc.so:devel/hwloc2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		cmake:noninja compiler:c++11-lang perl5 python shebangfix # noninja because: bad $-escape (literal $ must be written as $$)

USE_GITLAB=	yes
GL_SITE=	https://gitlab.inria.fr
GL_COMMIT=	3ab6a4781fa5d218ed332834809ba6c6fd1a591f

SHEBANG_GLOB=	*.py

CXXFLAGS_i386=	-msse2 # workaround for error: always_inline function '_mm_setzero_si128' requires target feature 'sse2', but would be inlined into function 'gf2x_mul4' that is compiled without support for 'sse2'

TEST_TARGET=	check # 'test' does the same but is less verbose

BINARY_ALIAS=	python3=${PYTHON_CMD} make=${GMAKE}

.include <bsd.port.options.mk>

.if ${ARCH} == amd64
PLIST_SUB=	LINGEN_PZ=""
.else
PLIST_SUB=	LINGEN_PZ="@comment "
.endif

.include <bsd.port.mk>
