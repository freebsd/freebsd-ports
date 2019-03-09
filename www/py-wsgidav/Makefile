# $FreeBSD$

PORTNAME=	WsgiDAV
DISTVERSION=	2.4.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	WSGI based WebDAV server for sharing resources

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0.5:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsmin>=2.2:devel/py-jsmin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.2:devel/py-yaml@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0.5:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsmin>=2.2:devel/py-jsmin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.2:devel/py-yaml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheroot>=6.0:www/py-cheroot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=3.5:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8-quotes>=1.0:devel/py-flake8-quotes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=2.7:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=1.8:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>=2.0:devel/py-tox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}WebTest>=2.0:www/py-WebTest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

OPTIONS_DEFINE=	CHEROOT CHERRYPY FLUP PASTE WSGIUTILS
OPTIONS_DEFAULT=	CHEROOT

CHEROOT_DESC=		Cheroot server support
CHERRYPY_DESC=		Cherrypy server support
FLUP_DESC=		Flup server support
PASTE_DESC=		Paste server support
WSGIUTILS_DESC=		Wsgiutils server support

CHEROOT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cheroot>=0:www/py-cheroot@${PY_FLAVOR}

CHERRYPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cherrypy>=0:www/py-cherrypy@${PY_FLAVOR}

FLUP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flup6>=0:www/py-flup6@${PY_FLAVOR}

PASTE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Paste>=0:www/py-paste@${PY_FLAVOR}

WSGIUTILS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wsgiutils>=0:devel/py-wsgiutils@${PY_FLAVOR}

# In order to run tests, need to switch to the GitHub
# repo, else will succeed with 0 test runs.
do-test:
	(cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
