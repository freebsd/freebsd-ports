PORTNAME=	pdf-reader-mcp
DISTVERSION=	2.3.0
CATEGORIES=	textproc # machine-learning
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MCP server providing tools to read PDF files
WWW=		https://github.com/SylphxAI/pdf-reader-mcp

LICENSE=	MIT

FETCH_DEPENDS=	npm:www/npm \
		jq:textproc/jq \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		nodejs:run

PACKAGE_NAME=	@sylphx/pdf-reader-mcp

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
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}
	${RLN} ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}/node_modules/${PACKAGE_NAME}/dist/index.js ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	# Update shebang
	${REINPLACE_CMD} -i '' -e '1s|#!/usr/bin/env node|#!${LOCALBASE}/bin/node|' \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}/node_modules/${PACKAGE_NAME}/dist/index.js
	${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}/node_modules/${PACKAGE_NAME}/dist/index.js
	# Add polyfills
	@${ECHO} "import 'data:text/javascript,globalThis.DOMMatrix=class{constructor(){this.a=1;this.b=0;this.c=0;this.d=1;this.e=0;this.f=0}};globalThis.ImageData=class{constructor(w,h){this.width=w;this.height=h;this.data=new Uint8ClampedArray(w*h*4)}};globalThis.Path2D=class{constructor(){}addPath(){}};';" > ${WRKDIR}/polyfills.js
	@${SED} -i '' '1r ${WRKDIR}/polyfills.js' ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}/node_modules/${PACKAGE_NAME}/dist/index.js
	# Suppress warnings in pdfjs-dist
	${REINPLACE_CMD} -i '' \
		-e '/warn(`Cannot load "@napi-rs\/canvas" package/d' \
		-e '/warn("Cannot polyfill `DOMMatrix`/d' \
		-e '/warn("Cannot polyfill `ImageData`/d' \
		-e '/warn("Cannot polyfill `Path2D`/d' \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}/node_modules/pdfjs-dist/legacy/build/pdf.mjs

.include <bsd.port.mk>
