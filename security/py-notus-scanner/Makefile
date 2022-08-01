PORTNAME=	notus-scanner
DISTVERSION=	22.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	scanner for creating results from local security checks

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry2setup>0:devel/py-poetry2setup@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paho-mqtt>0:net/py-paho-mqtt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gnupg>0:security/py-python-gnupg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tomli>0:textproc/py-tomli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentry-sdk>0:devel/py-sentry-sdk@${PY_FLAVOR} \
		mosquitto:net/mosquitto

USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	${PORTNAME}

USES=		python:3.8+
USE_PYTHON=	distutils

NO_ARCH=	yes

USERS=		gvm
GROUPS=		${USERS}

USE_RC_SUBR=	${PORTNAME:S/-/_/}
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

post-patch:
	${REINPLACE_CMD} -i "" -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/notus/scanner/cli/parser.py
	${REINPLACE_CMD} -i "" -e 's|/etc/openvas/gnupg|/var/lib/openvas/gnupg|g' \
		${WRKSRC}/notus/scanner/loader/gpg_sha_verifier.py
	@${RM} ${WRKSRC}/notus/scanner/cli/parser.py.orig
	@${RM} ${WRKSRC}/notus/scanner/config.py.orig

pre-configure:
	@cd ${WRKSRC} && poetry2setup > ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/notus-scanner
	@${MKDIR} ${STAGEDIR}/var/lib/openvas/plugins/notus/products
	@${MKDIR} ${STAGEDIR}/var/lib/notus

.include <bsd.port.mk>
