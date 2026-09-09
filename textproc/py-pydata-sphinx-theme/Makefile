PORTNAME=	pydata-sphinx-theme
PORTVERSION=	0.21.0
CATEGORIES=	textproc python
MASTER_SITES=	PYPI \
		LOCAL/sunpoet:static
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	pydata_sphinx_theme-${PORTVERSION}${EXTRACT_SUFX} \
		pydata_sphinx_theme-${PORTVERSION}-static${EXTRACT_SUFX}:static

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bootstrap-based Sphinx theme from the PyData community
WWW=		https://pydata-sphinx-theme.readthedocs.io/en/stable/ \
		https://github.com/pydata/pydata-sphinx-theme

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.9.0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}accessible-pygments>=0:textproc/py-accessible-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=0:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup4>=0:www/py-beautifulsoup4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.7:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=8.2,1<10,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/pydata_sphinx_theme-${PORTVERSION}

post-patch:
	@${FIND} ${WRKSRC} -name .gitignore -delete

post-install:
	cd ${WRKDIR}/static/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/pydata_sphinx_theme/

.include <bsd.port.mk>
