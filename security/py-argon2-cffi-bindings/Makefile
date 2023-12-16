PORTNAME=	argon2-cffi-bindings
PORTVERSION=	21.2.0
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Low-level CFFI bindings for Argon2
WWW=		https://github.com/hynek/argon2-cffi-bindings

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.1:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=45:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>=6.2:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libargon2.so:security/libargon2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.1:devel/py-cffi@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	autoplist concurrent pep517 pytest

MAKE_ENV=	ARGON2_CFFI_USE_SYSTEM=1
TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR}

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/extras/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
