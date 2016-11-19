# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	urllib3
PORTVERSION=	1.19.1
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Enhance HTTP Python's standard library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysocks>=1.5.7:net/py-pysocks \
	${PYTHON_PKGNAMEPREFIX}cryptography>=1.3.4:security/py-cryptography \
	${PYTHON_PKGNAMEPREFIX}openssl>=16.0:security/py-openssl \
	${PYTHON_PKGNAMEPREFIX}idna>=2.0:dns/py-idna

USES=	python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipaddress>=0:net/py-ipaddress
.endif

.if ${PYTHON_REL} < 3400
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}certifi>=0:security/py-certifi
.endif

.include <bsd.port.post.mk>
