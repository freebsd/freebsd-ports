PORTNAME=	webob
PORTVERSION=	1.8.6
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WebOb-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	WSGI request and response Python object

LICENSE=	MIT

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylons-sphinx-themes>=0:textproc/py-pylons-sphinx-themes@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx>=1.7.5,1:textproc/py-sphinx@${PY_FLAVOR}
DOCS_VARS=	PYDISTUTILS_BUILD_TARGET+="build_sphinx -a -E"
DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

NO_ARCH=	yes
USE_PYTHON=	distutils autoplist

post-extract-DOCS-on:
	@(cd ${WRKSRC} && \
	${LN} -s src/WebOb.egg-info .)

post-install-DOCS-on:
	@(cd ${WRKSRC}/build/sphinx/html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name .buildinfo -and ! -name objectiv.inv")

.include <bsd.port.mk>
