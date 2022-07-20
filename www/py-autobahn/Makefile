PORTNAME=	autobahn
PORTVERSION=	21.2.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	WebSocket client & server library, WAMP real-time framework

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=2.9.2:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hyperlink>=20.0.1:www/py-hyperlink@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}txaio>=20.4.1:devel/py-txaio@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=2.8.6:devel/py-pytest@${PY_FLAVOR}

USES=		cpe python:3.5+
CPE_VENDOR=	crossbar
USE_GITHUB=	yes
GH_ACCOUNT=	crossbario
GH_PROJECT=	autobahn-python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

OPTIONS_DEFINE=		ACCELERATE ENCRYPTION SCRAM SERIALIZATION
OPTIONS_DEFAULT=	ACCELERATE ASYNCIO ENCRYPTION SCRAM SERIALIZATION \
			TWISTED
OPTIONS_MULTI=		BACKENDS
OPTIONS_MULTI_BACKENDS=	ASYNCIO TWISTED
OPTIONS_FILE=		${PORT_DBDIR}/${OPTIONS_NAME}/${FLAVOR}-options

ACCELERATE_DESC=	C-based WebSocket Acceleration
ASYNCIO_DESC=		Asyncronous IO Support
BACKENDS_DESC=		Network Backends
ENCRYPTION_DESC=	TLS Transport / Cryptosign Encryption & Authentication
SCRAM_DESC=		WAMP-SCRAM Authentication support
SERIALIZATION_DESC=	Serializers (MessagePack, CBOR, UBJSON, Flatbuffers)
TWISTED_DESC=		Twisted network backend support

ACCELERATE_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}wsaccel>=0.6.2:www/py-wsaccel@${PY_FLAVOR}
ENCRYPTION_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}openssl>=16.2.0:security/py-openssl@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}pynacl>=1.0.1:security/py-pynacl@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}pyqrcode>=1.1:graphics/py-pyqrcode@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}pytrie>=0.2:devel/py-pytrie@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}service_identity>=18.1.0:security/py-service_identity@${PY_FLAVOR}
SCRAM_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}argon2-cffi>=18.1.0:security/py-argon2-cffi@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}cffi>=1.11.5:devel/py-cffi@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}passlib>=1.7.1:security/py-passlib@${PY_FLAVOR}
SERIALIZATION_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cbor2>=5.0.1:devel/py-cbor2@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}cbor>=1.0.0:devel/py-cbor@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}flatbuffers>=1.10:devel/py-flatbuffers@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}msgpack>=0.6.1:devel/py-msgpack@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}py-ubjson>=0.8.4:devel/py-py-ubjson@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}ujson>=1.35:devel/py-ujson@${PY_FLAVOR}
TWISTED_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}attrs>=19.2.0:devel/py-attrs@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}twisted>=20.3.0:devel/py-twisted@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}zope.interface>=3.6.0:devel/py-zope.interface@${PY_FLAVOR}

.include <bsd.port.options.mk>

OPTIONS_MULTI_BACKENDS:=	${OPTIONS_MULTI_BACKENDS:NASYNCIO}
COMPLETE_OPTIONS_LIST:=		${COMPLETE_OPTIONS_LIST:NASYNCIO}
PORT_OPTIONS:=			${PORT_OPTIONS:NASYNCIO}

do-test:
.if ${PORT_OPTIONS:MASYNCIO}
	@cd ${WRKSRC} && USE_ASYNCIO=1 ${PYTHON_CMD} -m pytest -v -rs ${WRKSRC}/autobahn
.endif
.if ${PORT_OPTIONS:MTWISTED}
	@cd ${WRKSRC} && USE_TWISTED=1 ${PYTHON_CMD} -m twisted.trial ${WRKSRC}/autobahn
.endif

.include <bsd.port.mk>
