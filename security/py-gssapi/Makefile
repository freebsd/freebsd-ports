PORTNAME=	gssapi
DISTVERSION=	1.10.1
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	john@saltant.com
COMMENT=	High-level and low-level Python bindings to GSSAPI C libraries
WWW=		https://github.com/pythongssapi/python-gssapi

LICENSE=	ISCL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR}

# Officially: 3.9-3.14
USES=	python
USE_PYTHON=	autoplist cython3 pep517

OPTIONS_SINGLE=	GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT
OPTIONS_DEFAULT=	GSSAPI_BASE

GSSAPI_BASE_USES=	gssapi ssl
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=	gssapi:mit

MAKE_ENV+=	GSSAPI_KRB5CONFIG=${KRB5CONFIG}

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} -type f -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
