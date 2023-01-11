PORTNAME=	jq
PORTVERSION=	1.3.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI LOCAL/mandree:mandree
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} jq-1.2.1-tests${EXTRACT_SUFX}:mandree

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	jq.py: a lightweight and flexible JSON processor
WWW=		https://github.com/mwilliamson/jq.py

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libjq.so:textproc/jq \
		libonig.so:devel/oniguruma
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		localbase python
USE_PYTHON=	autoplist distutils

post-extract:
		# move tests into place - unchanged between 1.2.1 and 1.2.2
		${MV} ${WRKDIR}/jq-1.2.1/* ${WRKSRC}

post-install:
		${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/jq*.so

.if defined(_MANDREE_FORCE_POUDRIERE_TEST_)
BUILD_DEPENDS+=	${TEST_DEPENDS}
pre-package:
		${MAKE} test
.endif

do-test:
		cd ${WRKSRC} && ${SETENV} \
			PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} \
			${PYTHON_CMD} -m pytest -v tests/

.include <bsd.port.mk>
