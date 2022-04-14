PORTNAME=	reprise
PORTVERSION=	0.2.0
CATEGORIES=	ports-mgmt python

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Port testing system

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonslicer>=0:textproc/py-jsonslicer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}termcolor>=0:devel/py-termcolor@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>=0:devel/py-pytest-asyncio@${PY_FLAVOR}

USES=		python
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

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
IGNORE=		needs python 3.10+, but newest python versions are disabled in the ports by default, so please build with DEFAULT_VERSIONS+=python=3.10 python3=3.10
.endif

.include <bsd.port.post.mk>
