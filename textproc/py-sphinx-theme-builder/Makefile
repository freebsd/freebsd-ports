PORTNAME=	sphinx-theme-builder
PORTVERSION=	0.2.0b2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool for authoring Sphinx themes with a simple (opinionated) workflow
WWW=		https://github.com/pradyunsg/sphinx-theme-builder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.2<4:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}nodeenv>=0:devel/py-nodeenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject-metadata>=0:devel/py-pyproject-metadata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rich>=0:textproc/py-rich@${PY_FLAVOR} \
		${PY_TOMLI}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	CLI
OPTIONS_DEFAULT=CLI
CLI_DESC=	Command-line interface support

CLI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>=0:devel/py-build@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx-autobuild>=0:textproc/py-sphinx-autobuild@${PY_FLAVOR}

.include <bsd.port.mk>
