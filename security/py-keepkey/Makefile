PORTNAME=	keepkey
PORTVERSION=	7.2.1
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Library for communicating with KeepKey Hardware Wallet
WWW=		https://github.com/keepkey/python-keepkey

LICENSE=	LGPL3

BUILD_DEPENDS=	protoc:devel/protobuf \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ecdsa>=0.9:security/py-ecdsa@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hidapi>=0.7.99.post15:comms/py-hidapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libusb1>=1.6:devel/py-libusb1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mnemonic>=0.8:security/py-mnemonic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=5.29.6:devel/py-protobuf@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_PROJECT=	python-keepkey
GH_TUPLE=	keepkey:device-protocol:b4bf792:devproto/device-protocol \
		keepkey:ethereum-lists:e216e92:ethlist/keepkeylib/eth/ethereum-lists
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

PB_FILES=	messages messages-eos messages-nano messages-cosmos \
		messages-ripple messages-binance messages-tendermint \
		messages-thorchain types exchange

# keepkeylib/exchange.py is built on the dead protobuf3 library (no port) and
# nothing uses it; the generated exchange_pb2 is what keepkeylib imports.
post-patch:
	@${RM} ${WRKSRC}/keepkeylib/exchange.py
# setup.py was not bumped for the 7.2.x releases; use PORTVERSION so the
# metadata is right and the pep517 wheel matches
	@${REINPLACE_CMD} -e "s|version='7.0.3',|version='${PORTVERSION}',|" \
		${WRKSRC}/setup.py

# The bundled *_pb2.py files come from an old protoc and fail with current
# py-protobuf (https://github.com/keepkey/python-keepkey/issues/146);
# regenerate them as build_pb.sh does.
pre-build:
	@${REINPLACE_CMD} -E 's/5000([2-5])/6000\1/' ${WRKSRC}/device-protocol/types.proto
.for f in ${PB_FILES}
	cd ${WRKSRC}/device-protocol && ${LOCALBASE}/bin/protoc \
		--python_out=${WRKSRC}/keepkeylib -I${LOCALBASE}/include -I. ${f}.proto
.endfor
	@${REINPLACE_CMD} -E 's/^import ([^.]+_pb2)/from . import \1/' \
		${WRKSRC}/keepkeylib/*_pb2.py

.include <bsd.port.mk>
