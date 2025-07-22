PORTNAME=	wt
DISTVERSION=	4.11.4
CATEGORIES=	www

MAINTAINER=	info@babaei.net
COMMENT=	Widget-centric C++ library for developing web applications
WWW=		https://www.webtoolkit.eu/wt

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libGraphicsMagick.so:graphics/GraphicsMagick \
		libpng.so:graphics/png
TEST_DEPENDS=	roboto-fonts-ttf>=0:x11-fonts/roboto-fonts-ttf

USES=		cmake:testing compiler:c++14-lang cpe pkgconfig ssl
CPE_VENDOR=	emweb
USE_GITHUB=	yes
GH_ACCOUNT=	emweb
USE_LDCONFIG=	yes
USE_XORG=	x11

CMAKE_ARGS=	-DCONFIGDIR:STRING=${ETCDIR} \
		-DDESTDIR:STRING=${STAGEDIR} \
		-DDOCUMENTATION_DESTINATION:STRING=${DOCSDIR} \
		-DEXAMPLES_DESTINATION:STRING=${EXAMPLESDIR_REL} \
		-DGM_PREFIX:STRING=${LOCALBASE} \
		-DWEBGROUP:STRING=${WWWGRP} \
		-DWEBUSER:STRING=${WWWOWN} \
		-DWT_WRASTERIMAGE_IMPLEMENTATION:STRING=GraphicsMagick
CMAKE_OFF=	BUILD_EXAMPLES ENABLE_MYSQLSERVER ENABLE_QT4 ENABLE_QT5 \
		ENABLE_QT6
CMAKE_TESTING_ON=	BUILD_TESTS

EXTRACT_AFTER_ARGS=	--exclude .gitignore \
			--exclude ${PORTNAME}-${DISTVERSION}/.vscode \
			--exclude ${PORTNAME}-${DISTVERSION}/fuzz \
			--exclude ${PORTNAME}-${DISTVERSION}/jenkins \
			--exclude ${PORTNAME}-${DISTVERSION}/migrate \
			--exclude ${PORTNAME}-${DISTVERSION}/selenium \
			--exclude ${PORTNAME}-${DISTVERSION}/target \
			--no-same-owner --no-same-permissions

PLIST_SUB=	VERSION=${DISTVERSION}
PORTEXAMPLES=	*

OPTIONS_DEFINE=			DEBUG EXAMPLES HARU LIBWTTEST OPENGL PANGO \
				RESOURCES SAML THEMES UNWIND
OPTIONS_DEFAULT=		EXAMPLES FASTCGI HARU LIBWTTEST MYSQL \
				OPENGL PANGO PGSQL RESOURCES SAML SQLITE3 \
				THEMES WTHTTP
OPTIONS_GROUP=			CONNECTOR DBO WSTRING
OPTIONS_GROUP_CONNECTOR=	FASTCGI WTHTTP
OPTIONS_GROUP_DBO=		FIREBIRD MYSQL PGSQL SQLITE3
NO_OPTIONS_SORT=	yes
OPTIONS_SUB=			yes

CONNECTOR_DESC=	Connector
DBO_DESC=	Wt::DBO
EXAMPLES_DESC=	Install examples (implies SQLITE3 and WTHTTP)
FASTCGI_DESC=	Build FastCGI connector
FIREBIRD_DESC=	Build Wt with FirebirdSQL support
HARU_DESC=	Enable Haru Free PDF Library
LIBWTTEST_DESC=	Build Wt::Test for automated (integration/unit) tests
MYSQL_DESC=	Build Wt with MariaDB or MySQL support
PGSQL_DESC=	Build Wt with PostgreSQL support
RESOURCES_DESC=	Install resources directory
SAML_DESC=	Build built-in SAML service provider for Wt::Auth
SQLITE3_DESC=	Build Wt with SQLite 3 support
THEMES_DESC=	Install the source files for Wt's themes
UNWIND_DESC=	Build Wt with stacktrace support using libunwind
WTHTTP_DESC=	Build Wt stand-alone httpd connector

