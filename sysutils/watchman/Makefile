# Created by: Jin-Sih, Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	watchman
PORTVERSION=	4.5.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	linpct@gmail.com
COMMENT=	File alteration monitoring service

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	facebook

USES=		autoreconf gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_prog_HAVE_ARC=false ac_cv_header_sys_inotify_h=no
CONFIGURE_ARGS=	--without-python --without-ruby # in separate ports
TEST_TARGET=	check

.if defined(BATCH) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--disable-silent-rules
.endif

PLIST_FILES=	bin/${PORTNAME} \
		"@dir(,,2777) /var/run/${PORTNAME}"
PORTDOCS=	README.markdown

OPTIONS_DEFINE=	BACKTRACE PCRE
OPTIONS_DEFAULT=BACKTRACE PCRE

BACKTRACE_DESC=		Stack backtrace support via (lib)execinfo
BACKTRACE_USES=		execinfo
BACKTRACE_CPPFLAGS=	${EXECINFO_CPPFLAGS}
BACKTRACE_LDFLAGS=	${EXECINFO_LDFLAGS}
BACKTRACE_LIBS=		-lexecinfo

PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
PCRE_CONFIGURE_WITH=	pcre

CPPFLAGS+=	-Wno-error

post-patch:
# https://www.gnu.org/prep/standards/html_node/Directory-Variables.html
	@${REINPLACE_CMD} -e 's,xprefix/var,localstatedir,' \
		-e '\,/etc, { s//$$sysconfdir/; /=/s/^/eval /; }' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e '/^docdir = /d' \
		-e '/not-empty/d; /chmod g+s/d;' \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
