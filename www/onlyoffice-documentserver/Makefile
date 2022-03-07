PORTNAME=	onlyoffice-documentserver
DISTVERSIONPREFIX=	v
DISTVERSION=	7.0.1.50
CATEGORIES=	www
MASTER_SITES+=	LOCAL/mikael/v8/:source1 \
		LOCAL/mikael/onlyoffice/:source2 \
		https://nodejs.org/dist/v16.13.0/:source3 \
		SF/optipng/OptiPNG/optipng-0.7.7/:source4
DISTFILES+=	v8-6.8.275.32_all.tar.gz:source1 \
		v8-6.8.275.32_122aarch64.tar.gz:source1 \
		v8-6.8.275.32_122amd64.tar.gz:source1 \
		node-v16.13.0.tar.gz:source3 \
		optipng-0.7.7.tar.gz:source4 \
		onlyoffice-${DISTVERSION}-npm-cache.tar.gz:source2 \

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Secure office and productivity apps

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	uses aarch64 or amd64 binaries

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs \
		glib>=2.54:devel/glib20 \
		java:java/openjdk11 \
		npm:www/npm-node16
LIB_DEPENDS=	libboost_regex.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libiconv.so:converters/libiconv \
		libicutu.so:devel/icu
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}supervisor>0:sysutils/py-supervisor@${PY_FLAVOR} \
		gsed:textproc/gsed \
		nginx:www/nginx \
		rabbitmq>0:net/rabbitmq \
		webfonts>=0:x11-fonts/webfonts

USES=		autoreconf:build dos2unix fakeroot gmake gnome iconv nodejs:16,build pkgconfig \
		python:3.7+,build qt:5
USE_QT=		qmake_build
USE_GITHUB=	yes
GH_ACCOUNT=	ONLYOFFICE
GH_PROJECT=	DocumentServer
GH_TAGNAME=	v7.0.1
GH_TUPLE=	ONLYOFFICE:core:v${DISTVERSION}:core/core \
		ONLYOFFICE:core-fonts:v${DISTVERSION}:corefonts/core-fonts \
		ONLYOFFICE:dictionaries:v${DISTVERSION}:dictionaries/dictionaries \
		ONLYOFFICE:document-server-integration:v${DISTVERSION}:dsi/document-server-integration \
		ONLYOFFICE:document-templates:v${DISTVERSION}:dt/document-templates \
		ONLYOFFICE:sdkjs:v${DISTVERSION}:sdkjs/sdkjs \
		ONLYOFFICE:server:v${DISTVERSION}:server/server \
		ONLYOFFICE:web-apps:v${DISTVERSION}:webapps/web-apps \
		ONLYOFFICE:plugin-highlightcode:v${DISTVERSION}:sdkjs_plugins_highlightcode/sdkjs-plugins/plugin-highlightcode \
		ONLYOFFICE:plugin-macros:v${DISTVERSION}:sdkjs_plugins_macros/sdkjs-plugins/plugin-macros \
		ONLYOFFICE:plugin-mendeley:v${DISTVERSION}:sdkjs_plugins_mendeley/sdkjs-plugins/plugin-mendeley \
		ONLYOFFICE:plugin-ocr:v${DISTVERSION}:sdkjs_plugins_ocr/sdkjs-plugins/plugin-ocr \
		ONLYOFFICE:plugin-photoeditor:v${DISTVERSION}:sdkjs_plugins_photoeditor/sdkjs-plugins/plugin-photoeditor \
		ONLYOFFICE:plugin-speech:v${DISTVERSION}:sdkjs_plugins_speech/sdkjs-plugins/plugin-speech \
		ONLYOFFICE:plugin-thesaurus:v${DISTVERSION}:sdkjs_plugins_thesaurus/sdkjs-plugins/plugin-thesaurus \
		ONLYOFFICE:plugin-translator:v${DISTVERSION}:sdkjs_plugins_translator/sdkjs-plugins/plugin-translator \
		ONLYOFFICE:plugin-youtube:v${DISTVERSION}:sdkjs_plugins_youtube/sdkjs-plugins/plugin-youtube \
		ONLYOFFICE:plugin-zotero:v${DISTVERSION}:sdkjs_plugins_zotero/sdkjs-plugins/plugin-zotero \
		ONLYOFFICE:build_tools:v${DISTVERSION}:buildtools/build_tools \
		ONLYOFFICE:DocumentBuilder:v${DISTVERSION}:document_builder/DocumentBuilder \
		ONLYOFFICE:onlyoffice.github.io:342e8f66:sdkjs_plugins_v1/onlyoffice.github.io \
		ONLYOFFICE:document-server-package:v${DISTVERSION}:dsp/document-server-package \
		hackers-painters:katana-parser:499118d3:hackers_painters_katana/core/Common/3dParty/html/katana-parser \
		google:gumbo-parser:aa91b27:google_gumbo/core/Common/3dParty/html/gumbo-parser

