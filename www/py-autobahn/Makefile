# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=		autobahn
PORTVERSION=		0.11.0
DISTVERSIONPREFIX=	v
CATEGORIES=		www python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		koobs@FreeBSD.org
COMMENT=		WebSocket client & server library, WAMP real-time framework

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.6.1:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}txaio>=2.2.0:devel/py-txaio
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.7.2:devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}mock>=1.3.0:devel/py-mock \
		${PYTHON_PKGNAMEPREFIX}unittest2>0:devel/py-unittest2 \
		${PYTHON_PKGNAMEPREFIX}trollius>0:devel/py-trollius # Not really a depends, but the test doesnt skip

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

GH_ACCOUNT=	crossbario
GH_PROJECT=	autobahn-python

OPTIONS_DEFINE=		ACCELERATE SERIALIZATION
OPTIONS_MULTI=		BACKENDS
OPTIONS_MULTI_BACKENDS=	ASYNCIO TWISTED
OPTIONS_DEFAULT=	ACCELERATE SERIALIZATION TWISTED

BACKENDS_DESC=		Networking Backends

ACCELERATE_DESC=	WebSocket and JSON Acceleration
ASYNCIO_DESC=		asyncio (PEP-3156) Backend (Python 3.x ONLY)
SERIALIZATION_DESC=	WAMPv2 Binary Serialization
TWISTED_DESC=		Twisted Backend (Python 2.x ONLY)

ACCELERATE_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}wsaccel>=0.6.2:www/py-wsaccel \
				${PYTHON_PKGNAMEPREFIX}ujson>=1.33:devel/py-ujson

SERIALIZATION_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack-python>=0.4.0:devel/py-msgpack-python

TWISTED_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}zope.interface>=3.6:devel/py-zope.interface \
				${PYTHON_PKGNAMEPREFIX}twisted>=12.1:devel/py-twisted

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTWISTED} && ${PYTHON_REL} >= 3000
BROKEN=	Twisted currently only supports Python 2.x. Disable the TWISTED option and use ASYNCIO instead
.endif

.if ${PORT_OPTIONS:MASYNCIO}
.if ${PYTHON_REL} <= 3000
BROKEN=	ASYNCIO requires Python 3.x. Disable the ASYNCIO option and use TWISTED instead
.elif ${PYTHON_REL} <= 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}asyncio>=3.4.3:devel/py-asyncio
.endif
.endif

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest autobahn

.include <bsd.port.post.mk>
