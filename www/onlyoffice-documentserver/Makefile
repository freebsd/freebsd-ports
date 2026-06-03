PORTNAME=	onlyoffice-documentserver
DISTVERSIONPREFIX=	v
DISTVERSION=	9.3.1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES+=	LOCAL/mikael/v8/:source1 \
		https://nodejs.org/dist/v${_PKGFETCH_NODE_VERSION}/:source2 \
		https://github.com/fsbruva/onlyoffice-DS-npm-cache/releases/download/${_NPM_CACHE_TAG}/:source3
DISTFILES+=	v8-8.9.255.25_all.tar.gz:source1 \
		node-v${_PKGFETCH_NODE_VERSION}.tar.gz:source2 \
		onlyoffice-DS-npm-cache-${_NPM_CACHE_TAG}.tar.gz:source3

MAINTAINER=	fsbruva@yahoo.com
COMMENT=	Secure office and productivity apps
WWW=		https://www.onlyoffice.com/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	Upstream only supports amd64 and arm64

# node version used with "npm install" inside ${WRKSRC}/yao-pkg
# kept in sync with patch-build__tools_scripts_build__server.py and patch-document-server-package_Makefile
_DS_BUILD=		8
_PKGFETCH_NODE_VERSION=	24.14.1
_NPM_CACHE_TAG= ${_DS_TAGNAME}-202604230220
# end of cache build config

_NODE_DISTFILE=	node-v${_PKGFETCH_NODE_VERSION}.tar.gz
WRKSRC_npm_cache= ${WRKDIR}/onlyoffice-DS-npm-cache-${_NPM_CACHE_TAG}

# Map FreeBSD ARCH to the node/sharp platform-arch suffix
.if ${MACHINE_ARCH} == aarch64
_SHARP_NODE_ARCH=   arm64v8
.else
_SHARP_NODE_ARCH=   x64
.endif

_SHARP_NODE_FILE=   sharp-freebsd-${_SHARP_NODE_ARCH}.node
_SHARP_INSTALL_DIR= ${WWWDIR}/documentserver/server/DocService/sharp

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		boost-libs>0:devel/boost-libs \
		glib>=2.54:devel/glib20 \
		gn:devel/gn \
		ninja:devel/ninja \
		npm:www/npm-node24 \
		optipng:graphics/optipng

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libbrotlicommon.so:archivers/brotli \
		libbrotlidec.so:archivers/brotli \
		libcurl.so:ftp/curl \
		libetonyek-0.1.so:graphics/libetonyek01 \
		libgumbo.so:devel/gumbo \
		libharfbuzz.so:print/harfbuzz \
		libheif.so:graphics/libheif \
		libicudata.so:devel/icu \
		libicuuc.so:devel/icu \
		libmd4c-html.so:textproc/md4c \
		libmd4c.so:textproc/md4c \
		libodfgen-0.1.so:textproc/libodfgen01 \
		librevenge-0.0.so:textproc/librevenge \
		libvips.so:graphics/vips

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}supervisor>0:sysutils/py-supervisor@${PY_FLAVOR} \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		gsed:textproc/gsed \
		nginx:www/nginx \
		pwgen:sysutils/pwgen \
		rabbitmq>0:net/rabbitmq \
		webfonts>=0:x11-fonts/webfonts

USES=		autoreconf:build dos2unix fakeroot gmake gnome iconv:wchar_t localbase java:build pkgconfig \
		python:build qt:5 ssl trigger

BROKEN_SSL=	boringssl libressl libressl-devel
BROKEN_SSL_REASON=	Node.js requires OpenSSL

DOS2UNIX_FILES=	document-server-package/common/documentserver/nginx/includes/http-common.conf.m4

