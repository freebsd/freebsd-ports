PORTNAME=	onlyoffice-documentserver
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.4
CATEGORIES=	www
MASTER_SITES+=	LOCAL/mikael/v8/:source1 \
		https://nodejs.org/dist/v${PKGFETCH_NODE_VERSION}/:source3 \
		SF/optipng/OptiPNG/optipng-0.7.8/:source4
DISTFILES+=	v8-8.9.255.25_all.tar.gz:source1 \
		node-v${PKGFETCH_NODE_VERSION}.tar.gz:source3 \
		optipng-0.7.8.tar.gz:source4

MAINTAINER=	fsbruva@yahoo.com
COMMENT=	Secure office and productivity apps
WWW=		https://www.onlyoffice.com/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_SSL=	boringssl libressl libressl-devel
BROKEN_SSL_REASON=	Node.js requires OpenSSL
ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	Upstream only supports amd64 and arm64

# node version used with "npm install @yao-pkg/pkg@6.6.0"
# keep in sync with patch-build__tools_scripts_build__server.py and patch-document-server-package_Makefile
PKGFETCH_NODE_VERSION=	20.19.4
DS_BUILD=	50

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		boost-libs>0:devel/boost-libs \
		glib>=2.54:devel/glib20 \
		gn:devel/gn \
		java:java/openjdk11 \
		ninja:devel/ninja \
		npm:www/npm-node20

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libetonyek-0.1.so:graphics/libetonyek01 \
		libcurl.so:ftp/curl \
		libharfbuzz.so:print/harfbuzz \
		libiconv.so:converters/libiconv \
		libicuuc.so:devel/icu \
		libodfgen-0.1.so:textproc/libodfgen01 \
		librevenge-0.0.so:textproc/librevenge

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}supervisor>0:sysutils/py-supervisor@${PY_FLAVOR} \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		gsed:textproc/gsed \
		nginx:www/nginx \
		pwgen:sysutils/pwgen \
		rabbitmq>0:net/rabbitmq \
		webfonts>=0:x11-fonts/webfonts

USES=		autoreconf:build dos2unix fakeroot gmake gnome iconv localbase pkgconfig \
		python:3.9+,build qt:5 ssl trigger

DOS2UNIX_FILES=	document-server-package/common/documentserver/nginx/includes/http-common.conf.m4

USE_GITHUB=	yes
GH_ACCOUNT=	ONLYOFFICE
GH_PROJECT=	DocumentServer
DS_TAGNAME=	${DISTVERSIONPREFIX}${DISTVERSION}.${DS_BUILD}
GH_TUPLE=	ONLYOFFICE:core:${DS_TAGNAME}:core/core \
		ONLYOFFICE:core-fonts:${DS_TAGNAME}:corefonts/core-fonts \
		ONLYOFFICE:dictionaries:${DS_TAGNAME}:dictionaries/dictionaries \
		ONLYOFFICE:document-server-integration:${DS_TAGNAME}:dsi/document-server-integration \
		ONLYOFFICE:document-templates:${DS_TAGNAME}:dt/document-templates \
		ONLYOFFICE:sdkjs:${DS_TAGNAME}:sdkjs/sdkjs \
		ONLYOFFICE:server:${DS_TAGNAME}:server/server \
		ONLYOFFICE:web-apps:${DS_TAGNAME}:webapps/web-apps \
		ONLYOFFICE:build_tools:${DS_TAGNAME}:buildtools/build_tools \
		ONLYOFFICE:DocumentBuilder:626d1e44db3d06ceb8298215a67ef0475912d89a:document_builder/DocumentBuilder \
		ONLYOFFICE:onlyoffice.github.io:b26d001664d771df4f663d2d3ba7dd4a188b6cab:sdkjs_plugins_v1/onlyoffice.github.io \
		ONLYOFFICE:document-server-package:${DS_TAGNAME}:dsp/document-server-package \
		jasenhuang:katana-parser:be6df45:jasenhuang_katana/core/Common/3dParty/html/katana-parser \
		google:gumbo-parser:aa91b27:google_gumbo/core/Common/3dParty/html/gumbo-parser \
		google:brotli:a47d747:google_brotli/core/Common/3dParty/brotli/brotli \
		hunspell:hyphen:73dd296:hunspell_hyphen/core/Common/3dParty/hyphen/hyphen \
		mity:md4c:481fbfb:mity_md4c/core/Common/3dParty/md/md4c \
		fsbruva:onlyoffice-DS-pkg-cache:v${PKGFETCH_NODE_VERSION}:pkg_cache/ \
		fsbruva:onlyoffice-DS-npm-cache:${DS_TAGNAME}-20250831:npm_cache/

USE_LDCONFIG=	yes
USE_QT=		qmake:build

MAKE_ENV=	BUILD_NUMBER=${DS_BUILD} \
		npm_package_config_node_gyp_nodedir=${LOCALBASE} \
		npm_package_config_node_gyp_python=${PYTHON_CMD} \
		PKG_CACHE_PATH=${WRKDIR}/.pkg-cache \
		PRODUCT_VERSION=${DISTVERSION} \
		PYTHON=${PYTHON_CMD}

