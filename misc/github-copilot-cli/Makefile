PORTNAME=	github-copilot-cli
DISTVERSION=	0.0.330
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GitHub Copilot CLI brings the power of the coding agent to terminal
WWW=		https://github.com/github/copilot-cli

FETCH_DEPENDS=	npm:www/npm
BUILD_DEPENDS=	npm:www/npm \
		libsecret>0:security/libsecret
RUN_DEPENDS=	libsecret>0:security/libsecret

USES=		nodejs:run pkgconfig

PACKAGE_NAME=	@github/copilot

do-fetch:
	@if ! [ -f ${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ]; then \
		${SETENV} HOME=${WRKDIR} npm install --ignore-scripts --prefix ${WRKSRC} -g ${PACKAGE_NAME}@${DISTVERSION} && \
		${FIND} ${WRKDIR} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
		cd ${WRKDIR} && ${FIND} ${PORTNAME}-${DISTVERSION} -print0 | LC_ALL=C ${SORT} -z | \
	        	${TAR} czf ${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} --format=bsdtar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T -; \
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
		${STAGEDIR}${PREFIX}/lib/node_modules/@github/copilot/index.js
	# set exec bit
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/node_modules/@github/copilot/index.js

.include <bsd.port.mk>
