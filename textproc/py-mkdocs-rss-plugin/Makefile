PORTNAME=	mkdocs-rss-plugin
DISTVERSION=	1.17.1
PORTREVISION=	1
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Generates a static RSS feed using git log and page.meta
WWW=		https://github.com/Guts/mkdocs-rss-plugin

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachecontrol>=0.14<1:www/py-cachecontrol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gitpython>=3.1.43<3.2:devel/py-gitpython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31<3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs>=1.6.1<2:textproc/py-mkdocs@${PY_FLAVOR}

USES=		python:3.9+
USE_GITHUB=	yes
GH_ACCOUNT=	Guts
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
