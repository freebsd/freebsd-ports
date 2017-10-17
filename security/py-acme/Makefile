# Created by: Carlos J Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	acme
PORTVERSION=	0.18.2
PORTEPOCH=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	ACME protocol implementation in Python

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=0.8:security/py-cryptography \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.13:security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}pyrfc3339>0:devel/py-pyrfc3339 \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}setuptools>=1.0:devel/${PYTHON_PKGNAMEPREFIX}setuptools \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}nose>0:devel/py-nose

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
