# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	sphinx-book-theme
PORTVERSION=	0.3.2
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP \
		LOCAL/sunpoet:static
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	sphinx_book_theme-${PORTVERSION}${EXTRACT_SUFX} \
		sphinx_book_theme-${PORTVERSION}-static${EXTRACT_SUFX}:static

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Bootstrap-based Sphinx theme from the PyData community

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydata-sphinx-theme>=0.8.0<0.9:textproc/py-pydata-sphinx-theme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=3,1<5,1:textproc/py-sphinx@${PY_FLAVOR} \

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
WRKSRC=		${WRKDIR}/sphinx_book_theme-${PORTVERSION}

post-patch:
	@${SED} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${FILESDIR}/setup.py > ${WRKSRC}/setup.py

post-install:
	cd ${WRKDIR}/static/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/sphinx_book_theme/theme/sphinx_book_theme/static/

.include <bsd.port.mk>
