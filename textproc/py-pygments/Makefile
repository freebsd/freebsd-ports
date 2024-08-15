PORTNAME=	pygments
DISTVERSION=	2.18.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Syntax highlighter written in Python
WWW=		https://pygments.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=1.18.0:devel/py-hatchling@${PY_FLAVOR}
# tests: 4400 passed, 3 skipped
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-cov>=4.1.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-randomly>=3.12.0:devel/py-pytest-randomly@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wcag-contrast-ratio>=0.9:www/py-wcag-contrast-ratio@${PY_FLAVOR}

USES=		cpe python tex
USE_PYTHON=	autoplist concurrent pep517 pytest
USE_TEX=	latex:test

NO_ARCH=	yes

.include <bsd.port.mk>
