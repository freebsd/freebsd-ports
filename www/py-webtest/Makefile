PORTNAME=	webtest
PORTVERSION=	3.0.0
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	WebTest-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Helper to test WSGI applications
WWW=		https://docs.pylonsproject.org/projects/webtest/en/latest/ \
		https://github.com/Pylons/webtest

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/license.rst

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}waitress>=0.8.5:www/py-waitress@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2:www/py-webob@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