EXAMPLES_IMPLIES=	SQLITE3 WTHTTP
EXAMPLES_CMAKE_BOOL=	BUILD_EXAMPLES INSTALL_EXAMPLES

FASTCGI_LIB_DEPENDS=	libfcgi++.so:www/fcgi \
			libfcgi.so:www/fcgi
FASTCGI_CMAKE_BOOL=	CONNECTOR_FCGI
FASTCGI_CMAKE_ON=	-DFCGI_PREFIX:STRING=${LOCALBASE}

FIREBIRD_USES=		firebird
FIREBIRD_CMAKE_BOOL=	ENABLE_FIREBIRD

HARU_LIB_DEPENDS=	libhpdf.so:print/libharu
HARU_CMAKE_BOOL=	ENABLE_HARU
HARU_CMAKE_ON=		-DHARU_PREFIX:STRING=${LOCALBASE}

LIBWTTEST_CMAKE_BOOL=	ENABLE_LIBWTTEST

MYSQL_USES=		mysql
MYSQL_CMAKE_BOOL=	ENABLE_MYSQL
MYSQL_CMAKE_ON=		-DENABLE_LIBWTDBO:BOOL=ON \
			-DMYSQL_PREFIX:STRING=${LOCALBASE}

OPENGL_USES=		gl xorg
OPENGL_USE=		GL=opengl,glew XORG=x11
OPENGL_CMAKE_BOOL=	ENABLE_OPENGL

PANGO_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
PANGO_USES=		gnome
PANGO_USE=		GNOME=pango
PANGO_CMAKE_BOOL=	ENABLE_PANGO

PGSQL_USES=		pgsql
PGSQL_CMAKE_BOOL=	ENABLE_POSTGRES
PGSQL_CMAKE_ON=		-DENABLE_LIBWTDBO:BOOL=ON \
			-DPOSTGRES_PREFIX:STRING=${LOCALBASE}

RESOURCES_CMAKE_BOOL=	INSTALL_RESOURCES

SAML_LIB_DEPENDS=	liblog4shib.so:devel/log4shib \
			libsaml.so:security/opensaml \
			libxerces-c.so:textproc/xerces-c3 \
			libxml-security-c.so:security/apache-xml-security-c \
			libxmltooling.so:devel/xmltooling
SAML_CMAKE_BOOL=	ENABLE_SAML

SQLITE3_USES=		sqlite:3
SQLITE3_CMAKE_BOOL=	ENABLE_SQLITE
SQLITE3_CMAKE_ON=	-DENABLE_LIBWTDBO:BOOL=ON

THEMES_CMAKE_BOOL=	INSTALL_THEMES

UNWIND_LIB_DEPENDS=	libunwind.so:devel/libunwind
UNWIND_CMAKE_BOOL=	ENABLE_UNWIND

WTHTTP_CMAKE_BOOL=	CONNECTOR_HTTP

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
PLIST_SUB+=	DEBUG_LIBS_POSTFIX="d"
CMAKE_ON+=	DEBUG
.else
PLIST_SUB+=	DEBUG_LIBS_POSTFIX=""
.endif

.if ${PORT_OPTIONS:MMYSQL} || ${PORT_OPTIONS:MPGSQL} || ${PORT_OPTIONS:MSQLITE3}
PLIST_SUB+=	DBO=""
.else
PLIST_SUB+=	DBO="@comment "
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/wt_config.xml \
		${STAGEDIR}${ETCDIR}/wt_config.xml.sample

do-test:
	@cd ${WRKSRC}/test && \
		${BUILD_WRKSRC}/test/test.wt && \
		${BUILD_WRKSRC}/test/test.sqlite3 && \
		${BUILD_WRKSRC}/test/test.http

.include <bsd.port.mk>
