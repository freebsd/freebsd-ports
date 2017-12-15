# Created by: arved
# $FreeBSD$

PORTNAME=	newsboat
PORTVERSION=	2.10.1
DISTVERSIONPREFIX=	r
CATEGORIES=	www

MAINTAINER=	mt@markoturk.info
COMMENT=	RSS feed reader for the text console

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libstfl.so:devel/stfl \
		libcurl.so:ftp/curl \
		libjson-c.so:devel/json-c

OPTIONS_DEFINE=	PODCAST
OPTIONS_DEFAULT=PODCAST
OPTIONS_SUB=	yes
PODCAST_DESC=	Podcast client (podbeuter)

USES=		compiler:c++11-lib gettext gmake iconv:translit ncurses perl5 \
		pkgconfig sqlite shebangfix ssl
USE_GITHUB=	yes
USE_CXXSTD=	gnu++11
USE_PERL5=	build
SHEBANG_FILES=	txt2h.pl
USE_GNOME=	libxml2

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,share/man,man,; \
			/^prefix/s|=.*|=${PREFIX}|; /^CXX=/d; \
			s|/usr/local|${LOCALBASE}|" \
				${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,<ncursesw/ncurses.h>,<ncurses.h>,' \
		${WRKSRC}/src/controller.cpp ${WRKSRC}/src/view.cpp
	${REINPLACE_CMD} -e 's,fail "ncursesw",true,; s,fail "libcrypto",true,' \
		${WRKSRC}/config.sh
	${REINPLACE_CMD} -e 's|-liconv|${ICONV_LIB} -lcrypto -lncursesw|;s|-Werror||' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|LDFLAGS+=-L. -fprofile-arcs -ftest-coverage|LDFLAGS+=-L.|' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*boat

.include <bsd.port.post.mk>
