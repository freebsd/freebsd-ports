PORTNAME=	jq
PORTVERSION=	1.10.0
PORTREVISION=	0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI LOCAL/mandree:mandree
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	jq.py: a lightweight and flexible JSON processor
WWW=		https://github.com/mwilliamson/jq.py

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}cython3>0:lang/cython3@${PY_FLAVOR}
LIB_DEPENDS=	libjq.so:textproc/jq \
		libonig.so:devel/oniguruma
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
MAKE_ENV+=	JQPY_USE_SYSTEM_LIBS=1

USES=		localbase python
USE_PYTHON=	autoplist distutils

post-install:
		${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/jq*.so

.if defined(_MANDREE_FORCE_POUDRIERE_TEST_)
BUILD_DEPENDS+=	${TEST_DEPENDS}
pre-package:
		${MAKE} test
.endif

pre-test:
		${CP} ${FILESDIR}/tox.ini ${WRKSRC}

do-test:
		cd ${WRKSRC} && ${SETENV} \
			PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} \
			${PYTHON_CMD} -m pytest -v tests/

.include <bsd.port.mk>
