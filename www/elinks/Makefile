# New ports collection makefile for:	links
# Date created:		21 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	elinks
DISTVERSION=	0.11.7
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

MAN1=		elinks.1
MAN5=		elinkskeys.5 elinks.conf.5

OPTIONS=	88COLORS	"Enable 88 color support"	on \
		256COLORS	"Enable 256 color support"	on \
		SPIDERMONKEY	"Enable ECMAScript support (via SpiderMonkey)" off \
		XBELMARKS	"Enable XBEL bookmarks (via expat)" off \
		LOCAL_CGI	"Enable local CGI support" off \
		FINGER		"Enable finger protocol support" off \
		GOPHER		"Enable gopher protocol support" off \
		BITTORRENT	"Enable BitTorrent protocol support" off \
		NNTP		"Enable NNTP (News) protocol support" off \
		FTP		"Enable FTP protocol support" on \
		FSP		"Enable FSP protocol support (via fsplib)" off \
		SMB		"Enable SMB protocol support (via smbclient)" off \
		EXMODE		"Enable exmode (CLI) support" on \
		HIGHLIGHT	"Enable HTML highlighting using DOM engine" on \
		IDN		"Enable international domain name support" off \
		NOROOT		"Enable prevention of usage by root" off \
		FASTMEM		"Enable fast memory allocation functions" on \
		PERLSCRIPT	"Enable Perl scripting support" off \
		RUBYSCRIPT	"Enable Ruby scripting support" off \
		LUASCRIPT	"Enable Lua scripting support" off \
		GUILESCRIPT	"Enable Guile scripting support" off \
		ICONV		"Enable iconv support" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.else
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.endif

.if defined(WITH_RUBYSCRIPT)
LIB_DEPENDS+=	ruby18:${PORTSDIR}/lang/ruby18
CONFIGURE_ARGS+=	--with-ruby
.else
CONFIGURE_ARGS+=	--without-ruby
.endif

.if defined(WITH_GUILESCRIPT)
LIB_DEPENDS+=	guile:${PORTSDIR}/lang/guile
CONFIGURE_ARGS+=	--with-guile
.else
CONFIGURE_ARGS+=	--without-guile
.endif

.if defined(WITH_LUASCRIPT)
USE_LUA=	5.0
CONFIGURE_ARGS+=	--with-lua
CPPFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-L${LUA_LIBDIR}
CONFIGURE_ENV+=	"CPPFLAGS=${CPPFLAGS}"
.else
CONFIGURE_ARGS+=	--without-lua
.endif

.if defined(WITH_PERLSCRIPT)
USE_PERL5=	yes
CONFIGURE_ARGS+=	--with-perl
.else
CONFIGURE_ARGS+=	--without-perl
.endif

.if defined(WITH_FASTMEM)
CONFIGURE_ARGS+=	--enable-fastmem
.endif

.if defined(WITH_IDN)
LIB_DEPENDS+=	idn:${PORTSDIR}/dns/libidn
CONFIGURE_ARGS+=	--with-idn
.else
CONFIGURE_ARGS+=	--without-idn
.endif

.if defined(WITH_NOROOT)
CONFIGURE_ARGS+=	--enable-no-root
.endif

.if defined(WITH_HIGHLIGHT)
CONFIGURE_ARGS+=	--enable-html-highlight
.endif

.if defined(WITH_EXMODE)
CONFIGURE_ARGS+=	--enable-exmode
.endif

.if defined(WITH_SMB)
RUN_DEPENDS+=	smbclient:${PORTSDIR}/net/samba3
BUILD_DEPENDS+=	smbclient:${PORTSDIR}/net/samba3
CONFIGURE_ARGS+=	--enable-smb
.else
CONFIGURE_ARGS+=	--disable-smb
.endif

.if defined(WITH_FSP)
RUN_DEPENDS+=	${LOCALBASE}/lib/libfsp.a:${PORTSDIR}/net/fsplib
BUILD_DEPENDS+=	${LOCALBASE}/lib/libfsp.a:${PORTSDIR}/net/fsplib
CONFIGURE_ARGS+=	--enable-fsp
.else
CONFIGURE_ARGS+=	--disable-fsp
.endif

.if defined(WITH_FTP)
CONFIGURE_ARGS+=	--enable-ftp
.else
CONFIGURE_ARGS+=	--disable-ftp
.endif

.if defined(WITH_NNTP)
CONFIGURE_ARGS+=	--enable-nntp
.else
CONFIGURE_ARGS+=	--disable-nntp
.endif

.if defined(WITH_BITTORRENT)
CONFIGURE_ARGS+=	--enable-bittorrent
.else
CONFIGURE_ARGS+=	--disable-bittorrent
.endif

.if defined(WITH_GOPHER)
CONFIGURE_ARGS+=	--enable-gopher
.else
CONFIGURE_ARGS+=	--disable-gopher
.endif

.if defined(WITH_FINGER)
CONFIGURE_ARGS+=	--enable-finger
.else
CONFIGURE_ARGS+=	--disable-finger
.endif

.if defined(WITH_LOCAL_CGI)
CONFIGURE_ARGS+=	--enable-cgi
.else
CONFIGURE_ARGS+=	--disable-cgi
.endif

.if defined(WITH_XBELMARKS)
LIB_DEPENDS+=	expat:${PORTSDIR}/textproc/expat2
CONFIGURE_ARGS+=	--enable-xbel --with-expat
.else
CONFIGURE_ARGS+=	--disable-xbel
.endif

.if defined(WITH_256COLORS)
CONFIGURE_ARGS+=	--enable-256-colors
.endif

.if defined(WITH_88COLORS)
CONFIGURE_ARGS+=	--enable-88-colors
.endif

.if defined(WITH_SPIDERMONKEY)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libjs.so:${PORTSDIR}/lang/spidermonkey
RUN_DEPENDS+=	js:${PORTSDIR}/lang/spidermonkey
LIB_DEPENDS+=	nspr4:${PORTSDIR}/devel/nspr
CFLAGS+=	-I${LOCALBASE}/include/nspr
LDFLAGS+=	-lnspr4 -pthread -lpthread -lm
CONFIGURE_ARGS+=	--enable-sm-scripting --with-spidermonkey
.else
CONFIGURE_ARGS+=	--disable-sm-scripting --without-spidermonkey
.endif

.if defined(WITH_ICONV)
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

.include <bsd.port.post.mk>
