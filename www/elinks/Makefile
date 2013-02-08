# New ports collection makefile for:	links
# Date created:		21 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	elinks
DISTVERSION=	0.11.7
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://elinks.or.cz/download/

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Elinks - links text WWW browser with enhancements

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_BISON=	build
USE_OPENSSL=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

SAMBA_PORT?=	net/samba36

MAN1=		elinks.1
MAN5=		elinkskeys.5 elinks.conf.5

OPTIONS_DEFINE=		88COLORS 256COLORS SPIDERMONKEY XBELMARKS LOCAL_CGI \
			FINGER GOPHER BITTORRENT NNTP FTP FSP SMB EXMODE \
			HIGHLIGHT IDN NOROOT FASTMEM PERL RUBY \
			LUA GUILE ICONV MOUSE NLS
OPTIONS_DEFAULT=	88COLORS 256COLORS FTP EXMODE HIGHLIGHT FASTMEM MOUSE
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

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=	--without-zlib

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.else
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.endif

.if ${PORT_OPTIONS:MRUBY}
LIB_DEPENDS+=	ruby18:${PORTSDIR}/lang/ruby18
CONFIGURE_ARGS+=	--with-ruby
.else
CONFIGURE_ARGS+=	--without-ruby
.endif

.if ${PORT_OPTIONS:MGUILE}
LIB_DEPENDS+=	guile:${PORTSDIR}/lang/guile
CONFIGURE_ARGS+=	--with-guile
.else
CONFIGURE_ARGS+=	--without-guile
.endif

.if ${PORT_OPTIONS:MLUA}
USE_LUA=	5.0
CONFIGURE_ARGS+=	--with-lua
CPPFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-L${LUA_LIBDIR}
.else
CONFIGURE_ARGS+=	--without-lua
.endif

.if ${PORT_OPTIONS:MPERL}
USE_PERL5=	yes
CONFIGURE_ARGS+=	--with-perl
.else
CONFIGURE_ARGS+=	--without-perl
.endif

.if ${PORT_OPTIONS:MFASTMEM}
CONFIGURE_ARGS+=	--enable-fastmem
.endif

.if ${PORT_OPTIONS:MIDN}
LIB_DEPENDS+=	idn:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=	--with-idn
.else
CONFIGURE_ARGS+=	--without-idn
.endif

.if ${PORT_OPTIONS:MNOROOT}
CONFIGURE_ARGS+=	--enable-no-root
.endif

.if ${PORT_OPTIONS:MHIGHLIGHT}
CONFIGURE_ARGS+=	--enable-html-highlight
.endif

.if ${PORT_OPTIONS:MEXMODE}
CONFIGURE_ARGS+=	--enable-exmode
.endif

.if ${PORT_OPTIONS:MSMB}
RUN_DEPENDS+=	smbclient:${PORTSDIR}/${SAMBA_PORT}
BUILD_DEPENDS+=	smbclient:${PORTSDIR}/${SAMBA_PORT}
CONFIGURE_ARGS+=	--enable-smb
.else
CONFIGURE_ARGS+=	--disable-smb
.endif

.if ${PORT_OPTIONS:MFSP}
RUN_DEPENDS+=	${LOCALBASE}/lib/libfsplib.a:${PORTSDIR}/net/fsplib
BUILD_DEPENDS+=	${LOCALBASE}/lib/libfsplib.a:${PORTSDIR}/net/fsplib
CONFIGURE_ARGS+=	--enable-fsp
.else
CONFIGURE_ARGS+=	--disable-fsp
.endif

.if ${PORT_OPTIONS:MFTP}
CONFIGURE_ARGS+=	--enable-ftp
.else
CONFIGURE_ARGS+=	--disable-ftp
.endif

.if ${PORT_OPTIONS:MNNTP}
CONFIGURE_ARGS+=	--enable-nntp
.else
CONFIGURE_ARGS+=	--disable-nntp
.endif

.if ${PORT_OPTIONS:MBITTORRENT}
CONFIGURE_ARGS+=	--enable-bittorrent
.else
CONFIGURE_ARGS+=	--disable-bittorrent
.endif

.if ${PORT_OPTIONS:MGOPHER}
CONFIGURE_ARGS+=	--enable-gopher
.else
CONFIGURE_ARGS+=	--disable-gopher
.endif

.if ${PORT_OPTIONS:MMOUSE}
CONFIGURE_ARGS+=	--enable-mouse
.else
CONFIGURE_ARGS+=	--disable-mouse
.endif

.if ${PORT_OPTIONS:MFINGER}
CONFIGURE_ARGS+=	--enable-finger
.else
CONFIGURE_ARGS+=	--disable-finger
.endif

.if ${PORT_OPTIONS:MLOCAL_CGI}
CONFIGURE_ARGS+=	--enable-cgi
.else
CONFIGURE_ARGS+=	--disable-cgi
.endif

.if ${PORT_OPTIONS:MXBELMARKS}
LIB_DEPENDS+=	expat:${PORTSDIR}/textproc/expat2
CONFIGURE_ARGS+=	--enable-xbel --with-expat
.else
CONFIGURE_ARGS+=	--disable-xbel
.endif

.if ${PORT_OPTIONS:M256COLORS}
CONFIGURE_ARGS+=	--enable-256-colors
.endif

.if ${PORT_OPTIONS:M88COLORS}
CONFIGURE_ARGS+=	--enable-88-colors
.endif

.if ${PORT_OPTIONS:MSPIDERMONKEY}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libjs.so:${PORTSDIR}/lang/spidermonkey17
RUN_DEPENDS+=	js:${PORTSDIR}/lang/spidermonkey17
LIB_DEPENDS+=	nspr4:${PORTSDIR}/devel/nspr
CFLAGS+=	-I${LOCALBASE}/include/nspr
LDFLAGS+=	-lnspr4 -pthread -lpthread -lm
CONFIGURE_ARGS+=	--enable-sm-scripting --with-spidermonkey
.else
CONFIGURE_ARGS+=	--disable-sm-scripting --without-spidermonkey
.endif

.if ${PORT_OPTIONS:MICONV}
USE_ICONV=	yes
CONFIGURE_ARGS+=	--with-libiconv-prefix=${LOCALBASE}
.endif

#
# Elinks will try to use it if exists
#
.if exists(${LOCALBASE}/include/execinfo.h)
LIB_DEPENDS+=	execinfo.1:${PORTSDIR}/devel/libexecinfo
LDFLAGS+=	-L${LOCALBASE}/lib -lexecinfo
.endif

.include <bsd.port.mk>