USE_GITHUB=	yes
GH_ACCOUNT=	ONLYOFFICE
GH_PROJECT=	DocumentServer
_DS_TAGNAME=	${DISTVERSIONPREFIX}${DISTVERSION}.${_DS_BUILD}
GH_TUPLE=	ONLYOFFICE:build_tools:${_DS_TAGNAME}:buildtools/build_tools \
		ONLYOFFICE:core:${_DS_TAGNAME}:core/core \
		ONLYOFFICE:core-fonts:${_DS_TAGNAME}:corefonts/core-fonts \
		ONLYOFFICE:dictionaries:${_DS_TAGNAME}:dictionaries/dictionaries \
		ONLYOFFICE:document-formats:${_DS_TAGNAME}:df/document-formats \
		ONLYOFFICE:document-server-integration:${_DS_TAGNAME}:dsi/document-server-integration \
		ONLYOFFICE:document-server-package:${_DS_TAGNAME}:dsp/document-server-package \
		ONLYOFFICE:document-templates:${_DS_TAGNAME}:dt/document-templates \
		ONLYOFFICE:sdkjs:${_DS_TAGNAME}:sdkjs/sdkjs \
		ONLYOFFICE:server:${_DS_TAGNAME}:server/server \
		ONLYOFFICE:web-apps:${_DS_TAGNAME}:webapps/web-apps \
		ONLYOFFICE:DocumentBuilder:626d1e44db3d06ceb8298215a67ef0475912d89a:document_builder/DocumentBuilder \
		ONLYOFFICE:onlyoffice.github.io:b26d001664d771df4f663d2d3ba7dd4a188b6cab:sdkjs_plugins_v1/onlyoffice.github.io \
		jasenhuang:katana-parser:be6df45:jasenhuang_katana/core/Common/3dParty/html/katana-parser \
		hunspell:hyphen:73dd296:hunspell_hyphen/core/Common/3dParty/hyphen/hyphen

JAVA_VERSION=	11+

USE_LDCONFIG=	yes
USE_QT=		qmake:build

MAKE_ENV=	BUILD_NUMBER=${_DS_BUILD} \
		npm_package_config_node_gyp_nodedir=${LOCALBASE} \
		npm_package_config_node_gyp_python=${PYTHON_CMD} \
		NODE_OPTIONS=--max-old-space-size=3072 \
		PKG_BUILD_PATH=${WRKDIR}/.pkg-build \
		PKG_CACHE_PATH=${WRKDIR}/.pkg-cache \
		PRODUCT_VERSION=${DISTVERSION} \
		PYTHON=${PYTHON_CMD}

# Don't create __pycache__ directory when executing node-gyp
# This is a workaround to avoid filesystem violations during poudriere build
MAKE_ENV+=	PYTHONDONTWRITEBYTECODE=1

# do not strip docservice, converter, metrics and json
STRIP=

ETCDIR=		${PREFIX}/etc/onlyoffice
WWWDIR=		${PREFIX}/www/onlyoffice

BINARY_ALIAS=	python=${PYTHON_CMD} \
		strip=true

SUB_FILES=	pkg-message \
		onlyoffice.newsyslog.sample
SUB_LIST=	DS_GROUPNAME=${DS_GROUPNAME} \
		DS_USERNAME=${DS_USERNAME} \
		ETCDIR=${ETCDIR} \
		PREFIX=${PREFIX} \
		WWWDIR=${WWWDIR}

DS_USERNAME=	onlyoffice
DS_GROUPNAME=	onlyoffice

USERS=		${DS_USERNAME}
GROUPS=		${DS_GROUPNAME}

PLIST_SUB=	DS_GROUPNAME=${DS_GROUPNAME} \
		DS_USERNAME=${DS_USERNAME} \
		SHARP_NODE_FILE=${_SHARP_NODE_FILE}

OPTIONS_DEFAULT=	PGSQL
OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL

MYSQL_USES+=	mysql:client
PGSQL_USES+=	pgsql
PGSQL_VARS=	WANT_PGSQL=client

