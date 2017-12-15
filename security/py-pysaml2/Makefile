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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>1.0.0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Paste>0:www/py-paste@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}repoze.who>0:devel/py-repoze.who@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>2.5:security/py-pycrypto@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:devel/py-dateutil@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR} \
		xmlsec1:security/xmlsec1
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}responses>0:devel/py-responses@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@(cd ${WRKSRC} && ${PYTHON_CMD} -m pytest)

.include <bsd.port.mk>
