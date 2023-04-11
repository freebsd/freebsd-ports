PORTNAME=	pygments
DISTVERSION=	2.15.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Pygments-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Syntax highlighter written in Python
WWW=		https://pygments.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0.40.0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wcag-contrast-ratio>=0.9:www/py-wcag-contrast-ratio@${PY_FLAVOR}

USES=		cpe python:3.7+
USE_PYTHON=	autoplist concurrent pep517

CONFLICTS_INSTALL=	py??-pygments-25

NO_ARCH=	yes

# test: 4033 passed, 3 skipped, 8072 warnings
do-test:
	(cd ${TEST_WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs -o addopts=)

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=1.7.0:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
