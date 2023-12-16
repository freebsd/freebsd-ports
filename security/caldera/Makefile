PORTNAME=	caldera
DISTVERSION=	4.2.0
PORTREVISION=	3
CATEGORIES=	security python

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Automated Adversary Emulation Platform
WWW=		https://github.com/mitre/caldera

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp-jinja2>0:www/py-aiohttp-jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp-session>0:www/py-aiohttp-session@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp-security>0:security/py-aiohttp-security@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}aiohttp-apispec>0:devel/py-aiohttp-apispec@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR} \
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
		${PYTHON_PKGNAMEPREFIX}pyautogui>0:x11/py-pyautogui@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}selenium>0:www/py-selenium@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webdriver_manager>0:www/py-webdriver_manager@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifulsoup>0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}networkx>0:math/py-networkx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		upx>0:archivers/upx \
		base64>0:converters/base64 \
		git>0:devel/git \
		bash>0:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	mitre
GH_PROJECT=	${PORTNAME}
GH_TUPLE=	mitre:access:0e67776:access/plugins/access \
		mitre:atomic:9e2c958:atomic/plugins/atomic \
		mitre:builder:f2ce67c:builder/plugins/builder \
		mitre:compass:fb88e02:compass/plugins/compass \
		mitre:debrief:e4d4f9e:debrief/plugins/debrief \
		mitre:emu:02a0f3e:emu/plugins/emu \
		mitre:fieldmanual:c286e77:fieldmanual/plugins/fieldmanual \
		mitre:gameboard:3d98c32:gameboard/plugins/gameboard \
		mitre:human:4368dea:human/plugins/human \
		mitre:manx:e7205ea:manx/plugins/manx \
		mitre:response:889213a:response/plugins/response \
		mitre:sandcat:7c326bd:sandcat/plugins/sandcat \
		mitre:ssl:ac5bfcb:ssl/plugins/ssl \
		mitre:stockpile:960f9ad:stockpile/plugins/stockpile \
		mitre:training:b058b67:training/plugins/training

USES=		dos2unix go:run python
USE_PYTHON=	cryptography

NO_ARCH=	yes
NO_BUILD=	yes

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
HAPROXY_RUN_DEPENDS=haproxy20>0:net/haproxy20

post-extract:
	${RM} -R ${WRKSRC}/.github
	cd ${WRKSRC} && ${RM} .coveragerc .dockerignore .eslintrc.js .flake8 \
		.git* .pre* .stylelintrc.json Dockerfile

post-patch:
	cd ${WRKSRC} && \
		${FIND} . -type f -name "*.orig" -exec ${RM} "{}" \;

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}

.include <bsd.port.mk>
