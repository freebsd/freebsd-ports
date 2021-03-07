# $FreeBSD$

PORTNAME=	certbot-dns-google
PORTVERSION=	${ACME_VERSION}
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Google Cloud DNS Authenticator plugin for Certbot

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}acme>=${ACME_VERSION},1:security/py-acme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certbot>=${ACME_VERSION},1:security/py-certbot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-api-python-client>=1.5.5:www/py-google-api-python-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>0:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauth2client>=4.0:security/py-oauth2client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include "${.CURDIR}/../py-acme/version.mk"
.include <bsd.port.mk>
