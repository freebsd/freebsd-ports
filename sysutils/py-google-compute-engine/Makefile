# $FreeBSD$

PORTNAME=	google-compute-engine
PORTVERSION=	2.6.1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	helen.koike@collabora.com
COMMENT=	Guest Environment for Google Compute Engine

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto>0:devel/py-boto@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:net/py-netifaces@${FLAVOR} \
		sudo:security/sudo

USES=		python
USE_PYTHON=	autoplist concurrent distutils

USE_RC_SUBR=	google_instance_setup \
		google_network_setup \
		google_accounts_daemon \
		google_clock_skew_daemon \
		google_ip_forwarding_daemon \
		google_startup

NO_ARCH=	yes

SUB_LIST=	PYTHON_CMD="${PYTHON_CMD}"
REINPLACE_ARGS=	-i ''

post-install:
	${INSTALL_DATA} ${FILESDIR}/instance_configs.cfg.distro.sample \
		${STAGEDIR}${PREFIX}/etc/instance_configs.cfg.distro.sample

.include <bsd.port.mk>
