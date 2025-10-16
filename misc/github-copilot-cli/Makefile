PORTNAME=	github-copilot-cli
DISTVERSION=	0.0.342
CATEGORIES=	misc # machine-learning
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ${NODE_HEADERS}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GitHub Copilot CLI brings the power of the coding agent to terminal
WWW=		https://github.com/github/copilot-cli

BROKEN_i386=	fails to package due to sharp-freebsd-x64.node file in the plist

FETCH_DEPENDS=	npm:www/npm
BUILD_DEPENDS=	npm:www/npm \
		libsecret>0:security/libsecret \
		vips>=8.17.2:graphics/vips
RUN_DEPENDS=	libsecret>0:security/libsecret \
		vips>=8.17.2:graphics/vips

USES=		nodejs:run pkgconfig python:build

PACKAGE_NAME=	@github/copilot
NODE_HEADERS=	node-v22.19.0-headers

do-fetch:
	@if ! [ -f ${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ] || ! [ -f ${DISTDIR}/${NODE_HEADERS}${EXTRACT_SUFX} ]; then \
		${ECHO} "Fetching ${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}" && \
		${MKDIR} ${WRKDIR}/.npm/_npx/c463d28440264a05 && \
		${CP} ${FILESDIR}/package.json ${WRKDIR}/.npm/_npx/c463d28440264a05 && \
		${SETENV} HOME=${WRKDIR} npm install --ignore-scripts --prefix ${WRKSRC} -g ${PACKAGE_NAME}@${DISTVERSION} && \
		${FIND} ${WRKDIR} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
		(cd ${WRKDIR} && ${FIND} ${PORTNAME}-${DISTVERSION} -print0 | LC_ALL=C ${SORT} -z | \
	        	${TAR} czf ${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} --format=bsdtar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T -) && \
		${ECHO} "Fetching ${NODE_HEADERS}${EXTRACT_SUFX}" && \
		${FETCH_CMD} -q https://nodejs.org/download/release/v22.19.0/${NODE_HEADERS}${EXTRACT_SUFX} -o ${DISTDIR}/${NODE_HEADERS}${EXTRACT_SUFX}; \
	fi

do-build:
	@${SETENV} HOME=${WRKDIR} npm rebuild --prefix ${WRKSRC} -g ${PACKAGE_NAME}@${DISTVERSION} && \
	(cd ${WRKSRC}/lib/node_modules/${PACKAGE_NAME}/node_modules/node-pty && ${SETENV} HOME=${WRKDIR} npm_config_tarball=${DISTDIR}/${NODE_HEADERS}${EXTRACT_SUFX} npm run install) && \
	(cd ${WRKSRC}/lib/node_modules/${PACKAGE_NAME}/node_modules/sharp/src && ${SETENV} HOME=${WRKDIR} PYTHON=${PYTHON_CMD} node-gyp rebuild) && \
	${RM} -rf \
		${WRKSRC}/lib/node_modules/${PACKAGE_NAME}/node_modules/sharp/src/build/Release/obj.target \
		${WRKSRC}/lib/node_modules/${PACKAGE_NAME}/node_modules/sharp/src/build/Release/.deps \
		${WRKSRC}/lib/node_modules/${PACKAGE_NAME}/node_modules/sharp/src/build/Release/node-addon-api \
		${WRKSRC}/lib/node_modules/${PACKAGE_NAME}/node_modules/sharp/src/build/Release/nothing.a \
		${WRKSRC}/lib/node_modules/${PACKAGE_NAME}/node_modules/sharp/src/build/node-addon-api \
		${WRKSRC}/lib/node_modules/${PACKAGE_NAME}/node_modules/sharp/node-addon-api \
		${WRKSRC}/lib/node_modules/${PACKAGE_NAME}/node_modules/sharp/src/build/*.mk \
		${WRKSRC}/lib/node_modules/${PACKAGE_NAME}/node_modules/sharp/src/build/Makefile \
		${WRKSRC}/lib/node_modules/${PACKAGE_NAME}/node_modules/sharp/src/build/binding.Makefile \
		${WRKSRC}/lib/node_modules/${PACKAGE_NAME}/node_modules/sharp/src/build/config.gypi

do-install:
	# install files
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}
	# update
	@${REINPLACE_CMD} -i '' \
		-e "s|#!/usr/bin/env node|#!${PREFIX}/bin/node|" \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/index.js
	# set exec bit
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/index.js

post-install:
	# strip binaries
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME} -path "*/build/*" -name *.node | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
