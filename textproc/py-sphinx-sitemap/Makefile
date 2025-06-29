PORTNAME=	sphinx-sitemap
PORTVERSION=	2.7.2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	sphinx_sitemap-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sitemap generator for Sphinx
WWW=		https://sphinx-sitemap.readthedocs.io/en/latest/ \
		https://github.com/jdillard/sphinx-sitemap

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx-last-updated-by-git>=0:textproc/py-sphinx-last-updated-by-git@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
