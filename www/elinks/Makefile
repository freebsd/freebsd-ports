# Created by: Michael Vasilenko <acid@stu.cn.ua>
# $FreeBSD$

PORTNAME=	elinks
DISTVERSION=	0.11.7
PORTREVISION=	13
CATEGORIES=	www
MASTER_SITES=	http://elinks.or.cz/download/

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Links text WWW browser with enhancements

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		bison:alias cpe gmake localbase ssl tar:bzip2
CONFIGURE_ARGS=	--without-zlib

LIBS+=		-lexecinfo

OPTIONS_DEFINE=		88COLORS 256COLORS SPIDERMONKEY XBELMARKS LOCAL_CGI \
			FINGER GOPHER BITTORRENT NNTP FTP FSP SMB EXMODE \
			HIGHLIGHT IDN NOROOT FASTMEM PERL \
			LUA GUILE ICONV MOUSE NLS
OPTIONS_DEFAULT=	88COLORS 256COLORS FTP EXMODE HIGHLIGHT FASTMEM MOUSE
OPTIONS_SUB=		yes

88COLORS_DESC=		88 color support
256COLORS_DESC=		256 color support
SPIDERMONKEY_DESC=	ECMAScript support (via SpiderMonkey)
XBELMARKS_DESC=		XBEL bookmarks (via expat)
LOCAL_CGI_DESC=		Local CGI support
FSP_DESC=		FSP protocol support (via fsplib)
EXMODE_DESC=		Exmode (CLI) support
HIGHLIGHT_DESC=		HTML highlighting using DOM engine
NOROOT_DESC=		Prevention of usage by root
FASTMEM_DESC=		Fast memory allocation functions

NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls

GUILE_LIB_DEPENDS=	libguile.so:lang/guile
GUILE_CONFIGURE_WITH=	guile

LUA_USES=		lua:51
LUA_CONFIGURE_WITH=	lua
LUA_CPPFLAGS=		-I${LUA_INCDIR}
LUA_LDFLAGS=		-L${LUA_LIBDIR}

PERL_USES=		perl5
PERL_CONFIGURE_WITH=	perl

FASTMEM_CONFIGURE_ON=	--enable-fastmem

IDN_LIB_DEPENDS=	libidn.so:dns/libidn
IDN_CONFIGURE_WITH=	idn

NOROOT_CONFIGURE_ON=	--enable-no-root

HIGHLIGHT_CONFIGURE_ON=	--enable-html-highlight

EXMODE_CONFIGURE_ON=	--enable-exmode

SMB_USES=		samba # smbclient
SMB_CONFIGURE_ENABLE=	smb

FSP_RUN_DEPENDS=	${LOCALBASE}/lib/libfsplib.a:net/fsplib
FSP_BUILD_DEPENDS=	${LOCALBASE}/lib/libfsplib.a:net/fsplib
FSP_CONFIGURE_ENABLE=	fsp

FTP_CONFIGURE_ENABLE=	ftp

NNTP_CONFIGURE_ENABLE=	nntp

BITTORRENT_CONFIGURE_ENABLE=	bittorrent

GOPHER_CONFIGURE_ENABLE=	gopher

MOUSE_CONFIGURE_ENABLE=	mouse

FINGER_CONFIGURE_ENABLE=	finger

LOCAL_CGI_CONFIGURE_ENABLE=	cgi

XBELMARKS_LIB_DEPENDS=	libexpat.so:textproc/expat2
XBELMARKS_CONFIGURE_ON=	--enable-xbel --with-expat
XBELMARKS_CONFIGURE_OFF=--disable-xbel

256COLORS_CONFIGURE_ON=	--enable-256-colors

88COLORS_CONFIGURE_ON=	--enable-88-colors

SPIDERMONKEY_BUILD_DEPENDS=	${LOCALBASE}/lib/libjs.so:lang/spidermonkey17
SPIDERMONKEY_RUN_DEPENDS=	js:lang/spidermonkey17
SPIDERMONKEY_LIB_DEPENDS=	libnspr4.so:devel/nspr
SPIDERMONKEY_CFLAGS=		-I${LOCALBASE}/include/nspr \
				-I${LOCALBASE}/include/js-1.7
SPIDERMONKEY_LDFLAGS=		-lnspr4 -pthread -lpthread -lm
SPIDERMONKEY_CONFIGURE_ON=	--enable-sm-scripting --with-spidermonkey
SPIDERMONKEY_CONFIGURE_OFF=	--disable-sm-scripting --without-spidermonkey

ICONV_USES=		iconv
ICONV_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG}

.include <bsd.port.mk>
