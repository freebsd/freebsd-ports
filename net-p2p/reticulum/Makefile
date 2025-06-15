PORTNAME=	reticulum
DISTVERSION=	0.9.6
CATEGORIES=	net-p2p

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Self-configuring, encrypted and resilient mesh networking stack
WWW=		https://reticulum.network/

LICENSE=	UNKNOWN
LICENSE_NAME=	Reticulum License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}netifaces>=0:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR}

WRKSRC=		${WRKDIR}/Reticulum-${PORTVERSION}
USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	markqvist
USE_PYTHON=	cryptography distutils
USE_RC_SUBR=	reticulum
GROUPS=		_reticulum
USERS=		_reticulum
SUB_LIST=	USERS="${USERS}" \
		GROUPS="${GROUPS}" \
		PYTHON=${PYTHON_CMD}
PLIST_SUB=	USERS="${USERS}" GROUPS="${GROUPS}"

NO_ARCH=	yes

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${ETCDIR}/interfaces ${STAGEDIR}/var/db/reticulum \
		${STAGEDIR}/var/run/reticulum ${STAGEDIR}/var/log/reticulum
	${INSTALL_DATA} ${PATCHDIR}/config.sample ${STAGEDIR}${ETCDIR}/config.sample

.include <bsd.port.mk>