.include <bsd.port.pre.mk>
.if ${ARCH} == aarch64
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
BINARY_ALIAS+=	ar=${LOCALBASE}/bin/llvm-ar${LLVM_DEFAULT} \
		c++=${LOCALBASE}/bin/clang++${LLVM_DEFAULT} \
		cc=${LOCALBASE}/bin/clang${LLVM_DEFAULT} \
		cpp=${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT} \
		ld=${LOCALBASE}/bin/ld.lld${LLVM_DEFAULT} \
		nm=${LOCALBASE}/bin/llvm-nm${LLVM_DEFAULT}
.endif

post-extract:
	@${MV} ${WRKDIR}/v8 ${WRKSRC}/core/Common/3dParty/v8_89

	@${LN} -s ${WRKSRC_npm_cache} ${WRKDIR}/.npm
	@${MKDIR} ${WRKDIR}/.pkg-build
	@${MKDIR} -p ${WRKDIR}/.pkg-cache/node

	# Copy node tarball to pkg-cache directory, and create sha256sum file
	@${CP} ${DISTDIR}/${_NODE_DISTFILE} ${WRKDIR}/.pkg-cache/node
	@${EGREP} '^\s*SHA256[[:space:]]\(${_NODE_DISTFILE}\)' \
			${.CURDIR}/distinfo | \
			${AWK} '{print $$4 "  ${_NODE_DISTFILE}"}' \
			> ${WRKDIR}/.pkg-cache/node/${_NODE_DISTFILE}.sha256sum
	@${ECHO_MSG} "===>  Created pkg-fetch cache entry for ${_NODE_DISTFILE}"

	@${MKDIR} ${WRKSRC}/sdkjs-plugins/v1
	@${CP} ${WRKSRC}/onlyoffice.github.io/sdkjs-plugins/v1/* ${WRKSRC}/sdkjs-plugins/v1

	@${MV} ${WRKSRC}/server/Common/config/production-linux.json ${WRKSRC}/server/Common/config/production-freebsd.json
	@${MV} ${WRKSRC}/server/Common/config/development-linux.json ${WRKSRC}/server/Common/config/development-freebsd.json

	# linux has moved to systemd init files, continue to using supervisord for now
	${MKDIR} ${WRKSRC}/document-server-package/common/documentserver/supervisor
.for i in ds-converter.conf ds-docservice.conf ds-metrics.conf ds.conf
	${CP} ${FILESDIR}/${i} \
		${WRKSRC}/document-server-package/common/documentserver/supervisor
.endfor

pre-configure:
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/build_tools/tools/freebsd/automate.py \
		${WRKSRC}/core/Apple/IWork.pro \
		${WRKSRC}/core/Common/3dParty/boost/boost.pri \
		${WRKSRC}/core/Common/3dParty/brotli/brotli.pri \
		${WRKSRC}/core/Common/3dParty/heif/heif.pri \
		${WRKSRC}/core/Common/3dParty/html/gumbo.pri \
		${WRKSRC}/core/Common/3dParty/icu/icu.pri \
		${WRKSRC}/core/Common/3dParty/md/md2html.pri \
		${WRKSRC}/core/Common/3dParty/v8_89/v8/build/toolchain/gcc_toolchain.gni \
		${WRKSRC}/core/Common/3dParty/v8_89/v8/buildtools/third_party/libc++/BUILD.gn \
		${WRKSRC}/core/DesktopEditor/fontengine/ApplicationFonts.cpp \
		${WRKSRC}/core/X2tConverter/build/Qt/X2tConverter.pri \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-generate-allfonts.sh.m4 \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-jwt-status.sh.m4 \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-pluginsmanager.sh.m4 \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-static-gzip.sh.m4 \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-update-securelink.sh.m4 \
		${WRKSRC}/document-server-package/common/documentserver/supervisor/ds-converter.conf \
		${WRKSRC}/document-server-package/common/documentserver/supervisor/ds-docservice.conf \
		${WRKSRC}/document-server-package/common/documentserver/supervisor/ds-metrics.conf \
		${WRKSRC}/web-apps/build/patches/optipng-bin+5.1.0.patch
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|' -e 's|%%CXX%%|${CXX}|' \
		${WRKSRC}/core/Common/3dParty/v8_89/v8/build/toolchain/gcc_toolchain.gni \
		${WRKSRC}/core/Common/base.pri
	@${REINPLACE_CMD} 's|%%WRKDIR%%|${WRKDIR}|' \
		${WRKSRC}/document-server-package/Makefile
	@${REINPLACE_CMD} 's|%%WRKSRC%%|${WRKSRC}|' \
		${WRKSRC}/build_tools/scripts/build_js.py \
		${WRKSRC}/build_tools/scripts/build_server.py \
		${WRKSRC}/document-server-package/Makefile
	@${REINPLACE_CMD} 's|%%PKGFETCH_NODE_MAJOR_VERSION%%|${_PKGFETCH_NODE_VERSION:C/^([0-9]+)\..*/\1/}|' \
		${WRKSRC}/build_tools/scripts/build_server.py \
		${WRKSRC}/document-server-package/Makefile
	@${REINPLACE_CMD} -e 's|/var/lib|/var/db|' -e 's|/var/www|${LOCALBASE}/www|' \
			  -e 's|/usr/share|${LOCALBASE}/share|' -e 's|/etc|${LOCALBASE}/etc|' \
		${WRKSRC}/server/Common/config/production-freebsd.json \
		${WRKSRC}/server/Common/config/development-freebsd.json
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' -e 's|%%ETCDIR%%|${ETCDIR}|' \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-flush-cache.sh.m4 \
		${WRKSRC}/document-server-package/Makefile
	@${REINPLACE_CMD} 's|%%OPENSSL_LIB%%|${OPENSSLLIB}|' \
		${WRKSRC}/core/Common/3dParty/openssl/openssl.pri
	@${RM} ${WRKSRC}/web-apps/build/patches/optipng-bin+5.1.0.patch.orig

	# Copy new package.json for sdkjs root
	@${CP} ${WRKSRC_npm_cache}/sdkjs-package.json ${WRKSRC}/sdkjs/package.json
	@${ECHO_MSG} "  Installed: sdkjs/package.json"

	# Copy optimized shrinkwrap files from cache repo, overwriting upstream
	@${ECHO_MSG} "Installing optimized npm-shrinkwrap.json files..."
	@(cd ${WRKSRC_npm_cache}/shrinkwrap && \
		${FIND} . -name npm-shrinkwrap.json | while read shrinkwrap; do \
			rel_path=$${shrinkwrap#./}; \
			target="${WRKSRC}/$${rel_path}"; \
			target_dir=$$(dirname "$$target"); \
			${MKDIR} -p "$$target_dir"; \
			${CP} "$$shrinkwrap" "$$target"; \
			${ECHO_MSG} "  Installed: $${rel_path}"; \
		done)

	@${ECHO} "# Generated from 'DEPS'" > ${WRKSRC}/core/Common/3dParty/v8_89/v8/build/config/gclient_args.gni
	@${ECHO} "checkout_google_benchmark = false" >> ${WRKSRC}/core/Common/3dParty/v8_89/v8/build/config/gclient_args.gni

do-build:
	${INSTALL_SCRIPT} ${FILESDIR}/npm ${BINARY_LINKDIR}/npm
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKDIR}/.bin/npm

	@cd ${WRKSRC}/web-apps/build ; ${SETENV} ${MAKE_ENV} NODE_ENV=production npm install --ignore-scripts
	@cd ${WRKSRC}/web-apps/build ; node_modules/.bin/patch-package
	@cd ${WRKSRC}/web-apps/build/node_modules/optipng-bin ; ${SETENV} ${MAKE_ENV} npm run postinstall optipng-bin

	@cd ${WRKSRC}/sdkjs ; ${SETENV} ${MAKE_ENV} npm install

	# During offline builds the install script doesn't run, and must patch for external native addon
	@cd ${WRKSRC}/server/DocService ; ${SETENV} ${MAKE_ENV} NODE_ENV=production npm install --ignore-scripts
	@cd ${WRKSRC}/server/DocService ; node_modules/.bin/patch-package
	@cd ${WRKSRC}/server/DocService/node_modules/sharp ; ${SETENV} ${MAKE_ENV} NODE_ENV=production npm run install

	# Install Metrics dependencies and patch statsd for Node 24 compatibility
	# (util.log was removed in Node 23; patch replaces it with console.log)
	@cd ${WRKSRC}/server/Metrics ; ${SETENV} ${MAKE_ENV} NODE_ENV=production npm install --ignore-scripts
	@cd ${WRKSRC}/server/Metrics ; node_modules/.bin/patch-package

	@${MKDIR} ${WRKSRC}/yao-pkg
	@${CP} ${WRKSRC_npm_cache}/yao-pkg-package.json      ${WRKSRC}/yao-pkg/package.json
	@${CP} ${WRKSRC_npm_cache}/yao-pkg-npm-shrinkwrap-${MACHINE_ARCH}.json ${WRKSRC}/yao-pkg/npm-shrinkwrap.json
	@cd ${WRKSRC}/yao-pkg ; ${SETENV} ${MAKE_ENV} npm install

	@cd ${WRKSRC} && ${PATCH} -N -s -i ${FILESDIR}/extra-patch-pkg-fetch_lib-es5_build.js || ${TRUE}
	@cd ${WRKSRC} && ${PATCH} -N -s -i ${WRKSRC_npm_cache}/extra-patch-pkg-fetch_patches_node.v${_PKGFETCH_NODE_VERSION}.cpp.patch || ${TRUE}

	cd ${WRKSRC}/build_tools/tools/freebsd ; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} automate.py
	cd ${WRKSRC}/document-server-package ; ${SETENV} ${MAKE_ENV} ${GMAKE} freebsd

