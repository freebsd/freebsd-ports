# $FreeBSD$

PORTNAME=	soco
PORTVERSION=	0.16
DISTVERSIONPREFIX=	v
CATEGORIES=	multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	conall@conall.net
COMMENT=	Python library to control Sonos speakers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>0:devel/py-xmltodict@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	SoCo
GH_PROJECT=	SoCo

.include <bsd.port.mk>
