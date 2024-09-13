PORTNAME=	sphinx-book-theme
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI \
		LOCAL/sunpoet:static
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	sphinx_book_theme-${PORTVERSION}${EXTRACT_SUFX} \
		sphinx_book_theme-${PORTVERSION}-static${EXTRACT_SUFX}:static

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Clean book theme for scientific explanations and documentation with Sphinx
WWW=		https://sphinx-book-theme.readthedocs.io/en/stable/ \
		https://github.com/executablebooks/sphinx-book-theme

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.9.0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydata-sphinx-theme>=0.15.2:textproc/py-pydata-sphinx-theme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=5,1:textproc/py-sphinx@${PY_FLAVOR} \

USES=		python:3.9+
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/sphinx_book_theme-${PORTVERSION}

post-patch:
	@${FIND} ${WRKSRC} -name .gitignore -delete

post-install:
	cd ${WRKDIR}/static/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/sphinx_book_theme/

.include <bsd.port.mk>
