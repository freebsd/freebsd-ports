PORTNAME=	mkdocs-rss-plugin
DISTVERSION=	1.17.5
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mkdocs_rss_plugin-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Generates a static RSS feed using git log and page.meta
WWW=		https://github.com/Guts/mkdocs-rss-plugin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachecontrol>=0.14<1:www/py-cachecontrol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=3.1.43<3.2:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31<3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs>=1.6.1<2:textproc/py-mkdocs@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