# Don't create __pycache__ directory when executing node-gyp
# This is a workaround to avoid filesystem violations during poudriere build
MAKE_ENV+=	PYTHONDONTWRITEBYTECODE=1

CONFLICTS_BUILD=	devel/googletest

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
		DS_USERNAME=${DS_USERNAME}

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
	@${LN} -s ${WRKSRC_pkg_cache} ${WRKDIR}/.pkg-cache
	@${CP} ${DISTDIR}/node-v${PKGFETCH_NODE_VERSION}.tar.gz ${WRKDIR}/.pkg-cache/node

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
		${WRKSRC}/core/Common/3dParty/icu/icu.pri \
		${WRKSRC}/core/Common/3dParty/v8_89/v8/build/toolchain/gcc_toolchain.gni \
		${WRKSRC}/core/Common/3dParty/v8_89/v8/buildtools/third_party/libc++/BUILD.gn \
		${WRKSRC}/core/DesktopEditor/fontengine/ApplicationFonts.cpp \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-generate-allfonts.sh.m4 \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-jwt-status.sh.m4 \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-pluginsmanager.sh.m4 \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-static-gzip.sh.m4 \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-update-securelink.sh.m4 \
		${WRKSRC}/document-server-package/common/documentserver/supervisor/ds-converter.conf \
		${WRKSRC}/document-server-package/common/documentserver/supervisor/ds-docservice.conf \
		${WRKSRC}/document-server-package/common/documentserver/supervisor/ds-metrics.conf \
		${WRKSRC}/server/Metrics/patches/modern-syslog+1.2.0.patch
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|' -e 's|%%CXX%%|${CXX}|' \
		${WRKSRC}/core/Common/3dParty/v8_89/v8/build/toolchain/gcc_toolchain.gni \
		${WRKSRC}/core/Common/base.pri
	@${REINPLACE_CMD} 's|%%WRKDIR%%|${WRKDIR}|' \
		${WRKSRC}/document-server-package/Makefile
	@${REINPLACE_CMD} 's|%%WRKSRC%%|${WRKSRC}|' \
		${WRKSRC}/build_tools/scripts/build_js.py \
		${WRKSRC}/build_tools/scripts/build_server.py \
		${WRKSRC}/document-server-package/Makefile
	@${REINPLACE_CMD} 's|%%PKGFETCH_NODE_MAJOR_VERSION%%|${PKGFETCH_NODE_VERSION:C/^([0-9]+)\..*/\1/}|' \
		${WRKSRC}/build_tools/scripts/build_server.py \
		${WRKSRC}/document-server-package/Makefile
	@${REINPLACE_CMD} -e 's|/var/lib|/var/db|' -e 's|/var/www|${LOCALBASE}/www|' \
			  -e 's|/usr/share|${LOCALBASE}/share|' -e 's|/etc|${LOCALBASE}/etc|' \
		${WRKSRC}/server/Common/config/production-freebsd.json \
		${WRKSRC}/server/Common/config/development-freebsd.json
	@${REINPLACE_CMD} 's|%%DISTDIR%%|${DISTDIR}|' \
		${WRKSRC}/web-apps/build/patches/optipng-bin+5.1.0.patch
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' -e 's|%%ETCDIR%%|${ETCDIR}|' \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-flush-cache.sh.m4 \
		${WRKSRC}/document-server-package/Makefile
	@${REINPLACE_CMD} 's|%%OPENSSL_LIB%%|${OPENSSLLIB}|' \
		${WRKSRC}/core/Common/3dParty/openssl/openssl.pri
	@${RM} ${WRKSRC}/web-apps/build/patches/optipng-bin+5.1.0.patch.orig
	@${RM} ${WRKSRC}/server/Metrics/patches/modern-syslog+1.2.0.patch.orig

	@${FIND} ${WRKSRC}/server -type f -name npm-shrinkwrap.json -delete

	@${ECHO} "# Generated from 'DEPS'" > ${WRKSRC}/core/Common/3dParty/v8_89/v8/build/config/gclient_args.gni
	@${ECHO} "checkout_google_benchmark = false" >> ${WRKSRC}/core/Common/3dParty/v8_89/v8/build/config/gclient_args.gni

do-build:
	${INSTALL_SCRIPT} ${FILESDIR}/npm ${BINARY_LINKDIR}/npm
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKDIR}/.bin/npm

