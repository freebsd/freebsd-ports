# Created by: Thierry Thomas <thierry@pompo.net>

PORTNAME=	toxic
PORTVERSION=	0.11.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Console client for Tox

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:net-im/tox	\
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libvpx.so:multimedia/libvpx		\
		libpng.so:graphics/png			\
		libcurl.so:ftp/curl			\
		libv4l2.so:multimedia/libv4l		\
		libqrencode.so:graphics/libqrencode	\
		libconfig.so:devel/libconfig
RUN_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:net-im/tox

USES=		compiler:c11 desktop-file-utils gettext-runtime gmake ncurses openal:al,alut pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	JFreegman

OPTIONS_DEFINE=	GAMES X11 PYTHON
OPTIONS_DEFAULT=GAMES X11

GAMES_DESC=	Includes a games module
GAMES_MAKE_ARGS_OFF=	DISABLE_GAMES=1

X11_USES=	gnome xorg
X11_USE=	GNOME=gdkpixbuf2,glib20 XORG=x11
X11_MAKE_ARGS_OFF=	DISABLE_X11=1 DISABLE_DESKTOP_NOTIFY=1
X11_LIB_DEPENDS=libnotify.so:devel/libnotify

PYTHON_USES=	python:3.8+
PYTHON_MAKE_ARGS=	ENABLE_PYTHON=1

CFLAGS+=	-I${NCURSESINC} -pthread
LDFLAGS+=	-L${NCURSESLIB}
LDFLAGS_i386=	-Wl,-znotext
MAKE_ENV=	USER_CFLAGS="${CFLAGS}" USER_LDFLAGS="${LDFLAGS}"	\
		MANDIR="${MANPREFIX}/man"
SUB_FILES=	pkg-message

pre-configure-PYTHON-on:
	${REINPLACE_CMD} -e '/PYTHON3_LIBS/ s|python3|python-${PYTHON_VER}|'	\
			 -e 's|python3-config|${PYTHON_VERSION}-config|g'	\
			 -e 's|--ldflags|--ldflags --embed|'			\
		${WRKSRC}/cfg/checks/python.mk

pre-configure:
	${REINPLACE_CMD} -e 's|PREFIX =|PREFIX?=|;s|$$(shell git rev-list HEAD.*$$|${GH_TAGNAME}|'	\
		${WRKSRC}/cfg/global_vars.mk

post-install:
	${RM} ${STAGEDIR}${MANPREFIX}/man/man1/toxic.1-e ${STAGEDIR}${MANPREFIX}/man/man5/toxic.conf.5-e
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/toxic

.include <bsd.port.mk>
