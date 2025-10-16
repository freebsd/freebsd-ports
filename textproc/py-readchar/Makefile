PORTNAME=	readchar
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.1
CATEGORIES=	textproc devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python library to read characters and key strokes
WWW=		https://github.com/magmax/python-readchar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pexpect>0:misc/py-pexpect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		dos2unix localbase python
USE_PYTHON=	autoplist pep517 pytest

USE_GITHUB=	yes
GH_ACCOUNT=	magmax
GH_PROJECT=	python-${PORTNAME}

DOS2UNIX_GLOB=	*.py

NO_ARCH=	yes

.include <bsd.port.mk>
