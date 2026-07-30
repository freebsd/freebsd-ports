PORTNAME=	elinks
DISTVERSION=	0.20.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/rkd77/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	jailbird@fdf.net
COMMENT=	Links text WWW browser with enhancements
WWW=		https://github.com/rkd77/elinks/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xmlto:textproc/xmlto
LIB_DEPENDS=	libidn2.so:dns/libidn2

USES=		bison:alias cpe gettext-runtime gmake iconv localbase:ldflags \
		meson pkgconfig python:build shebangfix ssl tar:xz

SHEBANG_FILES=	doc/tools/asciidoc/asciidoc.py doc/tools/help2xml \
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
		-Dsysmouse=true \
		-Dtest=true \
		-Dtrue-color=true

TEST_TARGET=	test

LDFLAGS+=	-lexecinfo -lintl

OPTIONS_DEFINE=		BROTLI CSS CURL EXMODE GUILE HIGHLIGHT LIBEVENT \
			LOCAL_CGI LIBRSVG2 LUA MUJS NLS NOROOT PERL PYTHON \
			QUICKJSNG SIXEL SMB SPIDERMONKEY TRE XBELMARKS ZSTD
OPTIONS_DEFAULT=	BROTLI EXMODE HIGHLIGHT PERL
OPTIONS_SUB=		yes

CSS_DESC=		Cascading Style Sheets support (via libcss & libdom)
EXMODE_DESC=		Exmode (CLI) support
HIGHLIGHT_DESC=		HTML highlighting using DOM engine
LIBEVENT_DESC=		Use libevent as event handler
LOCAL_CGI_DESC=		Local CGI support
MUJS_DESC=		ECMAscript support (via MuJS)
NOROOT_DESC=		Prevention of usage by root
QUICKJSNG_DESC=		ECMAScript support (via QuickJS-NG)
SIXEL_DESC=		Show images on sixel compatible terminals
SPIDERMONKEY_DESC=	ECMAScript support (via SpiderMonkey)
TRE_DESC=		TRE regex search support
XBELMARKS_DESC=		XBEL bookmarks (via expat)

BROTLI_LIB_DEPENDS=	libbrotlidec.so:archivers/brotli
BROTLI_MESON_TRUE=	brotli

CSS_IMPLIES=		HIGHLIGHT
CSS_LIB_DEPENDS=	libcss.so:textproc/libcss \
			libdom.so:www/libdom \
			libwapcaplet.so:textproc/libwapcaplet
CSS_MESON_TRUE=		libcss

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_MESON_TRUE=	libcurl

EXMODE_MESON_TRUE=	exmode

GUILE_USES=		guile:3.0
GUILE_MESON_TRUE=	guile

HIGHLIGHT_LIB_DEPENDS=	libdom.so:www/libdom
HIGHLIGHT_MESON_TRUE=	html-highlight

LIBEVENT_LIB_DEPENDS=	libevent.so:devel/libevent
LIBEVENT_MESON_TRUE=	libevent

LIBRSVG2_IMPLIES=	SIXEL
LIBRSVG2_USES=		gnome
LIBRSVG2_USE=		gnome=cairo,gdkpixbuf,librsvg2
LIBRSVG2_MESON_TRUE=	librsvg

LOCAL_CGI_MESON_TRUE=	cgi

LUA_USES=	lua:52+
LUA_MESON_ON=	-Dluapkg=lua-${LUA_VER}

MUJS_LIB_DEPENDS=	libmujs.so:lang/mujs
MUJS_MESON_TRUE=	mujs

NLS_BUILD_DEPENDS=	xxd:sysutils/xxd
NLS_USES=		gettext
NLS_MESON_TRUE=		gettext nls

NOROOT_MESON_TRUE=	no-root

PERL_USES=		perl5
PERL_MESON_TRUE=	perl

PYTHON_USES=		python:run
PYTHON_MESON_TRUE=	python
PYTHON_BINARY_ALIAS=	python=${PYTHON_CMD} python3=${PYTHON_CMD}

QUICKJSNG_LIB_DEPENDS=	libqjs.so:lang/quickjs-ng
QUICKJSNG_MESON_TRUE=	quickjs

SIXEL_LIB_DEPENDS=	libsixel.so:graphics/libsixel
SIXEL_MESON_TRUE=	libsixel

SMB_USES=	samba # smbclient
SMB_MESON_TRUE=	smb

SPIDERMONKEY_IMPLIES=		CSS CURL HIGHLIGHT
SPIDERMONKEY_BUILD_DEPENDS=	${LOCALBASE}/lib/libmozjs-140.so:lang/spidermonkey140
SPIDERMONKEY_LIB_DEPENDS=	libmozjs-140.so:lang/spidermonkey140
SPIDERMONKEY_USES=		compiler:c++17-lang sqlite
SPIDERMONKEY_MESON_TRUE=	sm-scripting spidermonkey
SPIDERMONKEY_CFLAGS=		-I${LOCALBASE}/include/js-140 -DRUST_BINDGEN
SPIDERMONKEY_CXXFLAGS=		-I${LOCALBASE}/include/js-140 -DRUST_BINDGEN
SPIDERMONKEY_LDFLAGS=		-lm -lpthread

TRE_LIB_DEPENDS=	libtre.so:textproc/libtre
TRE_MESON_TRUE=		tre

XBELMARKS_LIB_DEPENDS=	libexpat.so:textproc/expat2
XBELMARKS_MESON_TRUE=	xbel

ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_MESON_TRUE=	zstd

post-patch-PYTHON-on:
	${REINPLACE_CMD} -e '/python3deps/s,python3-embed,python-${PYTHON_VER}-embed,g' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
