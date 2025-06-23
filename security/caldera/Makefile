PORTNAME=	caldera
DISTVERSION=	5.2.0
PORTREVISION=	3
CATEGORIES=	security python

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Automated Adversary Emulation Platform
WWW=		https://github.com/mitre/caldera

CONFLICTS=	caldera4

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expired www/npm-node18
EXPIRATION_DATE=2025-09-01

BUILD_DEPENDS=	npm-node18>0:www/npm-node18
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp-jinja2>0:www/py-aiohttp-jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp-session>0:www/py-aiohttp-session@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp-security>0:security/py-aiohttp-security@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp-apispec>0:devel/py-aiohttp-apispec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>0:devel/py-websockets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>0:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx_rtd_theme>0:textproc/py-sphinx_rtd_theme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}myst-parser>0:textproc/py-myst-parser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}marshmallow>0:devel/py-marshmallow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dirhash>0:security/py-dirhash@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docker>0:sysutils/py-docker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}donut-shellcode>0:devel/py-donut-shellcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}marshmallow-enum>0:devel/py-marshmallow-enum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ldap3>0:net/py-ldap3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>0:print/py-reportlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}svglib>0:converters/py-svglib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>0:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asyncssh>0:security/py-asyncssh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aioftp>0:ftp/py-aioftp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyautogui>0:x11/py-pyautogui@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}selenium>0:www/py-selenium@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webdriver_manager>0:www/py-webdriver_manager@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}croniter2>0:sysutils/py-croniter2@${PY_FLAVOR} \
		upx>0:archivers/upx \
		base64>0:converters/base64 \
		git>0:devel/git \
		bash>0:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	mitre
GH_PROJECT=	${PORTNAME}
GH_TUPLE=	mitre:access:775181b:access/plugins/access \
		mitre:atomic:4f489bb:atomic/plugins/atomic \
		mitre:builder:2991945:builder/plugins/builder \
		mitre:compass:85e2ebf:compass/plugins/compass \
		mitre:debrief:eba44d5:debrief/plugins/debrief \
		mitre:emu:4d442bc:emu/plugins/emu \
		mitre:fieldmanual:2eb2e93:fieldmanual/plugins/fieldmanual \
		mitre:gameboard:dacb6ce:gameboard/plugins/gameboard \
		mitre:human:fd242d7:human/plugins/human \
		mitre:magma:32b5594:magma/plugins/magma \
		mitre:manx:8adc3c8:manx/plugins/manx \
		mitre:response:8ea6ab5:response/plugins/response \
		mitre:sandcat:0a35cd5:sandcat/plugins/sandcat \
		mitre:ssl:1ae8431:ssl/plugins/ssl \
		mitre:stockpile:fcd1eea:stockpile/plugins/stockpile \
		mitre:training:37f998f:training/plugins/training

USES=		dos2unix go:run nodejs:18,build python
USE_PYTHON=	cryptography

NO_ARCH=	yes

DOS2UNIX_REGEX= .*\.([yml])
CALDERA_USER=	caldera
CALDERA_GROUP=	caldera
USERS=		${CALDERA_USER}
GROUPS=		${CALDERA_GROUP}

USE_RC_SUBR=	${PORTNAME:S/-/_/}
SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		WWWDIR=${WWWDIR}

OPTIONS_DEFINE=	HAPROXY
OPTIONS_DEFAULT=HAPROXY
HAPROXY_DESC=	Support for HTTPS
HAPROXY_RUN_DEPENDS=haproxy24>0:net/haproxy24

NPM_BIN=	${LOCALBASE}/bin/npm

# to rebuild the deps archive:
#   1. set DEV_UPDATE_MODE=yes
#   2. make makesum build
#   3. upload the *-cache archive
#   4. set DEV_UPDATE_MODE=no
#   5. make clean makesum

DEV_UPDATE_MODE=	no
DEPS_CACHE_DIR=		${WRKSRC}/plugins/magma

.if (${DEV_UPDATE_MODE} == "yes")
NPM_ARGS=	install
post-build:
	@cd ${DEPS_CACHE_DIR} && ${TAR} czf ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-cache-${DISTVERSION}${EXTRACT_SUFX} node_modules
	@${ECHO} "(!!!) Please upload the cache archive: ${DISTDIR}/${DIST_SUBDIR}/${PORTNAME}-cache-${DISTVERSION}${EXTRACT_SUFX}"
.else
MASTER_SITES+=	LOCAL/acm/caldera/:npm_cache
DISTFILES+=	${PORTNAME}-cache-${DISTVERSION}${EXTRACT_SUFX}:npm_cache \
		${PORTNAME}-freebsd-logos.tar.gz:npm_cache
NPM_ARGS=	run build

post-extract:
	@${MV} ${WRKDIR}/node_modules ${WRKSRC}/plugins/magma/
	@${MV} ${WRKDIR}/freebsd.red.svg ${WRKSRC}/plugins/magma/src/assets/img/graph/freebsd-icon-privileged.svg
	@${MV} ${WRKDIR}/freebsd.black.svg ${WRKSRC}/plugins/magma/src/assets/img/graph/freebsd-icon.svg
	${RM} -R ${WRKSRC}/.github
	cd ${WRKSRC} && ${RM} .coveragerc .dockerignore .eslintrc.js .flake8 \
		.git* .pre* .stylelintrc.json Dockerfile
.endif

post-patch:
	cd ${WRKSRC} && \
		${FIND} . -type f -name "*.orig" -exec ${RM} "{}" \;
	${REINPLACE_CMD} -i "" -e 's|4.2.0|${PORTVERSION}|g' ${WRKSRC}/app/version.py

do-build:
	@cd ${WRKSRC}/plugins/magma && \
		${NPM_BIN} ${NPM_ARGS}

post-build:
	${RM} -r ${WRKSRC}/plugins/magma/node_modules

do-install:
	@${MKDIR} ${STAGEDIR}/${WWWDIR}/ftp_dir
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}

.include <bsd.port.mk>
