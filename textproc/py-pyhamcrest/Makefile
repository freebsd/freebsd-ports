# Created by: Richard Gallamore <ultima@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PyHamcrest
DISTVERSIONPREFIX=	V
DISTVERSION=	1.10.1
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Hamcrest matchers for Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.4:devel/py-six@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=1.11:devel/py-hypothesis@${PY_FLAVOR} \
       		${PYTHON_PKGNAMEPREFIX}pytest>=2.8:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes
GH_ACCOUNT=	hamcrest

NO_ARCH=	yes

do-test:
		(cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
