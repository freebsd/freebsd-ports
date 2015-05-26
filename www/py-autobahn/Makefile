# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	autobahn
PORTVERSION=	0.9.6
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	WebSocket client & server library, WAMP real-time framework

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.6.1:${PORTSDIR}/devel/py-six
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:${PORTSDIR}/devel/py-pytest \
		${PYTHON_PKGNAMEPREFIX}mock>0:${PORTSDIR}/devel/py-mock

USES=		dos2unix python
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=		ACCELERATE SERIALIZATION
OPTIONS_MULTI=		BACKENDS
OPTIONS_MULTI_BACKENDS=	ASYNCIO TWISTED
OPTIONS_DEFAULT=	ASYNCIO ACCELERATE SERIALIZATION TWISTED

BACKENDS_DESC=		Networking Backends

ACCELERATE_DESC=	WebSocket and JSON Acceleration
ASYNCIO_DESC=		asyncio (PEP-3156 aka "Tulip") Backend
SERIALIZATION_DESC=	WAMPv2 Binary Serialization
TWISTED_DESC=		Twisted Backend (Python 2.x ONLY)

ACCELERATE_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}wsaccel>=0.6.2:${PORTSDIR}/www/py-wsaccel \
				${PYTHON_PKGNAMEPREFIX}ujson>=1.33:${PORTSDIR}/devel/py-ujson
SERIALIZATION_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0.4.0:${PORTSDIR}/devel/py-msgpack
TWISTED_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}zope.interface>=3.6:${PORTSDIR}/devel/py-zope.interface
TWISTED_USES=			twisted:run

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MTWISTED} && ${PYTHON_REL} >= 3000
BROKEN=	Twisted currently only supports Python 2.x. Disable the TWISTED option and use ASYNCIO instead
.endif

.if ${PORT_OPTIONS:MASYNCIO} && ${PYTHON_REL} <= 3400
.if ${PYTHON_REL} >= 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}asyncio>=0.2.1:${PORTSDIR}/devel/py-asyncio
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}trollius>=0.1.2:${PORTSDIR}/devel/py-trollius \
		${PYTHON_PKGNAMEPREFIX}futures>=2.1.5:${PORTSDIR}/devel/py-futures
.endif
.endif

.include <bsd.port.post.mk>
