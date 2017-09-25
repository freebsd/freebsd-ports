# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	certbot
PORTVERSION=	0.18.2
PORTEPOCH=	1
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Let's Encrypt client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}acme>=${PORTVERSION}:security/py-acme \
		${PYTHON_PKGNAMEPREFIX}configargparse>=0.9.3:devel/py-configargparse \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj \
		${PYTHON_PKGNAMEPREFIX}cryptography>=1.2:security/py-cryptography \
		${PYTHON_PKGNAMEPREFIX}parsedatetime>=1.3:devel/py-parsedatetime \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}pyrfc3339>0:devel/py-pyrfc3339 \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}setuptools>=1.0:devel/${PYTHON_PKGNAMEPREFIX}setuptools \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock

# Actually 2.7,3.3+
USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/etc/|${LOCALBASE}/etc/|' \
		-e 's|/var/lib|/var/db|' \
		${WRKSRC}/${PORTNAME}/constants.py
do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
