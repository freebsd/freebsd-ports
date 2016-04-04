# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rackspace-monitoring
PORTVERSION=	0.6.5
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python client library for Rackspace Cloud Monitoring

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libcloud>=0.14:net/py-libcloud

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && \
	${CP} test/secrets.py-dist test/secrets.py && \
	${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
