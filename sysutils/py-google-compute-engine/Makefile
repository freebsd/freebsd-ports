# $FreeBSD$

PORTNAME=	google-compute-engine
DISTVERSION=	2.8.13
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	helen.koike@collabora.com
COMMENT=	Guest Environment for Google Compute Engine

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto>0:devel/py-boto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:net/py-netifaces@${PY_FLAVOR} \
		google_oslogin_control:sysutils/google-compute-engine-oslogin \
		sudo:security/sudo

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes
SHEBANG_FILES=	scripts/google_set_multiqueue scripts/google_optimize_local_ssd

USE_GITHUB=	yes
GH_ACCOUNT=	GoogleCloudPlatform
GH_PROJECT=	compute-image-packages
GH_TAGNAME=	20190124

USE_RC_SUBR=	google_instance_setup \
		google_accounts_daemon \
		google_clock_skew_daemon \
		google_network_daemon \
		google_startup

SUB_LIST=	PYTHON_CMD="${PYTHON_CMD}"
REINPLACE_ARGS=	-i ''

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/syslog.d ${STAGEDIR}/etc
	${INSTALL_DATA} ${FILESDIR}/instance_configs.cfg.distro.sample \
		${STAGEDIR}${PREFIX}/etc/instance_configs.cfg.distro.sample
	${INSTALL_DATA} ${FILESDIR}/90-google.conf.sample \
		${STAGEDIR}${PREFIX}/etc/syslog.d/90-google.conf.sample
	${INSTALL_DATA} ${FILESDIR}/google_set_hostname \
		${STAGEDIR}/etc/dhclient-exit-hooks

.include <bsd.port.mk>
