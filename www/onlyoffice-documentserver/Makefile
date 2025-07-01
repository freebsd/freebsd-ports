PORTNAME=	onlyoffice-documentserver
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.2.16
CATEGORIES=	www
MASTER_SITES+=	LOCAL/mikael/v8/:source1 \
		https://nodejs.org/dist/v${NODE_VERSION_PKGFETCH}/:source3 \
		SF/optipng/OptiPNG/optipng-0.7.8/:source4
DISTFILES+=	v8-8.9.255.25_all.tar.gz:source1 \
		node-v${NODE_VERSION_PKGFETCH}.tar.gz:source3 \
		optipng-0.7.8.tar.gz:source4

MAINTAINER=	fsbruva@yahoo.com
COMMENT=	Secure office and productivity apps
WWW=		https://www.onlyoffice.com/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	fails to build

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		boost-libs>0:devel/boost-libs \
		glib>=2.54:devel/glib20 \
		gn:devel/gn \
		java:java/openjdk11 \
		ninja:devel/ninja \
		npm:www/npm-node20 \
		${LOCALBASE}/lib/libcrypto.a:security/openssl
LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libetonyek-0.1.so:graphics/libetonyek01 \
		libcurl.so:ftp/curl \
		libharfbuzz.so:print/harfbuzz \
		libiconv.so:converters/libiconv \
		libicutu.so:devel/icu \
		libodfgen-0.1.so:textproc/libodfgen01 \
		librevenge-0.0.so:textproc/librevenge
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}supervisor>0:sysutils/py-supervisor@${PY_FLAVOR} \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss \
		gsed:textproc/gsed \
		nginx:www/nginx \
		pwgen:sysutils/pwgen \
		rabbitmq>0:net/rabbitmq \
		webfonts>=0:x11-fonts/webfonts

USES=		autoreconf:build dos2unix fakeroot gmake gnome iconv localbase nodejs:22,build pkgconfig \
		python:3.9+,build qt:5 trigger
USE_QT=		qmake:build
USE_GITHUB=	yes
GH_ACCOUNT=	ONLYOFFICE
GH_PROJECT=	DocumentServer
GH_TAGNAME=	v${DISTVERSION:C/^([0-9]+\.[0-9]+\.[0-9]+).*/\1/}
GH_TUPLE=	ONLYOFFICE:core:v${DISTVERSION}:core/core \
		ONLYOFFICE:core-fonts:v${DISTVERSION}:corefonts/core-fonts \
		ONLYOFFICE:dictionaries:v${DISTVERSION}:dictionaries/dictionaries \
		ONLYOFFICE:document-server-integration:v${DISTVERSION}:dsi/document-server-integration \
		ONLYOFFICE:document-templates:v${DISTVERSION}:dt/document-templates \
		ONLYOFFICE:sdkjs:v${DISTVERSION}:sdkjs/sdkjs \
		ONLYOFFICE:server:v${DISTVERSION}:server/server \
		ONLYOFFICE:web-apps:v${DISTVERSION}:webapps/web-apps \
		ONLYOFFICE:build_tools:v${DISTVERSION}:buildtools/build_tools \
		ONLYOFFICE:DocumentBuilder:626d1e44db3d06ceb8298215a67ef0475912d89a:document_builder/DocumentBuilder \
		ONLYOFFICE:onlyoffice.github.io:b26d001664d771df4f663d2d3ba7dd4a188b6cab:sdkjs_plugins_v1/onlyoffice.github.io \
		ONLYOFFICE:document-server-package:v${DISTVERSION}:dsp/document-server-package \
		jasenhuang:katana-parser:be6df45:jasenhuang_katana/core/Common/3dParty/html/katana-parser \
		google:gumbo-parser:aa91b27:google_gumbo/core/Common/3dParty/html/gumbo-parser \
		hunspell:hyphen:73dd296:hunspell_hyphen/core/Common/3dParty/hyphen/hyphen \
		mity:md4c:481fbfb:mity_md4c/core/Common/3dParty/md/md4c \
		fsbruva:onlyoffice-DS-pkg-cache:v${NODE_VERSION_PKGFETCH}:pkg_cache/ \
		fsbruva:onlyoffice-DS-npm-cache:v${DISTVERSION}-20250701:npm_cache/

OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL
OPTIONS_DEFAULT=	PGSQL

MYSQL_USES+=	mysql:client
PGSQL_USES+=	pgsql
PGSQL_VARS=	WANT_PGSQL=client

BINARY_ALIAS=	python=${PYTHON_CMD} \
		strip=true
USE_LDCONFIG=	yes

WWWDIR=		${PREFIX}/www/onlyoffice
ETCDIR=		${PREFIX}/etc/onlyoffice

DS_USERNAME=	onlyoffice
DS_GROUPNAME=	onlyoffice

USERS=		${DS_USERNAME}
GROUPS=		${DS_GROUPNAME}

PLIST_SUB=	DS_GROUPNAME=${DS_GROUPNAME} \
		DS_USERNAME=${DS_USERNAME}
SUB_FILES=	pkg-message \
		onlyoffice.newsyslog.sample
SUB_LIST=	DS_GROUPNAME=${DS_GROUPNAME} \
		DS_USERNAME=${DS_USERNAME} \
		ETCDIR=${ETCDIR} \
		PREFIX=${PREFIX} \
		WWWDIR=${WWWDIR}

