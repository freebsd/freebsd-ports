# $FreeBSD$

PORTNAME=	WsgiDAV
PORTVERSION=	2.1.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	WSGI based WebDAV server for sharing resources

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>=0:devel/py-defusedxml@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cherrypy>=0:www/py-cherrypy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cov-core>=0:devel/py-cov-core@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}WebTest>=0:www/py-WebTest@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0:devel/py-defusedxml@${FLAVOR}

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	distutils autoplist

post-extract:
	${RM} -r ${WRKSRC}/tests

.include <bsd.port.mk>
