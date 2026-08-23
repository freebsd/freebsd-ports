PORTNAME=	python-docs-theme
DISTVERSION=	2026.7
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python_docs_theme-${DISTVERSION}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Sphinx theme for the CPython docs and related projects
WWW=		https://github.com/python/python-docs-theme

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>0:devel/py-babel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=7.3,1:textproc/py-sphinx@${PY_FLAVOR}

USES=		python:3.12+
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes

.include <bsd.port.mk>