# node version used with "npm install @yao-pkg/pkg@6.5.1"
# keep in sync with patch-build__tools_scripts_build__server.py and patch-document-server-package_Makefile
NODE_VERSION_PKGFETCH=	20.19.1

MAKE_ENV=	BUILD_NUMBER="36" \
		PKG_CACHE_PATH=${WRKDIR}/.pkg-cache \
		PRODUCT_VERSION=${DISTVERSION:C/^([0-9]+\.[0-9]+\.[0-9]+).*/\1/} \
		BUILD_NUMBER=${DISTVERSION:C/^[0-9]+\.[0-9]+\.[0-9]+\.([0-9]+)/\1/}

# Don't create __pycache__ directory when executing node-gyp
# This is a workaround to avoid filesystem violations during poudriere build
MAKE_ENV+=	PYTHONDONTWRITEBYTECODE=1

DOS2UNIX_FILES=	document-server-package/common/documentserver/nginx/includes/http-common.conf.m4

CONFLICTS_BUILD=devel/googletest

.include <bsd.port.pre.mk>
.if ${ARCH} == aarch64
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
BINARY_ALIAS+=	cpp=${LOCALBASE}/bin/clang-cpp${LLVM_DEFAULT} \
		cc=${LOCALBASE}/bin/clang${LLVM_DEFAULT} \
		c++=${LOCALBASE}/bin/clang++${LLVM_DEFAULT} \
		ar=${LOCALBASE}/bin/llvm-ar${LLVM_DEFAULT} \
		nm=${LOCALBASE}/bin/llvm-nm${LLVM_DEFAULT} \
		ld=${LOCALBASE}/bin/ld.lld${LLVM_DEFAULT}
.endif

post-extract:
	@${MV} ${WRKDIR}/v8 ${WRKSRC}/core/Common/3dParty/v8_89

	@${LN} -s ${WRKSRC_npm_cache} ${WRKDIR}/.npm
	@${LN} -s ${WRKSRC_pkg_cache} ${WRKDIR}/.pkg-cache
	@${CP} ${DISTDIR}/node-v${NODE_VERSION_PKGFETCH}.tar.gz ${WRKDIR}/.pkg-cache/node

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

post-patch:
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/build_tools/tools/freebsd/automate.py \
		${WRKSRC}/core/Apple/IWork.pro \
		${WRKSRC}/core/Common/3dParty/boost/boost.pri \
		${WRKSRC}/core/Common/3dParty/icu/icu.pri \
		${WRKSRC}/core/Common/3dParty/openssl/openssl.pri \
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
		${WRKSRC}/document-server-package/common/documentserver/supervisor/ds-metrics.conf
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|' -e 's|%%CXX%%|${CXX}|' \
		${WRKSRC}/core/Common/3dParty/v8_89/v8/build/toolchain/gcc_toolchain.gni \
		${WRKSRC}/core/Common/base.pri
	@${REINPLACE_CMD} 's|%%WRKDIR%%|${WRKDIR}|' \
		${WRKSRC}/document-server-package/Makefile
	@${REINPLACE_CMD} 's|%%WRKSRC%%|${WRKSRC}|' \
		${WRKSRC}/build_tools/scripts/build_js.py \
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
	@${RM} ${WRKSRC}/web-apps/build/patches/optipng-bin+5.1.0.patch.orig

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
	@cd ${WRKSRC}/sdkjs  ; ${SETENV} ${MAKE_ENV} npm install grunt-cli
	@cd ${WRKSRC}/sdkjs  ; ${SETENV} ${MAKE_ENV} npm install grunt

	@${MKDIR} ${WRKSRC}/yao-pkg
	@${CP} ${FILESDIR}/package* ${WRKSRC}/yao-pkg
	@cd ${WRKSRC}/yao-pkg ; ${SETENV} ${MAKE_ENV} npm install @yao-pkg/pkg@6.5.1

	@cd ${WRKSRC} && ${PATCH} -N -s -i ${FILESDIR}/extra-patch-pkg-fetch_lib-es5_build.js || ${TRUE}
	@cd ${WRKSRC} && ${PATCH} -N -s -i ${FILESDIR}/extra-patch-pkg-fetch_patches_node.v${NODE_VERSION_PKGFETCH}.cpp.patch || ${TRUE}

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
.for f in ds.conf ds-ssl.conf includes/http-common.conf includes/ds-common.conf includes/ds-docservice.conf includes/ds-letsencrypt.conf includes/ds-mime.types.conf
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
#	${FIND} ${WRKDIR}/.cache -type f -perm 755 -exec file {} \; | ${EGREP} "ELF|PE32+|Mach-O" | ${AWK} -F ':' '{print $$1}' | ${XARGS} ${RM}
	${FIND} ${WRKDIR}/.pkg-cache -type f -perm 755 -exec file {} \; | ${EGREP} "ELF|PE32+|Mach-O" | ${AWK} -F ':' '{print $$1}' | ${XARGS} ${RM}
	${FIND} ${WRKDIR}/.pkg-cache -type f -perm 644 -exec file {} \; | ${EGREP} -v "${NODE_VERSION_PKGFETCH}" | ${EGREP} "built-v|node-v" | ${EGREP} "tar.gz|sha256sum" | ${AWK} -F ':' '{print $$1}' | ${XARGS} ${RM}

	cd ${WRKDIR} && \
		${TAR} czf ${PORTNAME}-${DISTVERSION}_`date +%Y%m%d`-npm-cache.tar.gz .npm .pkg-cache

.include <bsd.port.post.mk>
