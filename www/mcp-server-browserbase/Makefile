PORTNAME=	mcp-server-browserbase
DISTVERSION=	3.0.0
CATEGORIES=	www # machine-learning
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MCP server allowing LLMs control browser with Browserbase, Stagehand
WWW=		https://github.com/browserbase/mcp-server-browserbase

LICENSE=	MIT

FETCH_DEPENDS=	npm:www/npm \
		jq:textproc/jq \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		nodejs:run

PACKAGE_NAME=	@browserbasehq/mcp

WRKSRC=		${WRKDIR}/mcp-${DISTVERSION}

DD=		${DISTDIR}/${DIST_SUBDIR}

FETCH_SCRIPT=	${PORTSDIR}/Tools/scripts/npmjs-fetch-with-dependencies.sh

TOP_JS=		lib/node_modules/${PORTNAME}/node_modules/.bin/${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

do-fetch:
	@${MKDIR} ${DD}
	@if ! [ -f ${DD}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO} "====> Fetching ${DISTNAME}${EXTRACT_SUFX}" && \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} ${FETCH_SCRIPT} \
			${PACKAGE_NAME} ${DISTVERSION} \
			${FILESDIR}/package-lock.json \
			${DD}/${DISTNAME}${EXTRACT_SUFX}; \
	fi

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}
	${RLN} ${STAGEDIR}${PREFIX}/${TOP_JS} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	# Update shebang
	${REINPLACE_CMD} -i '' -e '1s|#!/usr/bin/env node|#!${LOCALBASE}/bin/node|' \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}/node_modules/${PACKAGE_NAME}/cli.js
	# make the top file executable
	${CHMOD} +x ${STAGEDIR}${PREFIX}/${TOP_JS}

.include <bsd.port.mk>
