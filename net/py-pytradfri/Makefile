PORTNAME=	pytradfri
DISTVERSION=	13.0.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python IKEA Tradfri API controller
WWW=		https://github.com/ggravlingen/pytradfri

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiocoap>=0:net/py-aiocoap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}DTLSSocket>=0:net/py-DTLSSocket@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
