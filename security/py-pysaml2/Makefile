# Created by: Brendan Molloy <brendan+freebsd@bbqsrc.net>
# $FreeBSD$

PORTNAME=	pysaml2
PORTVERSION=	4.0.2
CATEGORIES=	security devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	brendan+freebsd@bbqsrc.net
COMMENT=	Python implementation of SAML Version 2

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}requests>1.0.0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}Paste>0:www/py-paste \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}repoze.who>0:devel/py-repoze.who \
		${PYTHON_PKGNAMEPREFIX}pycrypto>2.5:security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		xmlsec1:security/xmlsec1
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}responses>0:devel/py-responses

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@(cd ${WRKSRC} && ${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>
