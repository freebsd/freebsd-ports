PORTNAME=	furo
PORTVERSION=	2025.7.19
CATEGORIES=	textproc python
MASTER_SITES=	PYPI \
		LOCAL/sunpoet:static
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-static${EXTRACT_SUFX}:static

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Clean customizable Sphinx documentation theme
WWW=		https://pradyunsg.me/furo/ \
		https://github.com/pradyunsg/furo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.9.0:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}accessible-pygments>=0.0.5:textproc/py-accessible-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=2.7:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=5.0,1<9.0,1:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx-basic-ng>=1.0.0b2:textproc/py-sphinx-basic-ng@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

post-patch:
	@${FIND} ${WRKSRC} -name .gitignore -delete

post-install:
	cd ${WRKDIR}/static/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/furo/theme/furo/static/

.include <bsd.port.mk>
