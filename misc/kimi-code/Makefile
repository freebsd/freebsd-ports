PORTNAME=	kimi-code
DISTVERSION=	2.6.2
CATEGORIES=	misc

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Coding agent for the terminal, driven by the Kimi models
WWW=		https://github.com/MoonshotAI/kimi-code

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/node_modules/${PACKAGE_NAME}/LICENSE

FETCH_DEPENDS=	jq:textproc/jq \
		npm:www/npm \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
RUN_DEPENDS=	git:devel/git \
		rg:textproc/ripgrep

USES=		nodejs:run

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

PLIST_FILES=	bin/kimi

PACKAGE_NAME=	@moonshot-ai/kimi-code
APPDIR=		${PREFIX}/lib/node_modules/${PACKAGE_NAME}
BUNDLE=		${STAGEDIR}${APPDIR}/dist/main.mjs

FETCH_SCRIPT=	${PORTSDIR}/Tools/scripts/npmjs-fetch-with-dependencies.sh

do-fetch:
	@if ! [ -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} ${FETCH_SCRIPT} \
			${PACKAGE_NAME} ${DISTVERSION} \
			${FILESDIR}/package-lock.json \
			${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}; \
	fi

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} node_modules ${STAGEDIR}${PREFIX}/lib
	@${RM} -rf ${STAGEDIR}${APPDIR}/native \
		${STAGEDIR}${APPDIR}/scripts \
		${STAGEDIR}${PREFIX}/lib/node_modules/.bin
	@for s in 'return "npm-global";' \
		'case "unsupported": return `npm install -g $${NPM_PACKAGE_NAME}@$${version}`;' \
		'telemetry !== false'; do \
		${GREP} -qF "$$s" ${BUNDLE} || { \
			${ECHO_MSG} "===> string gone from the bundle: $$s"; \
			${FALSE}; \
		}; \
	done
	${REINPLACE_CMD} -i '' \
		-e 's|return "npm-global";|return "unsupported";|' \
		-e 's|case "unsupported": return `npm install -g $${NPM_PACKAGE_NAME}@$${version}`;|case "unsupported": return "pkg upgrade ${PORTNAME}";|' \
		-e 's|telemetry !== false|telemetry === true|g' \
		${BUNDLE}
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	@${ECHO_CMD} '#!/bin/sh' > ${STAGEDIR}${PREFIX}/bin/kimi
	@${ECHO_CMD} 'exec ${LOCALBASE}/bin/node ${APPDIR}/dist/main.mjs "$$@"' \
		>> ${STAGEDIR}${PREFIX}/bin/kimi
	@${CHMOD} ${BINMODE} ${STAGEDIR}${PREFIX}/bin/kimi

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} lib/node_modules \( -type f -o -type l \) | ${SORT} >> ${TMPPLIST}

.include <bsd.port.mk>
