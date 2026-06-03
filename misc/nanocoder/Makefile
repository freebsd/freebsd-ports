PORTNAME=	nanocoder
DISTVERSION=	1.27.0
CATEGORIES=	misc # machine-learning
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Local-first coding agent running in your terminal
WWW=		https://github.com/Nano-Collective/nanocoder

LICENSE=	MIT

FETCH_DEPENDS=	npm:www/npm \
		jq:textproc/jq \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
BUILD_DEPENDS=	npm:www/npm

USES=		nodejs:run

PACKAGE_NAME=	@nanocollective/nanocoder

FETCH_SCRIPT=	${PORTSDIR}/Tools/scripts/npmjs-fetch-with-dependencies.sh

NO_BUILD=	yes

do-fetch:
	@if ! [ -f ${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ]; then \
		${MKDIR} ${DISTDIR} && \
		${ECHO} "====> Fetching ${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}" && \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} ${FETCH_SCRIPT} \
			${PACKAGE_NAME} ${DISTVERSION} \
			${FILESDIR}/package-lock.json \
			${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}; \
	fi

do-install:
	# install files
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib
	# remove unnecessary files
	@${RM} -rf ${STAGEDIR}${PREFIX}/lib/*.json
	# update shebang to use system node
	@${REINPLACE_CMD} -i '' \
		-e "s|#!/usr/bin/env node|#!${PREFIX}/bin/node|" \
		${STAGEDIR}${PREFIX}/lib/node_modules/@nanocollective/nanocoder/node_modules/cli-highlight/dist/cli.js
	# set exec bit
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/node_modules/.bin/${PORTNAME}
	# create symlink in bin
	@${RLN} -s ${STAGEDIR}${PREFIX}/lib/node_modules/.bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
