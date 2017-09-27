# $FreeBSD$

PORTNAME=	google-cloud-core
PORTVERSION=	0.27.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	API Client library for Google Cloud: Core Helpers

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}googleapis-common-protos>0:devel/py-googleapis-common-protos \
		${PYTHON_PKGNAMEPREFIX}google-auth>0:security/py-google-auth \
		${PYTHON_PKGNAMEPREFIX}protobuf>0:devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six

USES=		python
USE_PYTHON=	distutils concurrent autoplist

.include <bsd.port.mk>
