PORTNAME=	clawhub
DISTVERSION=	0.12.0
CATEGORIES=	misc # machine-learning
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	ClawHub CLI for managing OpenClaw agent skills
WWW=		https://clawhub.ai/ \
		https://github.com/openclaw/clawhub

LICENSE=	MIT

FETCH_DEPENDS=	npm:www/npm \
		jq:textproc/jq \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		nodejs:run

PACKAGE_NAME=	clawhub

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

DD=		${DISTDIR}/${DIST_SUBDIR}

FETCH_SCRIPT=	${PORTSDIR}/Tools/scripts/npmjs-fetch-with-dependencies.sh

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
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} node_modules ${STAGEDIR}${PREFIX}/lib
	# Update shebang
	${REINPLACE_CMD} -i '' \
		-e "s|#!/usr/bin/env node|#!${PREFIX}/bin/node|" \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}/bin/clawdhub.js
	@${CHMOD} +x \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}/bin/clawdhub.js
	# Create wrapper scripts
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	@${ECHO_CMD} '#!/bin/sh' > ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${ECHO_CMD} 'exec ${PREFIX}/lib/node_modules/${PORTNAME}/bin/clawdhub.js "$$@"' \
		>> ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${LN} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/clawdhub

.include <bsd.port.mk>
