PORTNAME=	bun-decompile
DISTVERSION=	0.2.0
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extract and de-minify source code from Bun-compiled executables
WWW=		https://github.com/shepherdjerred/monorepo/tree/main/packages/bun-decompile

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/node_modules/${PACKAGE_NAME}/LICENSE

FETCH_DEPENDS=	curl:ftp/curl \
		jq:textproc/jq \
		npm:www/npm \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

RUN_DEPENDS=	bun:lang/bun

NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/bun-decompile-${DISTVERSION}

PACKAGE_NAME=	@shepherdjerred/bun-decompile

FETCH_SCRIPT=	${PORTSDIR}/Tools/scripts/npmjs-fetch-with-dependencies.sh

do-fetch:
	@if ! [ -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${SETENV} TMPDIR=${WRKDIR} LOCALBASE=${LOCALBASE} ${FETCH_SCRIPT} \
			${PACKAGE_NAME} ${DISTVERSION} \
			${FILESDIR}/package-lock.json \
			${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}; \
	fi

do-install:
	# install node_modules
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} node_modules ${STAGEDIR}${PREFIX}/lib
	# create wrapper script
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	@${ECHO_CMD} '#!/bin/sh' > ${STAGEDIR}${PREFIX}/bin/bun-decompile
	@${ECHO_CMD} 'exec bun ${PREFIX}/lib/node_modules/${PACKAGE_NAME}/src/index.ts "$$@"' >> ${STAGEDIR}${PREFIX}/bin/bun-decompile
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/bin/bun-decompile

.include <bsd.port.mk>
