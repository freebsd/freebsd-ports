# Created by: arved
# $FreeBSD$

PORTNAME=	newsbeuter
PORTVERSION=	2.9
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	https://newsbeuter.org/downloads/ \
		http://newsbeuter.org/downloads/

MAINTAINER=	arved@FreeBSD.org
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
USE_CXXSTD=	gnu++11
USE_PERL5=	build
SHEBANG_FILES=	txt2h.pl
USE_GNOME=	libxml2

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,share/man,man,; \
			/^prefix/s|=.*|=${PREFIX}|; /^CXX=/d; \
			s|/usr/local|${LOCALBASE}|; s|ruby1.8|ruby18|" \
				${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,<ncursesw/ncurses.h>,<ncurses.h>,' \
		${WRKSRC}/src/controller.cpp ${WRKSRC}/src/view.cpp
	${REINPLACE_CMD} -e 's,fail "ncursesw",true,; s,fail "libcrypto",true,' \
		${WRKSRC}/config.sh
	${REINPLACE_CMD} -e 's|-liconv|${ICONV_LIB} -lcrypto -lncursesw|' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*beuter

.include <bsd.port.post.mk>
