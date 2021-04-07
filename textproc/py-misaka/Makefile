PORTNAME=	misaka
PORTVERSION=	2.1.1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	CFFI binding for Hoedown, a markdown parsing library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0:devel/py-cffi@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.0.0:devel/py-cffi@${PY_FLAVOR}
TEST_DEPENDS=	tidy5:www/tidy-html5

# Actually 2.7,3.4+
USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

PYDISTUTILS_BUILDARGS=	build_ext -i

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/misaka/*.so

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} tests/run_tests.py

.include <bsd.port.mk>
