PORTNAME=	s3transfer
PORTVERSION=	0.4.2
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bhughes@FreeBSD.org
COMMENT=	Amazon S3 Transfer Manager for Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}botocore>=1.12.36:devel/py-botocore@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>=1.3.3:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=1.3.0:devel/py-mock@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

# setup.py test runs integration tests which fail
# https://github.com/boto/s3transfer/issues/41
do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m nose -v tests/unit tests/functional

.include <bsd.port.mk>
