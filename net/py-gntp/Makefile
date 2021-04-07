PORTNAME=	gntp
PORTVERSION=	1.0.3
DISTVERSIONPREFIX=	v
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Growl Notification Transport Protocol for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		gol:deskutils/growl-for-linux

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	kfdm
USE_PYTHON=	distutils autoplist concurrent

NO_ARCH=	yes
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+=build_sphinx

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/build/sphinx/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! -name .buildinfo -and ! -name objects.inv"

# Two tests (test_double_resource + test_single_resource) in test_resources.py
# always fail because desktutils/growl-for-linux isn't (yet) capable to handle
# messages with embedded icons.
#
# To get succesful results from the remaining tests a running instance of "gol"
# (which needs X and is packaged with deskutils/growl-for-linux) is required.
do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} && \
		${TOUCH} ${WRKDIR}/.gntp && ${PYTHON_CMD} -m nose -v -e 'test_(single|double)_resource')

.include <bsd.port.mk>
