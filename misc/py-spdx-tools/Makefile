PORTNAME=	spdx-tools
DISTVERSION=	0.7.1
PORTREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Parses, validates and creates SPDX documents
WWW=		https://github.com/spdx/tools-python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.3:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0:devel/py-xmltodict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rdflib>=0:textproc/py-rdflib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typeguard>=2.13.3:devel/py-typeguard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uritools>=0:net/py-uritools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}license-expression>=0:textproc/py-license-expression@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ply>=0:devel/py-ply@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

TEST_ENV=	PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} LC_ALL=en_US.UTF-8

CONFLICTS_INSTALL=	py??-spdx
NO_ARCH=		yes
PORTEXAMPLES=		*

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${FIND} ${WRKSRC}/examples -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${EXAMPLESDIR} \;

.include <bsd.port.mk>
