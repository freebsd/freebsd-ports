PORTNAME=	cado-nfs
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0.20210806
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Implementation of the Number Field Sieve Algorithm

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_i386=	pkg-static: Unable to access file /wrkdirs/usr/ports/math/cado-nfs/work/stage/usr/local/lib/cado-nfs-3.0.0/linalg/bwc/lingen_pz:No such file or directory

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		bash:shells/bash \
		gmake:devel/gmake
LIB_DEPENDS=	libecm.so:math/gmp-ecm \
		libgf2x.so:math/gf2x \
		libgmp.so:math/gmp \
		libhwloc.so:devel/hwloc2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		cmake:noninja compiler:c++11-lang perl5 python shebangfix # noninja because: bad $-escape (literal $ must be written as $$)
USE_GCC=	yes # fails in clang-11 with various STL and C++ errors. Reported to the upstream author Emmanuel Thomé on 2021-08-13.

USE_GITLAB=	yes
GL_SITE=	https://gitlab.inria.fr
GL_COMMIT=	c5b20eac12ea225a325d582923ef058832cda28e

SHEBANG_GLOB=	*.py

TEST_TARGET=	check # 'test' does the same but is less verbose

BINARY_ALIAS=	python3=${PYTHON_CMD} make=${GMAKE}

.include <bsd.port.mk>
