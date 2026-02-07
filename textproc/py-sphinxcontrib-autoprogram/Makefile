PORTNAME=	sphinxcontrib-autoprogram
DISTVERSION=	0.1.9
CATEGORIES=	textproc
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Sphinx Autoprogram Extension
WWW=		https://github.com/sphinx-contrib/autoprogram

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.2,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.2,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_PORTDOCS=		*

post-extract:
	@(cd ${BUILD_WRKSRC}; ${RM} sphinxcontrib/__init__.py;)

pre-build-DOCS-on:
	@(cd ${BUILD_WRKSRC}; \
	${SETENVI} ${WRK_ENV} \
	sphinx-build-${PYTHON_VER} \
		-b html -d _build/doctress doc/ build/sphinx/html)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/build/sphinx/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		"! -name .buildinfo -and ! -name objects.inv")

do-test:
	@cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} \
	${PYTHON_CMD} -m unittest -v sphinxcontrib/autoprogram.py

.include <bsd.port.mk>
