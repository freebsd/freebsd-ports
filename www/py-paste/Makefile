PORTNAME=	Paste
PORTVERSION=	3.11.0
PORTREVISION=	0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tools for using a Web Server Gateway Interface stack
WWW=		https://github.com/pasteorg/paste

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/license.txt

DEPRECATED=	Paste is not being actively maintained. Choose other options

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0_3:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.48.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six@${PY_FLAVOR}
# tests: 192 passed, 1 skipped, 1 warning
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.4.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

TEST_ENV=	PYTEST_DISABLE_PLUGIN_AUTOLOAD=1 \
		PYTHONPATH="${STAGEDIR}${PYTHON_SITELIBDIR}"

NO_ARCH=	yes

.include <bsd.port.mk>
