# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=		autobahn
PORTVERSION=		19.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=		www python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		koobs@FreeBSD.org
COMMENT=		WebSocket client & server library, WAMP real-time framework

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.11.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}txaio>=18.8.1:devel/py-txaio@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.8.6:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=1.3.0:devel/py-mock@${PY_FLAVOR}

USES=		python:3.5+
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	crossbario
GH_PROJECT=	autobahn-python

NO_ARCH=	yes

OPTIONS_DEFINE=		ACCELERATE ENCRYPTION SCRAM SERIALIZATION
OPTIONS_DEFAULT=	ASYNCIO ACCELERATE ENCRYPTION SCRAM SERIALIZATION TWISTED

OPTIONS_FILE=		${PORT_DBDIR}/${OPTIONS_NAME}/${FLAVOR}-options

OPTIONS_MULTI=		BACKENDS
OPTIONS_MULTI_BACKENDS=	ASYNCIO TWISTED

BACKENDS_DESC=		Network Backends

ACCELERATE_DESC=	C-based WebSocket Acceleration
ASYNCIO_DESC=		Asyncronous IO Support
ENCRYPTION_DESC=	TLS Transport / Cryptosign Encryption & Authentication
SCRAM_DESC=		WAMP-SCRAM Authentication support
SERIALIZATION_DESC=	Serializers (MessagePack, CBOR, UBJSON, Flatbuffers)
TWISTED_DESC=		Twisted network backend support

ACCELERATE_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}wsaccel>=0.6.2:www/py-wsaccel@${PY_FLAVOR}
ENCRYPTION_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}openssl>=16.2.0:security/py-openssl@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}service_identity>=16.0.0:security/py-service_identity@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}pynacl>=1.0.1:security/py-pynacl@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}pytrie>=0.2:devel/py-pytrie@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}pyqrcode>=1.1:graphics/py-pyqrcode@${PY_FLAVOR}
SCRAM_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}cffi>=1.11.5:devel/py-cffi@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}argon2-cffi>=18.1.0:security/py-argon2-cffi@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}passlib>=1.7.1:security/py-passlib@${PY_FLAVOR}
SERIALIZATION_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0.6.1:devel/py-msgpack@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}ujson>=1.35:devel/py-ujson@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}cbor2>=4.1.2:devel/py-cbor2@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}cbor>=1.0.0:devel/py-cbor@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}py-ubjson>=0.8.4:devel/py-py-ubjson@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}flatbuffers>=1.10:devel/py-flatbuffers@${PY_FLAVOR}
TWISTED_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}twisted>=12.1.0:devel/py-twisted@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}zope.interface>=3.6.0:devel/py-zope.interface@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} > 3.0
OPTIONS_MULTI_BACKENDS:=	${OPTIONS_MULTI_BACKENDS:NASYNCIO}
COMPLETE_OPTIONS_LIST:=		${COMPLETE_OPTIONS_LIST:NASYNCIO}
PORT_OPTIONS:=			${PORT_OPTIONS:NASYNCIO}
.elif ${PORT_OPTIONS:MASYNCIO}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}trollius>=2.0:devel/py-trollius@${PY_FLAVOR} \
		${PY_FUTURES}
.endif

do-test:
.if ${PORT_OPTIONS:MASYNCIO}
	@cd ${WRKSRC} && USE_ASYNCIO=1 ${PYTHON_CMD} -m pytest -v -rs ${WRKSRC}/autobahn
.endif
.if ${PORT_OPTIONS:MTWISTED}
	@cd ${WRKSRC} && USE_TWISTED=1 ${PYTHON_CMD} -m twisted.trial ${WRKSRC}/autobahn
.endif

.include <bsd.port.post.mk>
