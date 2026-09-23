PORTNAME=	watchman
# frozen at 4.7.0, it is the last version not to use F_GETPATH which isn't
# available on FreeBSD, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=198570
PORTVERSION=	4.7.0
PORTEPOCH=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	File alteration monitoring service
WWW=		https://facebook.github.io/watchman/

LICENSE=	APACHE20

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

PORTSCOUT=	ignore:1 # see PORTVERSION comment

post-patch:
# https://www.gnu.org/prep/standards/html_node/Directory-Variables.html
	@${REINPLACE_CMD} -e 's,xprefix/var,localstatedir,' \
		-e '\,/etc, { s//$$sysconfdir/; /=/s/^/eval /; }' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e '/^docdir = /d' \
		-e '/not-empty/d; /chmod g+s/d;' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