OPTIONS_SINGLE=		DB
OPTIONS_SINGLE_DB=	MYSQL PGSQL
OPTIONS_DEFAULT=	PGSQL

MYSQL_USES+=	mysql:client
PGSQL_USES+=	pgsql
PGSQL_VARS=	WANT_PGSQL=client

BINARY_ALIAS=	python=${PYTHON_CMD}
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
SUB_LIST=	ETCDIR=${ETCDIR} \
		PREFIX=${PREFIX} \
		WWWDIR=${WWWDIR}

MAKE_ENV=	BUILD_NUMBER="1" \
		PKG_CACHE_PATH=${WRKDIR}/.pkg-cache \
		PRODUCT_VERSION="${DISTVERSION}"

# Don't create __pycache__ directory when executing node-gyp
# This is a workaround to avoid filesystem violations during poudriere build
MAKE_ENV+=	PYTHONDONTWRITEBYTECODE=1

DOS2UNIX_FILES=	document-server-package/common/documentserver/nginx/includes/http-common.conf.m4

CONFLICTS_BUILD=devel/googletest

post-extract:
	@${MV} ${WRKDIR}/v8 ${WRKSRC}/core/Common/3dParty/v8
	@${MKDIR} ${WRKSRC}/core/Common/3dParty/v8/v8/out.gn/freebsd_64
	@${MV} ${WRKDIR}/v8_obj_122${ARCH}/obj ${WRKSRC}/core/Common/3dParty/v8/v8/out.gn/freebsd_64

	@${MKDIR} ${WRKDIR}/.pkg-cache/node
	@${CP} ${DISTDIR}/node-v16.13.0.tar.gz ${WRKDIR}/.pkg-cache/node
