# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	boto3
PORTVERSION=	1.10.6
CATEGORIES=	www python devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	AWS SDK for Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}botocore>=1.13.6,<1.14.0:devel/py-botocore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jmespath>=0.7.1,<1.0.0:devel/py-jmespath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}s3transfer>=0.2.0,<0.3.0:net/py-s3transfer@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

# Actually 2.6-2.7,3.3-3.7
USES=		python
USE_GITHUB=	yes # tests missing from PyPI sdist
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	boto

NO_ARCH=	yes

# setup.py test runs integration tests which fail
# https://github.com/boto/s3transfer/issues/41
# Note: this is an AWS python package wide issue
do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m nose -v tests/unit tests/functional

.include <bsd.port.mk>
