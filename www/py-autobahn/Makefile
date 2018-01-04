# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=		autobahn
PORTVERSION=		0.17.2
DISTVERSIONPREFIX=	v
CATEGORIES=		www python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		koobs@FreeBSD.org
COMMENT=		WebSocket client & server library, WAMP real-time framework

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.6.1:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}txaio>=2.2.0:devel/py-txaio@${FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.7.2:devel/py-pytest@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=1.3.0:devel/py-mock@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}trollius>0:devel/py-trollius@${FLAVOR} # Not really a depends, but the test doesnt skip

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

GH_ACCOUNT=	crossbario
GH_PROJECT=	autobahn-python

OPTIONS_DEFINE=		ACCELERATE SERIALIZATION
OPTIONS_DEFAULT=	ACCELERATE SERIALIZATION

BACKENDS_DESC=		Networking Backends

ACCELERATE_DESC=	WebSocket and JSON Acceleration
SERIALIZATION_DESC=	WAMPv2 Binary Serialization

ACCELERATE_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}wsaccel>=0.6.2:www/py-wsaccel@${FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}ujson>=1.33:devel/py-ujson@${FLAVOR}

SERIALIZATION_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack-python>=0.4.0:devel/py-msgpack-python@${FLAVOR}

.include <bsd.port.pre.mk>

.if ${FLAVOR} == python2
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}zope.interface>=3.6:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=12.1:devel/py-twisted@${FLAVOR}
.elif ${FLAVOR} == python3 && ${PYTHON_REL} <= 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}asyncio>=3.4.3:devel/py-asyncio@${FLAVOR}
.endif

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest autobahn

.include <bsd.port.post.mk>
