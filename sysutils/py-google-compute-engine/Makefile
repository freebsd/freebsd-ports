PORTNAME=	google-compute-engine
DISTVERSION=	2.8.17
CATEGORIES=	sysutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Guest Environment for Google Compute Engine

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto>0:devel/py-boto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:net/py-netifaces@${PY_FLAVOR} \
		google_oslogin_control:sysutils/google-compute-engine-oslogin \
		sudo:security/sudo

.if ${FLAVOR:Upy36:Mpy3*}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}distro>0:sysutils/py-distro@${PY_FLAVOR}
.endif

USES=		python:3.6+ shebangfix
USE_PYTHON=	autoplist concurrent distutils

WRKSRC_SUBDIR=	packages/python-google-compute-engine

NO_ARCH=	yes
SHEBANG_FILES=	../google-compute-engine/src/usr/bin/google_optimize_local_ssd \
		../google-compute-engine/src/usr/bin/google_set_multiqueue

USE_GITHUB=	yes
GH_ACCOUNT=	GoogleCloudPlatform
GH_PROJECT=	compute-image-packages
GH_TAGNAME=	20190522

USE_RC_SUBR=	google_accounts_daemon google_clock_skew_daemon \
		google_instance_setup google_network_daemon google_startup

SUB_LIST=	PYTHON_CMD="${PYTHON_CMD}" \
		PYTHON_VER="${PYTHON_VER}"
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
