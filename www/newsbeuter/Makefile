# Created by: arved
# $FreeBSD$

PORTNAME=	newsbeuter
PORTVERSION=	2.8
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://newsbeuter.org/downloads/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	An RSS feed reader for the text console

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libstfl.so:${PORTSDIR}/devel/stfl \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libjson.so:${PORTSDIR}/devel/json-c

OPTIONS_DEFINE= PODCAST
OPTIONS_DEFAULT=PODCAST
OPTIONS_SUB=	yes
PODCAST_DESC=	Podcast client (podbeuter)

USES=		compiler:c++11-lang gettext gmake iconv:translit ncurses perl5 pkgconfig
USE_CXXSTD=	gnu++11
USE_PERL5=	build
USE_SQLITE=	yes
USE_GNOME=	libxml2

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

.include <bsd.port.mk>