do-install:
# install the project
# do not strip docservice, converter, metrics and json
	cd ${WRKSRC}/document-server-package/common/documentserver/home && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/documentserver
	${INSTALL_SCRIPT} ${WRKSRC}/document-server-package/common/documentserver/bin/*.sh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/document-server-package/common/documentserver/home/server/tools/all* ${STAGEDIR}${WWWDIR}/documentserver/server/tools
	${INSTALL_PROGRAM} ${WRKSRC}/document-server-package/common/documentserver/home/server/FileConverter/bin/x2t ${STAGEDIR}${WWWDIR}/documentserver/server/FileConverter/bin
	${INSTALL_PROGRAM} ${WRKSRC}/document-server-package/common/documentserver/home/server/FileConverter/bin/docbuilder ${STAGEDIR}${WWWDIR}/documentserver/server/FileConverter/bin
	${INSTALL_PROGRAM} ${WRKSRC}/document-server-package/common/documentserver/home/server/tools/pluginsmanager ${STAGEDIR}${WWWDIR}/documentserver/server/tools
	${INSTALL_DATA} ${WRKSRC}/document-server-package/common/documentserver/home/npm/json ${STAGEDIR}${WWWDIR}/documentserver/npm
	${INSTALL_LIB} ${WRKSRC}/document-server-package/common/documentserver/home/server/FileConverter/bin/*.so ${STAGEDIR}${PREFIX}/lib

# install conf
	${MKDIR} ${STAGEDIR}${ETCDIR}/documentserver/supervisor \
		 ${STAGEDIR}${ETCDIR}/documentserver/nginx/includes \
		 ${STAGEDIR}${ETCDIR}/documentserver/logrotate
	${RM} ${WRKSRC}/document-server-package/common/documentserver/config/*-mac.json ${WRKSRC}/document-server-package/common/documentserver/config/*-windows.json
	cd ${WRKSRC}/document-server-package/common/documentserver/supervisor && ${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR}/documentserver/supervisor "-name *\.conf"
	cd ${WRKSRC}/document-server-package/common/documentserver/logrotate && ${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR}/documentserver/logrotate "-name *\.conf"
	${INSTALL_DATA} ${WRKSRC}/document-server-package/common/documentserver/nginx/ds-ssl.conf.tmpl ${WRKSRC}/document-server-package/common/documentserver/nginx/ds-ssl.conf
.for f in ds.conf ds-ssl.conf includes/http-common.conf includes/ds-common.conf \
	includes/ds-docservice.conf includes/ds-letsencrypt.conf \
	includes/ds-mime.types.conf
	${INSTALL_DATA} ${WRKSRC}/document-server-package/common/documentserver/nginx/${f} ${STAGEDIR}${ETCDIR}/documentserver/nginx/${f}.sample
.endfor
	@echo "# Production ds-cache.conf is created automatically by documentserver-flush-cache.sh" > ${STAGEDIR}${ETCDIR}/documentserver/nginx/includes/ds-cache.conf.sample
	cd ${WRKSRC}/document-server-package/common/documentserver/nginx/includes && ${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR}/documentserver/nginx/includes "-name *\.conf"
	cd ${WRKSRC}/document-server-package/common/documentserver/config && ${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR}/documentserver
	${INSTALL_DATA} ${FILESDIR}/local.json.sample ${STAGEDIR}${ETCDIR}/documentserver
	${MKDIR} ${STAGEDIR}/${ETCDIR}/documentserver/newsyslog.conf.d
	${INSTALL_DATA} ${WRKDIR}/onlyoffice.newsyslog.sample ${STAGEDIR}/${ETCDIR}/documentserver/newsyslog.conf.d

# Install arch-specific sharp native binding adjacent to the docservice
# binary.  sharp.js resolves this at runtime via path.dirname(process.execPath).
	@${MKDIR} ${STAGEDIR}${_SHARP_INSTALL_DIR}
	${INSTALL_LIB} \
		${WRKSRC}/server/DocService/node_modules/sharp/build/Release/${_SHARP_NODE_FILE} \
		${STAGEDIR}${_SHARP_INSTALL_DIR}/${_SHARP_NODE_FILE}

# create missing dir
	${MKDIR} ${STAGEDIR}/var/log/onlyoffice/documentserver/docservice \
		 ${STAGEDIR}/var/log/onlyoffice/documentserver/converter \
		 ${STAGEDIR}/var/log/onlyoffice/documentserver/metrics \
		 ${STAGEDIR}/var/db/onlyoffice/documentserver/App_Data/cache/files \
		 ${STAGEDIR}/var/db/onlyoffice/documentserver/App_Data/docbuilder \
		 ${STAGEDIR}${WWWDIR}/Data \
		 ${STAGEDIR}${WWWDIR}/documentserver/fonts

post-install:
# Remove unwanted files from STAGE
	${RM} ${STAGEDIR}${PREFIX}/bin/documentserver-letsencrypt.sh
	${RM} ${STAGEDIR}${WWWDIR}/documentserver/server/Common/config/*.bak
	${RM} ${STAGEDIR}${WWWDIR}/documentserver/dictionaries/sl_SI/hyph_sl_SI.dic.bak

# formats@2.5x.svg is generated by grunt-svg-sprite (web-apps/build/sprites/Gruntfile.js) as
# part of the editor-specific deploy phase, which runs after the common deploy step that would
# have copied it to staging via its **/*.svg glob. Copy it manually until fixed upstream.
	${INSTALL_DATA} ${WRKSRC}/web-apps/apps/common/main/resources/img/doc-formats/formats@2.5x.svg \
		${STAGEDIR}${WWWDIR}/documentserver/web-apps/apps/common/main/resources/img/doc-formats/

.include <bsd.port.post.mk>
