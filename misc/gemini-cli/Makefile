PORTNAME=	gemini-cli
DISTVERSION=	0.9.0
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open-source CLI for direct access to Google's Gemini AI model
WWW=		https://geminicli.com/ \
		https://google-gemini.github.io/gemini-cli/ \
		https://github.com/google-gemini/gemini-cli

LICENSE=	APACHE20

FETCH_DEPENDS=	npm:www/npm

USES=		nodejs:run

NO_BUILD=	yes
NO_ARCH=	yes

PACKAGE_NAME=	@google/gemini-cli

do-fetch:
	@if ! [ -f ${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ]; then ( \
		${MKDIR} -p ${WRKDIR}/${PORTNAME}-${DISTVERSION} && \
		cd ${WRKDIR}/${PORTNAME}-${DISTVERSION} && \
		if [ -f ${FILESDIR}/package-lock.json ]; then \
			${ECHO} '{"name":"gemini-cli-installer","version":"1.0.0","dependencies":{"${PACKAGE_NAME}":"^${DISTVERSION}"}}' > package.json && \
			${CP} ${FILESDIR}/package-lock.json . ; \
			${SETENV} HOME=${WRKDIR} npm ci --ignore-scripts --global-style --legacy-peer-deps --omit=dev ; \
		else \
			${ECHO} '{"name":"gemini-cli-installer","version":"1.0.0"}' > package.json && \
			npm install --package-lock-only --global-style --legacy-peer-deps ${PACKAGE_NAME}@${DISTVERSION} && \
			${CP} package-lock.json ${WRKDIR}/package-lock.json.generated && \
			${ECHO} "" && \
			${ECHO} "=====================================================================" && \
			${ECHO} "WARNING: package-lock.json not found in files/ directory" && \
			${ECHO} "Generated one at: ${WRKDIR}/package-lock.json.generated" && \
			${ECHO} "" && \
			${ECHO} "To enable reproducible builds, please:" && \
			${ECHO} "  1. mkdir -p ${.CURDIR}/files" && \
			${ECHO} "  2. cp ${WRKDIR}/package-lock.json.generated ${.CURDIR}/files/package-lock.json" && \
			${ECHO} "  3. Re-run 'make clean distclean && make fetch'" && \
			${ECHO} "=====================================================================" && \
			${ECHO} "" && \
			${SETENV} HOME=${WRKDIR} npm ci --ignore-scripts --global-style --legacy-peer-deps --omit=dev ; \
		fi && \
		${MKDIR} -p lib/node_modules/@google && \
		${MKDIR} -p bin && \
		${MV} node_modules/${PACKAGE_NAME} lib/node_modules/@google/ && \
		${LN} -sf ../lib/node_modules/${PACKAGE_NAME}/dist/index.js bin/gemini && \
		${RM} -rf node_modules package.json && \
		${FIND} ${WRKDIR} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
		cd ${WRKDIR} && ${FIND} ${PORTNAME}-${DISTVERSION} -print0 | LC_ALL=C ${SORT} -z | \
			${TAR} czf ${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} --format=bsdtar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T - \
	); fi

do-install:
	# install files
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}
	# update
	${REINPLACE_CMD} -i '' \
		-e "s|#!/usr/bin/env node|#!${PREFIX}/bin/node|" \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/dist/index.js
	# set exec bit
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/dist/index.js

.include <bsd.port.mk>
