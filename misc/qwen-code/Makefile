PORTNAME=	qwen-code
DISTVERSION=	0.15.3
CATEGORIES=	misc # machine-learning
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Agentic coding tool from Alibaba
WWW=		https://github.com/QwenLM/qwen-code

LICENSE=	APACHE20

FETCH_DEPENDS=	jq:textproc/jq \
		npm:www/npm \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
RUN_DEPENDS=	rg:textproc/ripgrep

USES=		nodejs:run

NO_BUILD=	yes
NO_ARCH=	yes

PACKAGE_NAME=	@qwen-code/qwen-code

FETCH_SCRIPT=	${PORTSDIR}/Tools/scripts/npmjs-fetch-with-dependencies.sh

do-fetch:
	@if ! [ -f ${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ]; then \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} ${FETCH_SCRIPT} \
			${PACKAGE_NAME} ${DISTVERSION} \
			${FILESDIR}/package-lock.json \
			${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}; \
	fi

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} node_modules ${STAGEDIR}${PREFIX}/lib
	# remove bundled ripgrep (we use textproc/ripgrep via RUN_DEPENDS);
	# cli.js falls back to system rg when the builtin path is absent
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/vendor/ripgrep
	# remove macOS-only sandbox profiles
	@${RM} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/sandbox-macos-*.sb
	${REINPLACE_CMD} -i '' \
		-e "s|#!/usr/bin/env node|#!${PREFIX}/bin/node|" \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/cli.js
	${REINPLACE_CMD} -i '' \
		-e 's|settings.merged.general?.enableAutoUpdate !== false|false|g' \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/cli.js
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/cli.js
	# create wrapper script
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	@${ECHO_CMD} '#!/bin/sh' > ${STAGEDIR}${PREFIX}/bin/qwen
	@${ECHO_CMD} 'exec ${PREFIX}/lib/node_modules/${PACKAGE_NAME}/cli.js "$$@"' >> ${STAGEDIR}${PREFIX}/bin/qwen
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/qwen

.include <bsd.port.mk>
