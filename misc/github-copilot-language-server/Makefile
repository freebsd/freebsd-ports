PORTNAME=	github-copilot-language-server
DISTVERSION=	1.399.0
CATEGORIES=	misc # machine-learning
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${NODE_HEADERS}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GitHub Copilot Language Server
WWW=		https://github.com/github/copilot-language-server-release

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/node_modules/${PACKAGE_NAME}/LICENSE

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	binaries are installed in folders with architecture encoded in them, patches are welcome to fix this limitation

FETCH_DEPENDS=	npm:www/npm \
		jq:textproc/jq
BUILD_DEPENDS=	npm:www/npm \
		krb5>0:security/krb5 \
		sqlite3>0:databases/sqlite3
RUN_DEPENDS=	krb5>0:security/krb5 \
		sqlite3>0:databases/sqlite3 \
		ripgrep>0:textproc/ripgrep

USES=		nodejs:run pkgconfig python:build

WRKSRC=		${WRKDIR}/copilot-language-server-${DISTVERSION}

PACKAGE_NAME=	@github/copilot-language-server

NODE_HEADERS=	node-v24.11.0-headers

JS_ARCH=	${ARCH:S/amd64/x64/:S/aarch64/arm64/}
PLIST_SUB=	JS_ARCH=${JS_ARCH}

DD=		${DISTDIR}/${DIST_SUBDIR}

FETCH_SCRIPT=	${PORTSDIR}/Tools/scripts/npmjs-fetch-with-dependencies.sh

DEP_MODULES=			policy_watcher sqlite3 kerberos
dep_policy_watcher_npm_name=	@vscode/policy-watcher
dep_policy_watcher_version=	1.3.5
dep_sqlite3_npm_name=		@vscode/sqlite3
dep_sqlite3_version=		5.1.10-vscode
dep_kerberos_npm_name=		kerberos
dep_kerberos_version=		7.0.0

.for dep in ${DEP_MODULES}
DISTFILES+=	${dep:S/_/-/g}-${dep_${dep}_version}${EXTRACT_SUFX}
.endfor

#NO_CHECKSUM=	yes

do-fetch:
	@if ! [ -f ${DD}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ] || \
	    ! [ -f ${DD}/${NODE_HEADERS}${EXTRACT_SUFX} ] || \
	    ! [ -f ${DD}/policy-watcher-${dep_policy_watcher_version}${EXTRACT_SUFX} ] || \
	    ! [ -f ${DD}/sqlite3-${dep_sqlite3_version}${EXTRACT_SUFX} ] || \
	    ! [ -f ${DD}/kerberos-${dep_kerberos_version}${EXTRACT_SUFX} ]; then \
		${MKDIR} ${DD} && \
		${ECHO} "====> Fetching ${NODE_HEADERS}${EXTRACT_SUFX}" && \
		${FETCH_CMD} -q https://nodejs.org/download/release/v24.11.0/${NODE_HEADERS}${EXTRACT_SUFX} -o ${DD}/${NODE_HEADERS}${EXTRACT_SUFX} && \
		${ECHO} "====> Fetching dependency policy-watcher" && \
		${SETENV} TMPDIR=${WRKDIR} ${FETCH_SCRIPT} \
			${dep_policy_watcher_npm_name} ${dep_policy_watcher_version} \
			${FILESDIR}/package-lock-policy-watcher.json \
			${DD}/policy-watcher-${dep_policy_watcher_version}${EXTRACT_SUFX} && \
		${ECHO} "====> Fetching dependency sqlite3" && \
		${SETENV} TMPDIR=${WRKDIR} ${FETCH_SCRIPT} \
			${dep_sqlite3_npm_name} ${dep_sqlite3_version} \
			${FILESDIR}/package-lock-sqlite3.json \
			${DD}/sqlite3-${dep_sqlite3_version}${EXTRACT_SUFX} && \
		${ECHO} "====> Fetching dependency kerberos" && \
		${SETENV} TMPDIR=${WRKDIR} ${FETCH_SCRIPT} \
			${dep_kerberos_npm_name} ${dep_kerberos_version} \
			${FILESDIR}/package-lock-kerberos.json \
			${DD}/kerberos-${dep_kerberos_version}${EXTRACT_SUFX} && \
		${ECHO} "====> Fetching ${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}" && \
		${SETENV} TMPDIR=${WRKDIR} ${FETCH_SCRIPT} \
			${PACKAGE_NAME} ${DISTVERSION} \
			${FILESDIR}/package-lock.json \
			${DD}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}; \
	fi

