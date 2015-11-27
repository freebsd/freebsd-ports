# Created by: Carlos J Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	acme
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.0.dev20151114
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cpm@fbsd.es
COMMENT=	ACME implementation

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>0:${PORTSDIR}/devel/py-pyasn1 \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0.8:${PORTSDIR}/security/py-cryptography \
		${PYTHON_PKGNAMEPREFIX}mock>=1.0.1:${PORTSDIR}/devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}ndg_httpsclient>=0.4.0:${PORTSDIR}/net/py-ndg_httpsclient \
		${PYTHON_PKGNAMEPREFIX}pyrfc3339>=0.2:${PORTSDIR}/devel/py-pyrfc3339 \
		${PYTHON_PKGNAMEPREFIX}pytz>=2015.4:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}requests>0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:${PORTSDIR}/devel/py-six \
		${PYTHON_PKGNAMEPREFIX}werkzeug>=0.9:${PORTSDIR}/www/py-werkzeug

USES=		gmake python
USE_PYTHON=	autoplist distutils

WRKSRC_SUBDIR=	acme

USE_GITHUB=	yes
GH_ACCOUNT=	letsencrypt
GH_PROJECT=	letsencrypt

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
