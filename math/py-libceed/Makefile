PORTNAME=	libceed
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.0-763
DISTVERSIONSUFFIX=	-ge3ae47f6
CATEGORIES=	math # machine-learning
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	CEED Library: Code for Efficient Extensible Discretizations
WWW=		https://libceed.org/en/latest/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>0:devel/py-cffi@${PY_FLAVOR} \
		${PYNUMPY}
BUILD_DEPENDS=	gmake:devel/gmake \
		${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		fortran python
USE_PYTHON=	distutils autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	CEED
GH_PROJECT=	libCEED

CFLAGS+=	-fPIC # https://github.com/CEED/libCEED/issues/1706

BINARY_ALIAS=	make=${GMAKE}
#		python3=${PYTHON_CMD}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PYTHON_SITELIBDIR}/_ceed_cffi.abi3.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/libceed/lib/libceed.so

do-test:
	cd ${WRKSRC}/python/tests && \
		${SETENV} PYTHON=${PYTHON_CMD} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} ${GMAKE} test

# rebuilds and reinstalls the C library, see https://github.com/CEED/libCEED/issues/1707

.include <bsd.port.mk>
