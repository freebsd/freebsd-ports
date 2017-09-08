# $FreeBSD$

PORTNAME=	docker
PORTVERSION=	2.5.1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Python library for the Docker Engine API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}websocket-client>0:www/py-websocket-client \
		${PYTHON_PKGNAMEPREFIX}docker-pycreds>0:security/py-docker-pycreds

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.pre.mk>

.if ${PYTHON_SUFFIX} < 35
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.ssl_match_hostname>0:security/py-backports.ssl_match_hostname
.endif

.if ${PYTHON_SUFFIX} < 33
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipaddress>0:net/py-ipaddress
.endif

.include <bsd.port.post.mk>
