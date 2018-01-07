# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	toxic
PORTVERSION=	0.8.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-im

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Console client for Tox

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:net-im/tox	\
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libvpx.so:multimedia/libvpx		\
		libsodium.so:security/libsodium		\
		libpng.so:graphics/png		\
		libopus.so:audio/opus			\
		libcurl.so:ftp/curl			\
		libv4l2.so:multimedia/libv4l		\
		libqrencode.so:graphics/libqrencode	\
		libconfig.so:devel/libconfig
RUN_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:net-im/tox

USE_GITHUB=	yes
GH_ACCOUNT=	JFreegman

OPTIONS_DEFINE=	X11 PYTHON
OPTIONS_DEFAULT=X11

X11_USE=	GNOME=gdkpixbuf2,glib20 XORG=x11
X11_MAKE_ARGS_OFF=	DISABLE_X11=1 DISABLE_DESKTOP_NOTIFY=1
X11_LIB_DEPENDS=libnotify.so:devel/libnotify

PYTHON_VARS=	USES+=python:3.3+
PYTHON_MAKE_ARGS=	ENABLE_PYTHON=1

MAKE_ENV=	USER_CFLAGS="${CFLAGS}" USER_LDFLAGS="${LDFLAGS}"
LLD_UNSAFE=	yes
SUB_FILES=	pkg-message

USES=		desktop-file-utils gettext-runtime gmake ncurses openal:al,alut pkgconfig

pre-configure:
	${REINPLACE_CMD} -e 's|PREFIX =|PREFIX?=|;s|$$(shell git rev-list HEAD.*$$|${GH_TAGNAME}|'	\
		${WRKSRC}/cfg/global_vars.mk

post-install:
	${RM} ${STAGEDIR}${MANPREFIX}/man/man1/toxic.1-e ${STAGEDIR}${MANPREFIX}/man/man5/toxic.conf.5-e
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/toxic

.include <bsd.port.mk>
