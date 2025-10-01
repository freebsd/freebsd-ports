PORTNAME=	github-copilot-cli
DISTVERSION=	0.0.330
PORTREVISION=	1
CATEGORIES=	misc # machine-learning
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ${NODE_HEADERS}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GitHub Copilot CLI brings the power of the coding agent to terminal
WWW=		https://github.com/github/copilot-cli

FETCH_DEPENDS=	npm:www/npm
BUILD_DEPENDS=	npm:www/npm \
		libsecret>0:security/libsecret
RUN_DEPENDS=	libsecret>0:security/libsecret

USES=		nodejs:run pkgconfig

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
	(cd ${WRKSRC}/lib/node_modules/${PACKAGE_NAME}/node_modules/keytar-forked-forked && ${SETENV} HOME=${WRKDIR} npm run install)

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

.include <bsd.port.mk>
