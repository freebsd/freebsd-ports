# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	rackspace-monitoring
PORTVERSION=	0.8.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python client library for Rackspace Cloud Monitoring

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Python compatibility upto 3.2 and last release was 3 years ago
EXPIRATION_DATE=	2022-06-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}libcloud>=0.17:net/py-libcloud@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && \
	${CP} test/secrets.py-dist test/secrets.py && \
	${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
