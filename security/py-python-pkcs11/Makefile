PORTNAME=	python-pkcs11
PORTVERSION=	0.8.1
CATEGORIES=	security python
MASTER_SITES=	PYPI \
		https://github.com/pyauth/python-pkcs11/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python_pkcs11-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PKCS\#11 (Cryptoki) support for Python
WWW=		https://python-pkcs11.readthedocs.io/en/latest/ \
		https://github.com/danni/python-pkcs11

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=0:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1crypto>=0:devel/py-asn1crypto@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent cython3 pep517

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
