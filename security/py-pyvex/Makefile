PORTNAME=	pyvex
DISTVERSION=	9.2.222
CATEGORIES=	security devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python interface to libVEX and VEX IR
WWW=		https://github.com/angr/pyvex

LICENSE=	BSD2CLAUSE GPLv2+ GPLv3
LICENSE_COMB=	multi
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE
LICENSE_FILE_GPLv2+ =	${WRKSRC}/vex/LICENSE.GPL
LICENSE_FILE_GPLv3=	${WRKSRC}/pyvex_c/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64 armv7 i386
ONLY_FOR_ARCHS_REASON=	pyvex_c/pyvex.c does not support this architecture (see line 170)

BUILD_DEPENDS=	${_MY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}scikit-build-core>=0:devel/py-scikit-build-core@${PY_FLAVOR}
RUN_DEPENDS=	${_MY_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}bitstring>0:devel/py-bitstring@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}angr>=${DISTVERSION}:security/py-angr@${PY_FLAVOR} \
		z3>=0:math/z3

USES=		angr:binaries cmake:indirect localbase python
USE_CSTD=	c99
USE_GITHUB=	nodefault
GH_TUPLE=	angr:${PORTNAME}:v${DISTVERSION}:tests
USE_LDCONFIG=	${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/lib
USE_PYTHON=	autoplist pep517 pytest

MAKE_ENV=	EXTRA_CFLAGS="${CFLAGS}"

_MY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.3:devel/py-cffi@${PY_FLAVOR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/lib/lib${PORTNAME}*.so

do-test:
	@(cd ${WRKSRC} && ${SETENV} ${TEST_ENV} nosetests-${PYTHON_VER} tests/*)

.include <bsd.port.mk>
