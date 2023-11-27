PORTNAME=	service_identity
PORTVERSION=	18.1.0
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	axel.rau@chaos1.de
COMMENT=	Service identity verification for pyOpenSSL
WWW=		https://github.com/pyca/service_identity

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# See https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=275167
DEPRECATED=	Use security/py-service-identity
EXPIRATION_DATE=2024-01-31

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}attrs>=16.0.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0:devel/py-pyasn1-modules@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0:devel/py-pyasn1@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist cryptography distutils

NO_ARCH=	yes

.include <bsd.port.mk>
