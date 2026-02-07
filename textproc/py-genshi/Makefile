PORTNAME=	Genshi
PORTVERSION=	0.7.10
CATEGORIES=	textproc www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl}-${DISTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Toolkit for generation of output for the web
WWW=		https://genshi.edgewall.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.43.0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517 pytest

# tests: 808 passed
TEST_ENV=	PYTEST_DISABLE_PLUGIN_AUTOLOAD=1 \
		PYTHONPATH="${STAGEDIR}${PYTHON_SITELIBDIR}"

OPTIONS_DEFINE=	BABEL
BABEL_DESC=	I18n support through the Babel plugin

BABEL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=0.8:devel/py-babel@${PY_FLAVOR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/genshi/_speedups${PYTHON_TAG}.so

.include <bsd.port.mk>
