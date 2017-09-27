# $FreeBSD$

PORTNAME=	google-cloud-storage
PORTVERSION=	1.4.0
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Python Client for Google Cloud Storage

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}google-cloud-core>0:www/py-google-cloud-core \
		${PYTHON_PKGNAMEPREFIX}google-auth>0:security/py-google-auth \
		${PYTHON_PKGNAMEPREFIX}google-resumable-media>0:www/py-google-resumable-media \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests

USES=		python
USE_PYTHON=	distutils concurrent autoplist

.include <bsd.port.mk>
