PORTNAME=	watchman
PORTVERSION=	4.5.0 # frozen at 4.5.0: the current version 2020.08.10.00 is broken because F_GETPATH isn't currently available on FreeBSD
PORTEPOCH=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	File alteration monitoring service
WWW=		https://facebook.github.io/watchman/

LICENSE=	APACHE20

BROKEN_mips=		fails to build: watchman.h:169: undefined reference to '__sync_add_and_fetch_8'
BROKEN_mips64=		fails to build: watchman.h:169: undefined reference to '__sync_add_and_fetch_8'

BUILD_DEPENDS=	${LOCALBASE}/include/sys/inotify.h:devel/libinotify

USE_GITHUB=	yes
GH_ACCOUNT=	facebook

USES=		autoreconf gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_prog_HAVE_ARC=false ac_cv_header_sys_inotify_h=no
CONFIGURE_ARGS=	--without-python --without-ruby # in separate ports
TEST_TARGET=	check

PLIST_FILES=	bin/${PORTNAME} \
		"@dir(,,2777) /var/run/${PORTNAME}"
PORTDOCS=	README.markdown

OPTIONS_DEFINE=	BACKTRACE PCRE DOCS
OPTIONS_DEFAULT=BACKTRACE PCRE

BACKTRACE_DESC=		Stack backtrace support via (lib)execinfo
BACKTRACE_LIBS=		-lexecinfo

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_WITH=	pcre

CPPFLAGS+=	-Wno-error

PORTSCOUT=	ignore:1 # newer versions (YYYY.MM.DD.dd) use F_GETPATH that isn't currently available on FreeBSD

post-patch:
# https://www.gnu.org/prep/standards/html_node/Directory-Variables.html
	@${REINPLACE_CMD} -e 's,xprefix/var,localstatedir,' \
		-e '\,/etc, { s//$$sysconfdir/; /=/s/^/eval /; }' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e '/^docdir = /d' \
		-e '/not-empty/d; /chmod g+s/d;' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
