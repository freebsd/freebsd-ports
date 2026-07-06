PORTNAME=	commonmark
DISTVERSION=	0.9.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python parser for the CommonMark Markdown spec
WWW=		https://github.com/rtfd/commonmark.py

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} PYTHONPATH=${WRKSRC} ${PYTHON_CMD} commonmark/tests/run_spec_tests.py

# tests as of 0.9.2: 649 passed, 0 failed

.include <bsd.port.mk>
