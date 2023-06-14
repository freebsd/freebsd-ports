PORTNAME=	reticulum
DISTVERSION=	0.5.5
CATEGORIES=	net-p2p
MASTER_SITES=	PYPI
DISTNAME=	rns-${DISTVERSION}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Self-configuring, encrypted and resilient mesh networking stack
WWW=		https://reticulum.network/

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils
USE_RC_SUBR=	reticulum
GROUPS=		_reticulum
USERS=		_reticulum
SUB_LIST=	USERS="${USERS}" \
		GROUPS="${GROUPS}" \
		PYTHON=${PYTHON_CMD}
PLIST_SUB=	USERS="${USERS}" GROUPS="${GROUPS}"

NO_ARCH=	yes

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}/var/db/reticulum ${STAGEDIR}/var/run/reticulum ${STAGEDIR}/var/log/reticulum
	${INSTALL_DATA} ${PATCHDIR}/config.sample ${STAGEDIR}${ETCDIR}/config.sample

.include <bsd.port.mk>
