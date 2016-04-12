# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	letsencrypt
PORTVERSION=	0.5.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Let's Encrypt client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}acme==${PORTVERSION}:security/py-acme \
		${PYTHON_PKGNAMEPREFIX}configargparse>=0.9.3:devel/py-configargparse \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0.7:security/py-cryptography \
		${PYTHON_PKGNAMEPREFIX}parsedatetime>0:devel/py-parsedatetime \
		${PYTHON_PKGNAMEPREFIX}psutil>=2.1.0:sysutils/py-psutil \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}pyrfc3339>0:devel/py-pyrfc3339 \
		${PYTHON_PKGNAMEPREFIX}python2-pythondialog>=3.2.2r1:devel/py-python2-pythondialog \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}setuptools${PYTHON_SUFFIX}>0:devel/py-setuptools${PYTHON_SUFFIX} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock

USES=		python:-2.7
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's|/etc/|${LOCALBASE}/etc/|' \
		-e 's|/var/lib|/var/db|' \
		${WRKSRC}/letsencrypt/constants.py
do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