#	@cd ${WRKSRC}/web-apps/build ; ${SETENV} ${MAKE_ENV} npm cache clean --force
	@cd ${WRKSRC}/web-apps/build ; ${SETENV} ${MAKE_ENV} npm install patch-package
	@cd ${WRKSRC}/web-apps/build ; ${SETENV} ${MAKE_ENV} npm install optipng-bin@5.1.0
	@cd ${WRKSRC}/web-apps/build ; node_modules/.bin/patch-package
	@cd ${WRKSRC}/web-apps/build/node_modules/optipng-bin ; ${SETENV} ${MAKE_ENV} npm run postinstall optipng-bin

	@cd ${WRKSRC}/server ; ${SETENV} ${MAKE_ENV} npm install grunt-cli
	@cd ${WRKSRC}/server ; ${SETENV} ${MAKE_ENV} npm install grunt
	@cd ${WRKSRC}/server/Metrics ; ${SETENV} ${MAKE_ENV} npm install modern-syslog@1.2.0 --ignore-scripts
	@cd ${WRKSRC}/server/Metrics ; ${SETENV} ${MAKE_ENV} npm install patch-package
	@cd ${WRKSRC}/server/Metrics ; node_modules/.bin/patch-package
	@cd ${WRKSRC}/server/Metrics/node_modules/modern-syslog ; ${SETENV} ${MAKE_ENV} ${GMAKE}
	@cd ${WRKSRC}/sdkjs  ; ${SETENV} ${MAKE_ENV} npm install grunt-cli
	@cd ${WRKSRC}/sdkjs  ; ${SETENV} ${MAKE_ENV} npm install grunt

	@${MKDIR} ${WRKSRC}/yao-pkg
	@${CP} ${FILESDIR}/package* ${WRKSRC}/yao-pkg
	@cd ${WRKSRC}/yao-pkg ; ${SETENV} ${MAKE_ENV} npm install @yao-pkg/pkg@6.6.0

	@cd ${WRKSRC} && ${PATCH} -N -s -i ${FILESDIR}/extra-patch-pkg-fetch_lib-es5_build.js || ${TRUE}
	@cd ${WRKSRC} && ${PATCH} -N -s -i ${FILESDIR}/extra-patch-pkg-fetch_patches_node.v${PKGFETCH_NODE_VERSION}.cpp.patch || ${TRUE}

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
	${RM} ${STAGEDIR}${PREFIX}/bin/documentserver-letsencrypt.sh

# install conf
	${MKDIR} ${STAGEDIR}${ETCDIR}/documentserver/supervisor \
		 ${STAGEDIR}${ETCDIR}/documentserver/nginx/includes \
		 ${STAGEDIR}${ETCDIR}/documentserver/logrotate
	${RM} ${WRKSRC}/document-server-package/common/documentserver/config/*-mac.json ${WRKSRC}/document-server-package/common/documentserver/config/*-windows.json
	cd ${WRKSRC}/document-server-package/common/documentserver/supervisor && ${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR}/documentserver/supervisor "-name *\.conf"
	cd ${WRKSRC}/document-server-package/common/documentserver/logrotate && ${COPYTREE_SHARE} . ${STAGEDIR}${ETCDIR}/documentserver/logrotate "-name *\.conf"
	@${CP} ${WRKSRC}/document-server-package/common/documentserver/nginx/ds-ssl.conf.tmpl ${WRKSRC}/document-server-package/common/documentserver/nginx/ds-ssl.conf
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

# create missing dir
	${MKDIR} ${STAGEDIR}/var/log/onlyoffice/documentserver/docservice \
		 ${STAGEDIR}/var/log/onlyoffice/documentserver/converter \
		 ${STAGEDIR}/var/log/onlyoffice/documentserver/metrics \
		 ${STAGEDIR}/var/db/onlyoffice/documentserver/App_Data/cache/files \
		 ${STAGEDIR}/var/db/onlyoffice/documentserver/App_Data/docbuilder \
		 ${STAGEDIR}${WWWDIR}/Data \
		 ${STAGEDIR}${WWWDIR}/documentserver/fonts

# Remove bak file
	${RM} ${STAGEDIR}${WWWDIR}/documentserver/server/Common/config/*.bak
	${RM} ${STAGEDIR}${WWWDIR}/documentserver/dictionaries/sl_SI/hyph_sl_SI.dic.bak

create-caches-tarball:
	# do some cleanup first
	${RM} -r  ${WRKDIR}/.npm/_logs ${WRKDIR}/.npm/_update-notifier-last-checked ${WRKDIR}/.cache/yarn/v6/.tmp ${WRKDIR}/.cache/node-gyp
#	${FIND} ${WRKDIR}/.cache -type f -perm 755 -exec ${FILE} {} \; | ${EGREP} "ELF|PE32+|Mach-O" | ${AWK} -F ':' '{print $$1}' | ${XARGS} ${RM}
	${FIND} ${WRKDIR}/.pkg-cache -type f -perm 755 -exec ${FILE} {} \; | ${EGREP} "ELF|PE32+|Mach-O" | ${AWK} -F ':' '{print $$1}' | ${XARGS} ${RM}
	${FIND} ${WRKDIR}/.pkg-cache -type f -perm 644 -exec ${FILE} {} \; | ${EGREP} -v "${PKGFETCH_NODE_VERSION}" | ${EGREP} "built-v|node-v" | ${EGREP} "tar.gz|sha256sum" | ${AWK} -F ':' '{print $$1}' | ${XARGS} ${RM}

#	cd ${WRKDIR} && \
#		${TAR} czf ${PORTNAME}-${DISTVERSION}_`date +%Y%m%d`-npm-cache.tar.gz .npm .pkg-cache

.include <bsd.port.post.mk>
