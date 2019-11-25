# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elasticsearch
PORTVERSION=	5.5.2
PORTREVISION=	2
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	5

MAINTAINER=	elastic@FreeBSD.org
COMMENT=	Official Python low-level client for Elasticsearch

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urllib3>=1.8.2:net/py-urllib3@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=2.0.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyaml>0:textproc/py-pyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}coverage>0:devel/py-coverage@${PY_FLAVOR}

USES=		python

USE_GITHUB=	yes # tests not packaged with sdist
USE_PYTHON=	distutils autoplist

GH_ACCOUNT=	elastic
GH_PROJECT=	elasticsearch-py
GH_TAGNAME=	719a94ab4

# Using (5.5.2) commit hash in 5.5.x branch not the 5.5.2 tag
# because that branch has the module and package name set as
# 'elastisearch' not 'elasticsearch5'. The reason this is
# needed (for now) is because:
#
# 1) Upstream doesn't package tests with the sdist, so
#    we need USE_GITHUB until they do.
# 2) This port fetches distfile from the *elastisearch*
#    PyPI package *NOT* the 'elasticsearch5' PyPI package,
#    which has the different internal package name.
#
# Upstream made separate (versioned) packages on PyPI
# available so that they didn't conflict on install.
# The elasticsearchX python ports should be changed to
# use these version-specific package names/sources, at
# which point CONFLICTS can be removed.

CONFLICTS=	${PYTHON_PKGNAMEPREFIX}elasticsearch-[0-9]*

NO_ARCH=	yes

# All tests pass with or without elasticsearch server running, but without
# it running, connection errors are displayed. upstream test runs display these
# errors too. More tests run when elasticsearch server is running.

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
