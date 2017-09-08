# $FreeBSD$

PORTNAME=	google-compute-engine
PORTVERSION=	2.4.1
PORTREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	helen.koike@collabora.com
COMMENT=	Guest Environment for Google Compute Engine

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto>0:devel/py-boto \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:net/py-netifaces \
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

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/google_compute_engine/accounts/accounts_utils.py \
		${WRKSRC}/google_compute_engine/boto/boto_config.py \
		${WRKSRC}/google_compute_engine/boto/compute_auth.py \
		${WRKSRC}/google_compute_engine/config_manager.py \
		${WRKSRC}/google_compute_engine/instance_setup/instance_config.py \
		${WRKSRC}/google_compute_engine/metadata_scripts/script_executor.py \
		${WRKSRC}/google_compute_engine/network_setup/network_setup.py

.include <bsd.port.mk>
