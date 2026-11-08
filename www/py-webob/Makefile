PORTNAME=	webob
PORTVERSION=	1.8.11
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	WSGI request and response Python object
WWW=		https://webob.org/

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>=3.8.0:devel/py-pytest-xdist@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517
# tests: 2488 passed, 1 xfailed, 9 skipped 
USE_PYTHON+=	pytest

.if make(test)
TEST_ENV=	PYTHONPATH="${STAGEDIR}${PYTHON_SITELIBDIR}"
.endif

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}
NO_ARCH=	yes
SUB_FILES=	pyproject.toml
SUB_LIST=	PORTVERSION=${PORTVERSION}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylons-sphinx-themes>=0:textproc/py-pylons-sphinx-themes@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=1.7.5,1:textproc/py-sphinx@${PY_FLAVOR}

post-extract-DOCS-on:
	@(cd ${WRKSRC} && \
	${LN} -s src/webob.egg-info .)

pre-configure:
	[ ! -e ${WRKSRC}/pyproject.toml ] && cp ${WRKDIR}/pyproject.toml ${WRKSRC}

post-build-DOCS-on:
	${LOCALBASE}/bin/sphinx-build-${PYTHON_VER} -d ${WRKDIR} -b html -E ${WRKSRC}/docs ${WRKSRC}/build/sphinx/html

post-install-DOCS-on:
	@(cd ${WRKSRC}/build/sphinx/html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -name objectiv.inv")

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 31300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}legacy-cgi>=0:www/py-legacy-cgi@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
