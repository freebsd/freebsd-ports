PORTNAME=	elementpath
DISTVERSION=	2.5.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	XPath 1.0/2.0/3.0 parsers and selectors for ElementTree and lxml

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR}

USES=		python:3.7+ pytest
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes

# https://github.com/sissaschool/elementpath/issues/41
PYTEST_BROKEN_TESTS=	test_exp_math_function

.include <bsd.port.mk>
