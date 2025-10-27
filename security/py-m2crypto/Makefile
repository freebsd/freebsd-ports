PORTNAME=	m2crypto
PORTVERSION=	0.46.2
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Crypto and SSL toolkit for Python
WWW=		https://m2crypto.readthedocs.io/en/latest/ \
		https://gitlab.com/m2crypto/m2crypto

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSES/BSD-2-Clause.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.0.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		swig>=4.0:devel/swig

USES=		cpe python ssl
USE_PYTHON=	autoplist concurrent pep517

CPE_VENDOR=	m2crypto_project

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
