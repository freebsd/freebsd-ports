PORTNAME=		sbws
PORTVERSION=		1.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=		net python
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	Tor network bandwidth scanner
WWW=		https://sbws.readthedocs.io/

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

		# pysocks: indirect dependency via requests[socks]
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysocks>=1.6.8:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.18.4:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stem>=1.7.0:security/py-stem@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.5:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}versioneer>=0:devel/py-versioneer@${PY_FLAVOR} \
		tor:security/tor \
		obfs4proxy:security/obfs4proxy-tor \
		snowflake-client:security/snowflake-tor

		# testing depends on `git` and chutney. not adding that here. see `start_chutney.sh`
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=0:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8>=0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flake8-docstrings>=0:devel/py-flake8-docstrings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>=0:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-mock>=0:devel/py-pytest-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>=0:devel/py-tox@${PY_FLAVOR} \
		bash:shells/bash

USES=		cpe python shebangfix
USE_GITLAB=	yes
USE_PYTHON=	autoplist distutils concurrent flavors

PLIST_FILES=	"@sample ${PREFIX}/etc/sbws.ini.sample"

CPE_VENDOR=	torproject
GL_SITE=	https://gitlab.torproject.org/tpo
GL_ACCOUNT=	network-health
GL_PROJECT=	sbws
GL_TAGNAME=	30a2256098fad8e8aaa06e325274546b4aead552

SHEBANG_FILES=	setup.py \
		sbws/core/bwfile_health.py \
		scripts/maint/release.py \
		scripts/tools/get-per-relay-budget.py \
		scripts/tools/scale-v3bw-with-budget.py \
		tests/integration/async_https_server.py \
		tests/integration/stop_chutney.sh \
		tests/integration/start_chutney.sh \
		tests/integration/run.sh

NO_ARCH=	yes

# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=262759
post-patch:
	${RM} ${WRKSRC}/tests/__init__.py

do-test:
	cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v

post-install:
	${INSTALL_DATA}	${WRKSRC}/docs/source/examples/sbws.example.ini \
		${STAGEDIR}${PREFIX}/etc/sbws.ini.sample

.include <bsd.port.mk>
