PORTNAME=	pygments
DISTVERSION=	2.16.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pygments-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Syntax highlighter written in Python
WWW=		https://pygments.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0.40.0:devel/py-wheel@${PY_FLAVOR}
# test: 4152 passed, 3 skipped
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wcag-contrast-ratio>=0.9:www/py-wcag-contrast-ratio@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist concurrent pep517 pytest

CONFLICTS_INSTALL=	py??-pygments-25

NO_ARCH=	yes

.include <bsd.port.mk>
