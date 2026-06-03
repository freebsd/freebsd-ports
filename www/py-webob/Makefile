PORTNAME=	webob
PORTVERSION=	1.8.9
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	WSGI request and response Python object
WWW=		https://webob.org/

LICENSE=	MIT

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python

BUILD_DEPENDS=		${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylons-sphinx-themes>=0:textproc/py-pylons-sphinx-themes@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=1.7.5,1:textproc/py-sphinx@${PY_FLAVOR}
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

NO_ARCH=	yes
SUB_FILES=	pyproject.toml
SUB_LIST=	PORTVERSION=${PORTVERSION}
USE_PYTHON=	autoplist pep517

pre-configure:
	[ ! -e ${WRKSRC}/pyproject.toml ] && cp ${WRKDIR}/pyproject.toml ${WRKSRC}

post-build-DOCS-on:
	${LOCALBASE}/bin/sphinx-build-${PYTHON_VER} -d ${WRKDIR} -b html -E ${WRKSRC}/docs ${WRKSRC}/build/sphinx/html

post-extract-DOCS-on:
	@(cd ${WRKSRC} && \
	${LN} -s src/webob.egg-info .)

post-install-DOCS-on:
	@(cd ${WRKSRC}/build/sphinx/html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -name objectiv.inv")

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 31300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}legacy-cgi>=0:www/py-legacy-cgi@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
