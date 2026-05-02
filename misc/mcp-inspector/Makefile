PORTNAME=	mcp-inspector
DISTVERSION=	0.21.2
CATEGORIES=	misc # machine-learning
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Model Context Protocol inspector
WWW=		https://github.com/modelcontextprotocol/inspector

LICENSE=	APACHE20 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/node_modules/${PACKAGE_NAME}/LICENSE

FETCH_DEPENDS=	npm:www/npm \
		jq:textproc/jq \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		nodejs:run

NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/inspector-${DISTVERSION}

PACKAGE_NAME=	@modelcontextprotocol/inspector

DD=		${DISTDIR}/${DIST_SUBDIR}

FETCH_SCRIPT=	${PORTSDIR}/Tools/scripts/npmjs-fetch-with-dependencies.sh

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
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/lib
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib
	@${FIND} ${STAGEDIR}${PREFIX}/lib -type f -and -name "README.md" -delete
	@${REINPLACE_CMD} -i '' \
		-e "s|#!/usr/bin/env node|#!${PREFIX}/bin/node|" \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/cli/build/cli.js
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/cli/build/cli.js
	@${RLN} -s ${STAGEDIR}${PREFIX}/lib/node_modules/.bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	# remove stray file
	@${RM} \
		${STAGEDIR}${LOCALBASE}/lib/package.json \
		${STAGEDIR}${LOCALBASE}/lib/package-lock.json

.include <bsd.port.mk>
