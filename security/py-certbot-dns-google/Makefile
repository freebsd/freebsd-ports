# $FreeBSD$

PORTNAME=	certbot-dns-google
PORTVERSION=	${ACME_VERSION}
PORTREVISION=	0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Google Cloud DNS Authenticator plugin for Certbot

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}acme>=${ACME_VERSION}:security/py-acme@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certbot>=${ACME_VERSION}:security/py-certbot@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>0:www/py-httplib2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauth2client>=2.0:security/py-oauth2client@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-api-python-client>1.5:www/py-google-api-python-client@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${FLAVOR}

.include "${.CURDIR}/../py-acme/version.mk"
.include <bsd.port.mk>
