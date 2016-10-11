# $FreeBSD$

PORTNAME=	WsgiDAV
PORTVERSION=	2.0.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima1252@gmail.com
COMMENT=	WSGI based WebDAV server for sharing resources

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cherrypy>=0:www/py-cherrypy \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}cov-core>=0:devel/py-cov-core \
		${PYTHON_PKGNAMEPREFIX}WebTest>=0:www/py-WebTest

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	distutils autoplist

post-extract:
	${RM} -r ${WRKSRC}/tests

.include <bsd.port.mk>
