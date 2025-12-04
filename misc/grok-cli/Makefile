PORTNAME=	grok-cli
DISTVERSION=	0.0.34
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open-source AI agent bringing Grok to your terminal
WWW=		https://github.com/superagent-ai/grok-cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/node_modules/${PACKAGE_NAME}/LICENSE

FETCH_DEPENDS=	npm:www/npm \
		jq:textproc/jq
RUN_DEPENDS=	rg:textproc/ripgrep

USES=		nodejs:run

NO_BUILD=	yes
NO_ARCH=	yes

PACKAGE_NAME=	@vibe-kit/grok-cli

FETCH_SCRIPT=	${PORTSDIR}/Tools/scripts/npmjs-fetch-with-dependencies.sh

do-fetch:
	@if ! [ -f ${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ]; then \
		${SETENV} TMPDIR=${WRKDIR} ${FETCH_SCRIPT} \
			${PACKAGE_NAME} ${DISTVERSION} \
			${FILESDIR}/package-lock.json \
			${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}; \
	fi

do-install:
	# install files
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} node_modules ${STAGEDIR}${PREFIX}/lib
	# update shebang
	${REINPLACE_CMD} -i '' \
		-e "s|#!/usr/bin/env node|#!${PREFIX}/bin/node|" \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/dist/index.js
	# set exec bit
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/dist/index.js
	# create wrapper script
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	@${ECHO_CMD} '#!/bin/sh' > ${STAGEDIR}${PREFIX}/bin/grok
	@${ECHO_CMD} 'exec ${PREFIX}/lib/node_modules/${PACKAGE_NAME}/dist/index.js "$$@"' >> ${STAGEDIR}${PREFIX}/bin/grok
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/grok

.include <bsd.port.mk>
