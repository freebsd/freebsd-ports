# Created by: Thierry Thomas <thierry@pompo.net>

PORTNAME=	word_cloud
DISTVERSION=	1.5.0
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Little word cloud generator in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYNUMPY}	\
		${PY_PILLOW}
RUN_DEPENDS=	${PYNUMPY}	\
		${PY_PILLOW}	\
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pluggy>0:devel/py-pluggy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	amueller

USES=		python:3.7+ shebangfix
USE_PYTHON=	distutils
SHEBANG_FILES=	doc/*.sh examples/*.py

OPTIONS_DEFINE=	DOCS EXAMPLES

PLIST_SUB+=	VER=${PORTVERSION}
TEST_TARGET=	test
PORTDOCS=	*
PORTEXAMPLES=	*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}

do-test: install
	${REINPLACE_CMD} -e 's|--cov --cov-report xml ||' ${WRKSRC}/setup.cfg
	${REINPLACE_CMD} -e 's|"python |"${PYTHON_CMD} |' ${WRKSRC}/test/test_wordcloud_cli.py
	(cd ${TEST_WRKSRC} && py.test)

.include <bsd.port.mk>