do-build:
	# Create directory for FreeBSD native modules
	@${MKDIR} ${WRKSRC}/node_modules/${PACKAGE_NAME}/dist/compiled/freebsd/${JS_ARCH}
	@${ECHO_MSG} "====> Building vscode-policy-watcher..."
	@cd ${WRKDIR}/policy-watcher-${dep_policy_watcher_version}/node_modules/${dep_policy_watcher_npm_name} && \
		${SETENV} HOME=${WRKDIR} PYTHON=${PYTHON_CMD} CXXFLAGS="-I${LOCALBASE}/include" \
			npm rebuild --nodedir=${WRKDIR}/${NODE_HEADERS:S/-headers//} && \
		${CP} build/Release/vscode-policy-watcher.node ${WRKSRC}/node_modules/${PACKAGE_NAME}/dist/compiled/freebsd/${JS_ARCH}/
	@${ECHO_MSG} "====> Building @vscode/sqlite3..."
	@cd ${WRKDIR}/sqlite3-${dep_sqlite3_version}/node_modules/${dep_sqlite3_npm_name} && \
		${SETENV} HOME=${WRKDIR} PYTHON=${PYTHON_CMD} CXXFLAGS="-I${LOCALBASE}/include" \
			npm rebuild --nodedir=${WRKDIR}/${NODE_HEADERS:S/-headers//} && \
		${CP} build/Release/vscode-sqlite3.node ${WRKSRC}/node_modules/${PACKAGE_NAME}/dist/compiled/freebsd/${JS_ARCH}/node_sqlite3.node
	@${ECHO_MSG} "====> Building kerberos..."
	@cd ${WRKDIR}/kerberos-${dep_kerberos_version}/node_modules/${dep_kerberos_npm_name} && \
		${SETENV} HOME=${WRKDIR} PYTHON=${PYTHON_CMD} CFLAGS="-I${LOCALBASE}/include" CXXFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib" \
			npm rebuild --nodedir=${WRKDIR}/${NODE_HEADERS:S/-headers//} && \
		${CP} build/Release/kerberos.node ${WRKSRC}/node_modules/${PACKAGE_NAME}/dist/compiled/freebsd/${JS_ARCH}/

do-install:
	# install files
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib
	# remove *.node files for other OSes
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/dist/compiled -name "*\\.node" | \
		${GREP} -v freebsd | \
		${XARGS} ${RM}
	# remove files for other OSes
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/dist -name "*linux*" | ${XARGS} ${RM} -r
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/dist -name "*win32*" | ${XARGS} ${RM} -r
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/dist -name "*darwin*" | ${XARGS} ${RM} -r
	# remove crypt32.node (Windows only)
	@${RM} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/dist/crypt32*.node
	# update shebang to use system node
	@${REINPLACE_CMD} -i '' \
		-e "s|#!/usr/bin/env node|#!${PREFIX}/bin/node|" \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/dist/language-server.js
	# set exec bit
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/dist/language-server.js
	# create symlink in bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	@${LN} -s ../lib/node_modules/${PACKAGE_NAME}/dist/language-server.js ${STAGEDIR}${PREFIX}/bin/copilot-language-server
	# strip binaries
	@${FIND} ${STAGEDIR}${PREFIX}/lib/node_modules/${PACKAGE_NAME}/dist/compiled -name "*.node" | ${XARGS} ${STRIP_CMD}

.include <bsd.port.mk>
