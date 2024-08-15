PORTNAME=	cloud-init
DISTVERSION=	24.1.4
PORTREVISION=	1
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	andrey@bsdnir.info
COMMENT=	Init scripts for use on cloud images
WWW=		https://cloud-init.io/

LICENSE=	APACHE20 GPLv3
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-Apache2.0
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE-GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}boto>0:devel/py-boto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configobj>0:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpatch>0:devel/py-jsonpatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonpointer>0:devel/py-jsonpointer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>0:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauthlib>0:security/py-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		sudo>0:security/sudo

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	canonical
USE_PYTHON=	autoplist distutils
PYDISTUTILS_INSTALLARGS+=	"--init-system=sysvinit_freebsd"

SHEBANG_FILES=	tools/hook-hotplug tools/read-dependencies tools/read-version \
		tools/validate-yaml.py

# Conflicts
CONFLICTS_INSTALL=	cloud-init-devel

# Standard bsd.port.mk variables
ETCDIR=		${PREFIX}/etc/cloud

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${STAGEDIR}${PREFIX}|g' ${WRKSRC}/setup.py
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/cloudinit/settings.py
	${REINPLACE_CMD} -e 's|@@PACKAGED_VERSION@@|${DISTVERSION}${DISTVERSIONSUFFIX}|g' ${WRKSRC}/cloudinit/version.py
	${RM} ${WRKSRC}/config/cloud.cfg.d/99_freebsd.cfg.orig

post-install:
	${MV} ${STAGEDIR}${ETCDIR}/cloud.cfg ${STAGEDIR}${ETCDIR}/cloud.cfg.sample
	${MV} ${STAGEDIR}${ETCDIR}/cloud.cfg.d/05_logging.cfg ${STAGEDIR}${ETCDIR}/cloud.cfg.d/05_logging.cfg.sample
	${MV} ${STAGEDIR}${ETCDIR}/cloud.cfg.d/99_freebsd.cfg ${STAGEDIR}${ETCDIR}/cloud.cfg.d/99_freebsd.cfg.sample
	${REINPLACE_CMD} -e 's|^.*\.cfg$$|@sample &.sample|'  \
		-e 's|${ETCDIR}/clean.d|@dir ${ETCDIR}/clean.d|' \
		${_PYTHONPKGLIST}

.include <bsd.port.mk>
