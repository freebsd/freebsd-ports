PORTNAME=	license-expression
DISTVERSION=	30.4.3
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	license_expression-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Parses, normalizes and compares license expressions
WWW=		https://github.com/aboutcode-org/license-expression

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/NOTICE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boolean.py>=4.0:devel/py-boolean.py@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

NO_ARCH=	yes

.include <bsd.port.mk>
