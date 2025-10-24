PORTNAME=	nchat
PORTVERSION=	5.10.15
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im
EXTRACT_ONLY=	${GH_ACCOUNT}-${PORTNAME}-v${PORTVERSION}_GH0.tar.gz

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Another yet Telegram client
WWW=		https://github.com/d99kris/nchat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake gperf localbase:ldflags ncurses:port \
		pkgconfig readline ssl sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	d99kris

LDFLAGS+=	-lexecinfo
CMAKE_ARGS+=	-DCLIP_X11_WITH_PNG=OFF \
		-DCMAKE_INSTALL_MANDIR=share/man \
		-DCURSES_CURSES_LIBRARY="${LOCALBASE}/lib/libncurses.so" \
		-DCURSES_FORM_LIBRARY="${LOCALBASE}/lib/libform.so" \
		-DCURSES_INCLUDE_PATH="${LOCALBASE}/include/ncurses" \
		-DCURSES_NCURSES_LIBRARY="${LOCALBASE}/lib/libncursesw.so" \
		-DHAS_DYNAMICLOAD=OFF \
		-DHAS_SHARED_LIBS=ON \
		-DHAS_WHATSAPP=OFF

post-install:
	(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -s libtgchat.so libtgchat)

.include <bsd.port.mk>
