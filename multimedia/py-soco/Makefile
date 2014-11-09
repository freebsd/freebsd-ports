# $FreeBSD$

PORTNAME=	soco
PORTVERSION=	0.9
CATEGORIES=	multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	conall@conall.net
COMMENT=	Python library to control Sonos speakers

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:${PORTSDIR}/www/py-requests

USE_GITHUB=	yes
GH_ACCOUNT=	SoCo
GH_PROJECT=	SoCo
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	d7d2688

USES=		python:2
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
