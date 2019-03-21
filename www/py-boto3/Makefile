# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	boto3
PORTVERSION=	1.9.106
CATEGORIES=	www python devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	AWS SDK for Python

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}botocore>=1.12.106:devel/py-botocore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>=0.7.1:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}s3transfer>=0.2.0:net/py-s3transfer@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

# Actually 2.6-2.7,3.3-3.7
USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

# setup.py test runs integration tests which fail
# https://github.com/boto/s3transfer/issues/41
# Note: this is an AWS python package wide issue
do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m nose -v tests/unit tests/functional

.include <bsd.port.mk>
