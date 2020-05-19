# Created by: Johannes Jost Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	msrest
PORTVERSION=	0.6.14
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	AutoRest swagger generator Python client runtime

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}certifi>=2017.4.17:security/py-certifi@${PY_FLAVOR} \
		${PY_ENUM34} \
		${PYTHON_PKGNAMEPREFIX}isodate>=0.6.0:devel/py-isodate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.16:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0.5.0:www/py-requests-oauthlib@${PY_FLAVOR} \
		${PY_TYPING}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
