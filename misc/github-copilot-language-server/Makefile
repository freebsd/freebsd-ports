PORTNAME=	github-copilot-language-server
DISTVERSION=	1.380.0
PORTREVISION=	1
CATEGORIES=	misc # machine-learning
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GitHub Copilot Language Server
WWW=		https://github.com/github/copilot-language-server-release

FETCH_DEPENDS=	npm:www/npm
BUILD_DEPENDS=	npm:www/npm

USES=		nodejs:run

PACKAGE_NAME=	@github/copilot-language-server

do-fetch:
	@if ! [ -f ${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ]; then \
		${ECHO} "Fetching ${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}" && \
		${MKDIR} ${WRKDIR}/.npm/_npx/c463d28440264a05 && \
		${SETENV} HOME=${WRKDIR} npm install --ignore-scripts --prefix ${WRKSRC} -g ${PACKAGE_NAME}@${DISTVERSION} && \
		${FIND} ${WRKDIR} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
		(cd ${WRKDIR} && ${FIND} ${PORTNAME}-${DISTVERSION} -print0 | LC_ALL=C ${SORT} -z | \
	        	${TAR} czf ${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} --format=bsdtar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T -); \
	fi

do-build:
	@${SETENV} HOME=${WRKDIR} npm rebuild --prefix ${WRKSRC} -g ${PACKAGE_NAME}@${DISTVERSION}

do-install:
	# install files
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}
	# update
	@${REINPLACE_CMD} -i '' \
		-e "s|#!/usr/bin/env node|#!${PREFIX}/bin/node|" \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/dist/language-server.js
	# set exec bit
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/dist/language-server.js

.include <bsd.port.mk>
