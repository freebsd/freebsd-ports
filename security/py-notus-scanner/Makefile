PORTNAME=	notus-scanner
DISTVERSION=	22.7.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	scanner for creating results from local security checks
WWW=		https://github.com/greenbone/notus-scanner

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paho-mqtt>0:net/py-paho-mqtt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gnupg>0:security/py-python-gnupg@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}sentry-sdk>0:devel/py-sentry-sdk@${PY_FLAVOR} \
		mosquitto:net/mosquitto

USE_GITHUB=	yes
GH_ACCOUNT=	greenbone
GH_PROJECT=	${PORTNAME}

USES=		python
USE_PYTHON=	pep517

NO_ARCH=	yes

USERS=		gvm
GROUPS=		${USERS}

USE_RC_SUBR=	${PORTNAME:S/-/_/}
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

post-extract:
	${MV} ${WRKSRC}/tests ${WRKSRC}/notus/

post-patch:
	${REINPLACE_CMD} -i "" -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/notus/scanner/cli/parser.py
	${REINPLACE_CMD} -i "" -e 's|/etc/openvas/gnupg|/var/lib/openvas/gnupg|g' \
		${WRKSRC}/notus/scanner/loader/gpg_sha_verifier.py
	${REINPLACE_CMD} '37d' ${WRKSRC}/pyproject.toml
	@${RM} ${WRKSRC}/notus/scanner/cli/parser.py.orig
	@${RM} ${WRKSRC}/notus/scanner/config.py.orig

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/notus-scanner
	@${MKDIR} ${STAGEDIR}/var/lib/openvas/plugins/notus/products
	@${MKDIR} ${STAGEDIR}/var/lib/notus

.include <bsd.port.mk>
