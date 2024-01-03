PORTNAME=	autobahn
PORTVERSION=	23.6.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	WebSocket client & server library, WAMP real-time framework
WWW=		https://github.com/crossbario/autobahn-python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hyperlink>=21.0.0:www/py-hyperlink@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}txaio>=21.2.1:devel/py-txaio@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	crossbar
USE_GITHUB=	yes
GH_ACCOUNT=	crossbario
GH_PROJECT=	autobahn-python
USE_PYTHON=	autoplist cryptography distutils pytest

OPTIONS_DEFINE=		ACCELERATE COMPRESS ENCRYPTION SCRAM SERIALIZATION
OPTIONS_DEFAULT=	ACCELERATE ASYNCIO ENCRYPTION SCRAM SERIALIZATION \
			TWISTED
OPTIONS_MULTI=		BACKENDS
OPTIONS_MULTI_BACKENDS=	ASYNCIO TWISTED
OPTIONS_FILE=		${PORT_DBDIR}/${OPTIONS_NAME}/${FLAVOR}-options

ACCELERATE_DESC=	C-based WebSocket Acceleration
ASYNCIO_DESC=		Asyncronous IO Support
COMPRESS_DESC=		Compression support
BACKENDS_DESC=		Network Backends
ENCRYPTION_DESC=	TLS Transport / Cryptosign Encryption & Authentication
SCRAM_DESC=		WAMP-SCRAM Authentication support
SERIALIZATION_DESC=	Serializers (MessagePack, CBOR, UBJSON, Flatbuffers)
TWISTED_DESC=		Twisted network backend support

ACCELERATE_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}wsaccel>=0.6.3:www/py-wsaccel@${PY_FLAVOR}
COMPRESS_RUN_DEPENDS=			${PYTHON_PKGNAMEPREFIX}python-snappy>=0.6.0:archivers/py-python-snappy@${PY_FLAVOR}
ENCRYPTION_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}openssl>=20.0.1:security/py-openssl@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}pynacl>=1.4.0:security/py-pynacl@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}qrcode>=7.3.1:textproc/py-qrcode@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}pytrie>=0.4.0:devel/py-pytrie@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}service-identity>=18.1.0:security/py-service-identity@${PY_FLAVOR}
SCRAM_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}argon2-cffi>=20.1.0:security/py-argon2-cffi@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}cffi>=1.14.5:devel/py-cffi@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}passlib>=1.7.4:security/py-passlib@${PY_FLAVOR}
SERIALIZATION_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cbor2>=5.2.0:devel/py-cbor2@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}flatbuffers>=22.12.6:devel/py-flatbuffers@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}msgpack>=1.0.2:devel/py-msgpack@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}py-ubjson>=0.16.1:devel/py-py-ubjson@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}ujson>=4.0.2:devel/py-ujson@${PY_FLAVOR}
TWISTED_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}attrs>=20.3.0:devel/py-attrs@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}twisted>=20.3.0:devel/py-twisted@${PY_FLAVOR} \
				${PYTHON_PKGNAMEPREFIX}zope.interface>=5.2.0:devel/py-zope.interface@${PY_FLAVOR}

.include <bsd.port.options.mk>

OPTIONS_MULTI_BACKENDS:=	${OPTIONS_MULTI_BACKENDS:NASYNCIO}
COMPLETE_OPTIONS_LIST:=		${COMPLETE_OPTIONS_LIST:NASYNCIO}
PORT_OPTIONS:=			${PORT_OPTIONS:NASYNCIO}

post-stage:
.if exists(${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_nvx_utf8validator.abi3.so)
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_nvx_utf8validator.abi3.so
.endif

do-test-ASYNCIO-on:
	@cd ${WRKSRC} && USE_ASYNCIO=1 ${PYTHON_CMD} -m pytest -v -rs ${WRKSRC}/autobahn

do-test-TWISTED-on:
	@cd ${WRKSRC} && USE_TWISTED=1 ${PYTHON_CMD} -m twisted.trial ${WRKSRC}/autobahn

.include <bsd.port.mk>