# Checksum can be verified here: https://nodejs.org/dist/v16.13.0/SHASUMS256.txt
	@${ECHO} "9c00e5b6024cfcbc9105f9c58cf160762e78659a345d100c5bd80a7fb38c684f  node-v16.13.0.tar.gz" > \
		${WRKDIR}/.pkg-cache/node/node-v16.13.0.tar.gz.sha256sum

	@${MKDIR} ${WRKSRC}/sdkjs-plugins/v1
	@${CP} ${WRKSRC}/onlyoffice.github.io/sdkjs-plugins/v1/* ${WRKSRC}/sdkjs-plugins/v1

	@${MV} ${WRKSRC}/server/Common/config/production-linux.json ${WRKSRC}/server/Common/config/production-freebsd.json
	@${MV} ${WRKSRC}/server/Common/config/development-linux.json ${WRKSRC}/server/Common/config/development-freebsd.json

post-patch:
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/core/Common/3dParty/icu/icu.pri \
		${WRKSRC}/core/DesktopEditor/fontengine/ApplicationFonts.cpp
	@${REINPLACE_CMD} -e 's|%%CC%%|${CC}|' -e 's|%%CXX%%|${CXX}|' \
		${WRKSRC}/core/Common/base.pri
	@${REINPLACE_CMD} 's|%%WRKDIR%%|${WRKDIR}|' \
		${WRKSRC}/document-server-package/Makefile
	@${REINPLACE_CMD} 's|%%WRKSRC%%|${WRKSRC}|' \
		${WRKSRC}/build_tools/scripts/build_js.py \
		${WRKSRC}/build_tools/scripts/build_server.py \
		${WRKSRC}/document-server-package/Makefile
	@${REINPLACE_CMD} -e 's|linux|freebsd|' -e 's|/etc|${LOCALBASE}/etc|' \
		${WRKSRC}/document-server-package/common/documentserver/supervisor/ds-docservice.conf.m4 \
		${WRKSRC}/document-server-package/common/documentserver/supervisor/ds-converter.conf.m4 \
		${WRKSRC}/document-server-package/common/documentserver-example/supervisor/ds-example.conf.m4 \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-static-gzip.sh.m4 \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-update-securelink.sh.m4
	@${REINPLACE_CMD} 's|/var/www|${LOCALBASE}/www|' \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-generate-allfonts.sh.m4 \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-static-gzip.sh.m4 \
		${WRKSRC}/document-server-package/common/documentserver/supervisor/ds-converter.conf.m4 \
		${WRKSRC}/document-server-package/common/documentserver/supervisor/ds-docservice.conf.m4 \
		${WRKSRC}/document-server-package/common/documentserver/supervisor/ds-metrics.conf.m4
	@${REINPLACE_CMD} -e 's|/var/lib|/var/db|' -e 's|/var/www|${LOCALBASE}/www|' \
			  -e 's|/usr/share|${LOCALBASE}/share|' -e 's|/etc|${LOCALBASE}/etc|' \
		${WRKSRC}/server/Common/config/production-freebsd.json \
		${WRKSRC}/server/Common/config/development-freebsd.json
	@${REINPLACE_CMD} -e 's|bash|sh|' -e 's|sed|gsed|' \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-static-gzip.sh.m4 \
		${WRKSRC}/document-server-package/common/documentserver/bin/documentserver-update-securelink.sh.m4
	@${REINPLACE_CMD} 's|%%DISTDIR%%|${DISTDIR}|' \
		${WRKSRC}/web-apps/build/patches/optipng-bin+5.1.0.patch
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' -e 's|%%ETCDIR%%|${ETCDIR}|' \
		${WRKSRC}/document-server-package/Makefile
	@${RM} ${WRKSRC}/web-apps/build/patches/optipng-bin+5.1.0.patch.orig

	@${FIND} ${WRKSRC}/server -type f -name npm-shrinkwrap.json -delete

do-build:
	@${CP} ${FILESDIR}/packagejsons/server/package-lock.json ${WRKSRC}/server
	@${CP} ${FILESDIR}/packagejsons/server/Common/package-lock.json ${WRKSRC}/server/Common

	@cd ${WRKSRC}/web-apps/build ; ${SETENV} ${MAKE_ENV} npm install patch-package
	@cd ${WRKSRC}/web-apps/build ; ${SETENV} ${MAKE_ENV} npm install optipng-bin@5.1.0
	@cd ${WRKSRC}/web-apps/build ; node_modules/.bin/patch-package
	@cd ${WRKSRC}/web-apps/build/node_modules/optipng-bin ; ${SETENV} ${MAKE_ENV} npm run postinstall optipng-bin

	@cd ${WRKSRC}/web-apps/build ; ${SETENV} ${MAKE_ENV} npm install patch-package
	@cd ${WRKSRC}/server ; ${SETENV} ${MAKE_ENV} npm install grunt-cli
	@cd ${WRKSRC}/server ; ${SETENV} ${MAKE_ENV} npm install grunt
	@cd ${WRKSRC}/server ; ${SETENV} ${MAKE_ENV} npm install pkg@5.5.1
	@cd ${WRKSRC}/sdkjs  ; ${SETENV} ${MAKE_ENV} npm install grunt-cli
	@cd ${WRKSRC}/sdkjs  ; ${SETENV} ${MAKE_ENV} npm install grunt
	@cd ${WRKSRC} && ${PATCH} -N -s -i ${FILESDIR}/extra-patch-pkg-fetch_lib-es5_build.js || ${TRUE}
	@cd ${WRKSRC} && ${PATCH} -N -s -i ${FILESDIR}/extra-patch-pkg-fetch_patches_node.v16.13.0.cpp.patch || ${TRUE}

	cd ${WRKSRC}/build_tools/tools/freebsd ; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} automate.py
	cd ${WRKSRC}/document-server-package ; ${SETENV} ${MAKE_ENV} ${GMAKE} freebsd

do-install:
# install the project
# do not strip docservice, converter and metrics
	cd ${WRKSRC}/document-server-package/common/documentserver/home && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/documentserver
	${INSTALL_SCRIPT} ${WRKSRC}/document-server-package/common/documentserver/bin/*.sh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/document-server-package/common/documentserver/home/server/tools/all* ${STAGEDIR}${WWWDIR}/documentserver/server/tools
	${INSTALL_PROGRAM} ${WRKSRC}/document-server-package/common/documentserver/home/server/FileConverter/bin/x2t ${STAGEDIR}${WWWDIR}/documentserver/server/FileConverter/bin
	${INSTALL_PROGRAM} ${WRKSRC}/document-server-package/common/documentserver/home/server/FileConverter/bin/docbuilder ${STAGEDIR}${WWWDIR}/documentserver/server/FileConverter/bin
	${INSTALL_PROGRAM} ${WRKSRC}/document-server-package/common/documentserver/home/npm/json ${STAGEDIR}${WWWDIR}/documentserver/npm
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
.for f in ds.conf ds-ssl.conf includes/http-common.conf includes/ds-common.conf includes/ds-docservice.conf includes/ds-letsencrypt.conf
	${INSTALL_DATA} ${WRKSRC}/document-server-package/common/documentserver/nginx/${f} ${STAGEDIR}${ETCDIR}/documentserver/nginx/${f}.sample
.endfor
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

.include <bsd.port.mk>
