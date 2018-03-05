# $FreeBSD$

PORTNAME=	sseclient
DISTVERSION=	0.0.19
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python client library for reading Server Sent Event streams

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
