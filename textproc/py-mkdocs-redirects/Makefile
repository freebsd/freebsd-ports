PORTNAME=	mkdocs-redirects
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.4
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	samir@noir.im
COMMENT=	MkDocs plugin for dynamic page redirects to prevent broken links

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mkdocs>=1.0.4:textproc/py-mkdocs@${PY_FLAVOR}

TEST_DEPENDS=	${RUN_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	mkdocs
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

do-test:
	cd ${WRKSRC} && PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} ${PYTHON_CMD} -m pytest -v tests

.include <bsd.port.mk>
