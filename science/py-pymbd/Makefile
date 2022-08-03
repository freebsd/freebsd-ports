PORTNAME=	pymbd
DISTVERSION=	0.12.5
CATEGORIES=	science # chemistry
MASTER_SITES=	https://github.com/libmbd/libmbd/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Many-body dispersion library

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>:devel/py-cffi@${PY_FLAVOR}
LIB_DEPENDS=	libmbd.so:science/libmbd
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>:devel/py-cffi@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	distutils autoplist

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

post-install: # strip binary
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/_libmbd.abi3.so

do-test: # also see https://github.com/libmbd/libmbd/issues/44
	@${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${FILESDIR}/example.py

.include <bsd.port.mk>
