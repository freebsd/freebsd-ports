PORTNAME=	elinks
DISTVERSIONPREFIX=	v
DISTVERSION=	0.18.0
CATEGORIES=	www

MAINTAINER=	jailbird@fdf.net
COMMENT=	Links text WWW browser with enhancements
WWW=		https://github.com/rkd77/elinks/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xmlto:textproc/xmlto
LIB_DEPENDS=	libidn2.so:dns/libidn2

USES=		bison:alias cpe gettext-runtime:build gmake iconv localbase \
		meson perl5 pkgconfig python:build shebangfix ssl
TEST_USES=	gettext-tools:build
USE_GITHUB=	yes
GH_ACCOUNT=	rkd77

LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo -lintl
TEST_TARGET=	test
SHEBANG_FILES=	doc/tools/help2xml doc/tools/asciidoc/asciidoc.py \
		src/protocol/ftp/test-ftp-parser
MESON_ARGS=	-D256-colors=true \
		-D88-colors=true \
		-Dapidoc=false \
		-Dbzlib=true \
		-Dcodepoint=false \
		-Dfastmem=true \
		-Dfinger=true \
		-Dfsp2=true \
		-Dgemini=true \
		-Dgopher=true \
		-Dgpm=false \
		-Dhtmldoc=true \
		-Didn=true \
		-Dlzma=true \
		-Dnntp=true \
		-Dpdfdoc=false \
		-Dperl=true \
		-Dsysmouse=true \
		-Dtest=true \
		-Dtrue-color=true

OPTIONS_DEFINE=		BROTLI CSS CURL EXMODE GUILE HIGHLIGHT LIBEVENT \
			LOCAL_CGI LUA MUJS NLS NOROOT PYTHON SIXEL SMB \
			SPIDERMONKEY TRE XBELMARKS ZSTD
OPTIONS_DEFAULT=	BROTLI EXMODE HIGHLIGHT
OPTIONS_SUB=		yes

CSS_DESC=		Cascading Style Sheets support (via libcss & libdom)
EXMODE_DESC=		Exmode (CLI) support
HIGHLIGHT_DESC=		HTML highlighting using DOM engine
LIBEVENT_DESC=		Use libevent as event handler
LOCAL_CGI_DESC=		Local CGI support
MUJS_DESC=		ECMAscript support (via MuJS)
NOROOT_DESC=		Prevention of usage by root
SIXEL_DESC=		Show images on sixel compatible terminals
SPIDERMONKEY_DESC=	ECMAScript support (via SpiderMonkey)
TRE_DESC=		TRE regex search support
XBELMARKS_DESC=		XBEL bookmarks (via expat)

BROTLI_LIB_DEPENDS=	libbrotlidec.so:archivers/brotli
BROTLI_MESON_TRUE=	brotli

CSS_LIB_DEPENDS=	libcss.so:textproc/libcss \
			libdom.so:www/libdom \
			libwapcaplet.so:textproc/libwapcaplet
CSS_MESON_TRUE=		libcss
CSS_IMPLIES=		HIGHLIGHT

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_MESON_TRUE=	libcurl

EXMODE_MESON_TRUE=	exmode

GUILE_USES=		guile:3.0
GUILE_MESON_TRUE=	guile

HIGHLIGHT_LIB_DEPENDS=	libdom.so:www/libdom
HIGHLIGHT_MESON_TRUE=	html-highlight

LIBEVENT_LIB_DEPENDS=	libevent.so:devel/libevent
LIBEVENT_MESON_TRUE=	libevent

LOCAL_CGI_MESON_TRUE=	cgi

LUA_USES=	lua:52-53
LUA_MESON_ON=	-Dluapkg=lua-${LUA_VER}

MUJS_LIB_DEPENDS=	libmujs.so:lang/mujs
MUJS_MESON_TRUE=	mujs

NLS_USES=		gettext-tools
NLS_BUILD_DEPENDS=	xxd:sysutils/xxd
NLS_MESON_TRUE=		gettext nls

NOROOT_MESON_TRUE=	no-root

PYTHON_USES=		python:run
PYTHON_MESON_TRUE=	python

SIXEL_LIB_DEPENDS=	libsixel.so:graphics/libsixel
SIXEL_MESON_TRUE=	libsixel

SMB_USES=	samba # smbclient
SMB_MESON_TRUE=	smb

SPIDERMONKEY_USES=		compiler:c++17-lang sqlite
SPIDERMONKEY_BUILD_DEPENDS=	${LOCALBASE}/lib/libmozjs-128.so:lang/spidermonkey128
SPIDERMONKEY_LIB_DEPENDS=	libmozjs-128.so:lang/spidermonkey128
SPIDERMONKEY_CFLAGS=		-I${LOCALBASE}/include/js-128
SPIDERMONKEY_CXXFLAGS=		-I${LOCALBASE}/include/js-128
SPIDERMONKEY_LDFLAGS=		-lpthread -lm
SPIDERMONKEY_MESON_TRUE=	sm-scripting spidermonkey
SPIDERMONKEY_IMPLIES=		CSS CURL HIGHLIGHT

TRE_LIB_DEPENDS=	libtre.so:textproc/libtre
TRE_MESON_TRUE=		tre

XBELMARKS_LIB_DEPENDS=	libexpat.so:textproc/expat2
XBELMARKS_MESON_TRUE=	xbel

ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_MESON_TRUE=	zstd

.include <bsd.port.mk>
