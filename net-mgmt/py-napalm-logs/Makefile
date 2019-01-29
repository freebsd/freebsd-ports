# $FreeBSD$

PORTNAME=	napalm-logs
DISTVERSION=	0.7.0
CATEGORIES=	net-mgmt python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd_ports@k-worx.org
COMMENT=	Cross-vendor normalisation for network syslog messages

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pynacl>0:security/py-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzmq>0:net/py-pyzmq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}u-msgpack-python>0:devel/py-u-msgpack-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>0:net-mgmt/py-prometheus-client@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils concurrent autoplist

NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PREFIX=${PREFIX} PYTHON_VER=${PYTHON_VER}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/napalm_logs/config/__init__.py

.include <bsd.port.mk>
