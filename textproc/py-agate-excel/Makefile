PORTNAME=	agate-excel
PORTVERSION=	0.4.3
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S,-,_,}-${PORTVERSION}

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Support reading Excel files for agate
WWW=		https://agate-excel.rtfd.org/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}agate>=1.5.0:textproc/py-agate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}olefile>=0:devel/py-olefile@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>=0.9.4:textproc/py-xlrd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=2.3.0:textproc/py-openpyxl@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

.include <bsd.port.mk>
