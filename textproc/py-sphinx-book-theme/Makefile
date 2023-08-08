PORTNAME=	sphinx-book-theme
PORTVERSION=	1.0.1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI \
		LOCAL/sunpoet:static
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	sphinx_book_theme-${PORTVERSION}${EXTRACT_SUFX} \
		sphinx_book_theme-${PORTVERSION}-static${EXTRACT_SUFX}:static

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bootstrap-based Sphinx theme from the PyData community
WWW=		https://github.com/executablebooks/sphinx-book-theme

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydata-sphinx-theme>=0.13.3:textproc/py-pydata-sphinx-theme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=4,1<7,1:textproc/py-sphinx@${PY_FLAVOR} \

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/sphinx_book_theme-${PORTVERSION}

post-patch:
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

post-install:
	cd ${WRKDIR}/static/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/sphinx_book_theme/

.include <bsd.port.mk>
