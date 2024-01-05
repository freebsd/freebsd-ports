PORTNAME=	elinks
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
CATEGORIES=	www

MAINTAINER=	jailbird@fdf.net
COMMENT=	Links text WWW browser with enhancements
WWW=		https://github.com/rkd77/elinks/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xmlto:textproc/xmlto

USES=		bison:alias cpe gmake iconv meson perl5 pkgconfig python ssl
USE_GITHUB=	yes
GH_ACCOUNT=	rkd77

LDFLAGS+=	-lexecinfo
MESON_ARGS=	-Dgpm=false -Dperl=true

OPTIONS_DEFINE=		256COLORS 88COLORS TRUECOLORS BITTORRENT BROTLI CSS \
			CURL EXMODE FASTMEM FINGER FSP FTP GOPHER GUILE \
			HIGHLIGHT IDN LOCAL_CGI LUA LZMA MOUSE NLS NNTP NOROOT \
			SMB SPIDERMONKEY TRE XBELMARKS ZSTD
OPTIONS_DEFAULT=	256COLORS 88COLORS BROTLI EXMODE FASTMEM FTP \
			HIGHLIGHT LZMA MOUSE
OPTIONS_SUB=		yes

88COLORS_DESC=		88 color support
256COLORS_DESC=		256 color support
TRUECOLORS_DESC=	True color support
CSS_DESC=		Cascading Style Sheets support (via libcss & libdom)
EXMODE_DESC=		Exmode (CLI) support
FASTMEM_DESC=		Fast memory allocation functions
FSP_DESC=		FSP protocol support (via fsplib)
HIGHLIGHT_DESC=		HTML highlighting using DOM engine
LOCAL_CGI_DESC=		Local CGI support
NOROOT_DESC=		Prevention of usage by root
SPIDERMONKEY_DESC=	ECMAScript support (via SpiderMonkey)
TRE_DESC=		TRE regex search support
XBELMARKS_DESC=		XBEL bookmarks (via expat)

256COLORS_MESON_TRUE=	256-colors

88COLORS_MESON_TRUE=	88-colors

TRUECOLORS_MESON_TRUE=	true-color

BITTORRENT_MESON_TRUE=	bittorrent

BROTLI_LIB_DEPENDS=	libbrotlidec.so:archivers/brotli
BROTLI_MESON_TRUE=	brotli

CSS_LIB_DEPENDS=	libcss.so:textproc/libcss \
			libdom.so:www/libdom
CSS_MESON_TRUE=		libcss

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_MESON_TRUE=	libcurl

EXMODE_MESON_TRUE=	exmode

FASTMEM_MESON_TRUE=	fastmem

FINGER_MESON_TRUE=	finger

FSP_RUN_DEPENDS=	${LOCALBASE}/lib/libfsplib.a:net/fsplib
FSP_BUILD_DEPENDS=	${LOCALBASE}/lib/libfsplib.a:net/fsplib
FSP_MESON_TRUE=		fsp

FTP_MESON_TRUE=		ftp

GOPHER_MESON_TRUE=	gopher

GUILE_USES=		guile:3.0
GUILE_MESON_TRUE=	guile

HIGHLIGHT_MESON_TRUE=	html-highlight

IDN_LIB_DEPENDS=	libidn2.so:dns/libidn2
IDN_USES=		localbase
IDN_MESON_TRUE=		idn

LOCAL_CGI_MESON_TRUE=	cgi

LUA_USES=		lua:52-53
LUA_MESON_ON=		-Dluapkg=lua-${LUA_VER}

LZMA_MESON_TRUE=	lzma

MOUSE_MESON_TRUE=	mouse

NLS_USES=		gettext
NLS_MESON_TRUE=		nls

NNTP_MESON_TRUE=	nntp

NOROOT_MESON_TRUE=	no-root

SMB_USES=		samba # smbclient
SMB_MESON_TRUE=		smb

SPIDERMONKEY_USES=		compiler:c++17-lang sqlite
SPIDERMONKEY_BUILD_DEPENDS=	${LOCALBASE}/lib/libmozjs-102.so:lang/spidermonkey102 \
				${LOCALBASE}/lib/libxml++-5.0.so:textproc/libxml++
SPIDERMONKEY_LIB_DEPENDS=	libnspr4.so:devel/nspr \
				libxml++-5.0.so:textproc/libxml++
SPIDERMONKEY_CFLAGS=		-I${LOCALBASE}/include/nspr \
				-I${LOCALBASE}/include/js-102
SPIDERMONKEY_CXXFLAGS=		-I${LOCALBASE}/include/nspr \
				-I${LOCALBASE}/include/js-102
SPIDERMONKEY_LDFLAGS=		-L${LOCALBASE}/lib -lnspr4 -lpthread -lm
SPIDERMONKEY_MESON_ON=		-Dsm-scripting=true -Dspidermonkey=true
SPIDERMONKEY_IMPLIES=		CURL

TRE_LIB_DEPENDS=	libtre.so:textproc/libtre
TRE_MESON_TRUE=		tre

XBELMARKS_LIB_DEPENDS=	libexpat.so:textproc/expat2
XBELMARKS_MESON_TRUE=	xbel

ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_USES=		localbase
ZSTD_MESON_TRUE=	zstd

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|g' ${WRKSRC}/doc/tools/help2xml
	@${REINPLACE_CMD} -e 's|/usr/bin/env python3|${PYTHON_CMD}|g' ${WRKSRC}/doc/tools/asciidoc/asciidoc.py

.include <bsd.port.mk>
