# Created by: Carlos J Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	acme
PORTVERSION=	0.5.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	ACME protocol implementation in Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=0.8:security/py-cryptography \
		${PYTHON_PKGNAMEPREFIX}ndg_httpsclient>0:net/py-ndg_httpsclient \
		${PYTHON_PKGNAMEPREFIX}pyasn1>0:devel/py-pyasn1 \
		${PYTHON_PKGNAMEPREFIX}idna>0:dns/py-idna \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.13:security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}pyrfc3339>0:devel/py-pyrfc3339 \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}setuptools${PYTHON_SUFFIX}>0:devel/py-setuptools${PYTHON_SUFFIX} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}werkzeug>0:www/py-werkzeug
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}funcsigs>0:devel/py-funcsigs \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
