PORTNAME=	npm
PORTVERSION=	12.2.0
CATEGORIES=	www
MASTER_SITES=	https://registry.npmjs.org/${PORTNAME}/-/
PKGNAMESUFFIX=	${NODEJS_SUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Node package manager
WWW=		https://www.npmjs.com/package/npm \
		https://docs.npmjs.com/ \
		https://github.com/npm/cli

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	gmake:devel/gmake

USES?=		nodejs:24,run
USES+=		cpe python shebangfix tar:tgz
CPE_VENDOR=	npmjs
SHEBANG_GLOB=	*.py

CONFLICTS_INSTALL=	npm-node[0-9][0-9]

REINPLACE_ARGS=	-i ''
NO_ARCH=	yes
NO_BUILD=	yes
PORTSCOUT=	ignore:1

WRKSRC=		${WRKDIR}/package

NPM_DIR=	lib/node_modules/npm
# Executables of the bundled dependencies, as linked by "npm install"
NPM_BINS=	arborist:@npmcli/arborist/bin/index.js cssesc:cssesc/bin/cssesc \
		installed-package-contents:@npmcli/installed-package-contents/bin/index.js \
		node-gyp:node-gyp/bin/node-gyp.js node-which:which/bin/which.js \
		nopt:nopt/bin/nopt.js pacote:pacote/bin/index.js \
		qrcode-terminal:qrcode-terminal/bin/qrcode-terminal.js \
		semver:semver/bin/semver.js

post-patch:
	@${REINPLACE_CMD} -e '/^exec/ s|python|${PYTHON_CMD}|' ${WRKSRC}/node_modules/node-gyp/gyp/gyp
	@${FIND} ${WRKSRC}/ -name '*.bak' -delete
	@${RM} ${WRKSRC}/node_modules/node-gyp/macOS_Catalina_acid_test.sh

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${NPM_DIR}/node_modules/.bin ${STAGEDIR}${PREFIX}/etc/man.d
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${NPM_DIR}/
	${FIND} ${STAGEDIR}${PREFIX}/${NPM_DIR}/man -type f -exec ${GZIP_CMD} {} +
	${ECHO_CMD} "MANPATH ${PREFIX}/${NPM_DIR}/man" > ${STAGEDIR}${PREFIX}/etc/man.d/npm.conf
	${RLN} ${STAGEDIR}${PREFIX}/${NPM_DIR}/bin/npm-cli.js ${STAGEDIR}${PREFIX}/bin/npm
	${RLN} ${STAGEDIR}${PREFIX}/${NPM_DIR}/bin/npx-cli.js ${STAGEDIR}${PREFIX}/bin/npx
	${RLN} ${STAGEDIR}${PREFIX}/${NPM_DIR}/node_modules/node-gyp/bin/node-gyp.js ${STAGEDIR}${PREFIX}/bin/node-gyp
.for bin in ${NPM_BINS}
	${RLN} ${STAGEDIR}${PREFIX}/${NPM_DIR}/node_modules/${bin:C/^[^:]*://} ${STAGEDIR}${PREFIX}/${NPM_DIR}/node_modules/.bin/${bin:C/:.*//}
.endfor
	${PYTHON_CMD} -m compileall -d ${PREFIX}/${NPM_DIR}/node_modules/node-gyp/gyp -f ${STAGEDIR}${PREFIX}/${NPM_DIR}/node_modules/node-gyp/gyp -o 0 -o 1

.include <bsd.port.mk>
