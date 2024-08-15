PORTNAME=	reprise
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	ports-mgmt python

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Port testing system
WWW=		https://github.com/AMDmi3/reprise

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonslicer>=0:textproc/py-jsonslicer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=0:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=0:devel/py-termcolor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR}

USES=		python:3.9+
USE_GITHUB=	yes
GH_ACCOUNT=	AMDmi3
USE_PYTHON=	autoplist distutils noflavors
NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG.md ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
