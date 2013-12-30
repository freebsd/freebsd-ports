# Created by: arved
# $FreeBSD$

PORTNAME=	newsbeuter
PORTVERSION=	2.7
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://newsbeuter.org/downloads/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	An RSS feed reader for the text console

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	stfl:${PORTSDIR}/devel/stfl \
		curl:${PORTSDIR}/ftp/curl \
		libjson.so:${PORTSDIR}/devel/json-c

OPTIONS_DEFINE= PODCAST
PODCAST_DESC=	Podcast client (podbeuter)

OPTIONS_DEFAULT= PODCAST

USES=		gettext iconv ncurses gmake pkgconfig perl5
USE_PERL5=	build
USE_SQLITE=	yes
USE_GNOME=	libxml2
USE_GCC=	any

.include  <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPODCAST}
PLIST_SUB+=	PODCAST=""
.else
PLIST_SUB+=	PODCAST="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e "s,share/man,man,; \
			/^prefix/s|=.*|=${PREFIX}|; /^CXX=/d; \
			s|/usr/local|${LOCALBASE}|; s|ruby1.8|ruby18|" \
				${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's,<ncursesw/ncurses.h>,<ncurses.h>,' \
		${WRKSRC}/src/controller.cpp ${WRKSRC}/src/view.cpp
	${REINPLACE_CMD} -e 's,fail "ncursesw5",true,; s,fail "libcrypto",true,' \
		${WRKSRC}/config.sh
	${REINPLACE_CMD} -e 's|-liconv|${ICONV_LIB} -lcrypto -lncursesw|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
