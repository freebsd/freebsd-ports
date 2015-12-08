# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	letsencrypt
DISTVERSION=	0.1.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Let's Encrypt client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/acme/__init__.py:${PORTSDIR}/security/py-acme \
		${PYTHON_PKGNAMEPREFIX}configargparse>0:${PORTSDIR}/devel/py-configargparse \
		${PYTHON_PKGNAMEPREFIX}configobj>0:${PORTSDIR}/devel/py-configobj \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0.7:${PORTSDIR}/security/py-cryptography \
		${PYTHON_PKGNAMEPREFIX}parsedatetime>0:${PORTSDIR}/devel/py-parsedatetime \
		${PYTHON_PKGNAMEPREFIX}psutil>0:${PORTSDIR}/sysutils/py-psutil \
		${PYTHON_PKGNAMEPREFIX}openssl>0:${PORTSDIR}/security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}pyrfc3339>0:${PORTSDIR}/devel/py-pyrfc3339 \
		${PYTHON_PKGNAMEPREFIX}python2-pythondialog>0:${PORTSDIR}/devel/py-python2-pythondialog \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}requests>0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}zope.component>0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:${PORTSDIR}/devel/py-zope.interface

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
