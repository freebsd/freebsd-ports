# $FreeBSD$

PORTNAME=	uTox
PORTVERSION=	0.11.1
PORTREVISION=	6
CATEGORIES=	net-im net-p2p

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Lightweight Tox client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:net-im/tox12 \
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libsodium.so:security/libsodium \
		libv4lconvert.so:multimedia/libv4l \
		libvpx.so:multimedia/libvpx \
		libfilteraudio.so:audio/libfilteraudio\
		libopus.so:audio/opus
RUN_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:net-im/tox12

USE_GITHUB=	yes
GH_TAGNAME=	1835eae

USES=		cmake compiler:c11 desktop-file-utils localbase:ldflags openal:al	\
		pkgconfig
USE_XORG=	x11 xext xrender

OPTIONS_DEFINE=		DBUS
OPTIONS_DEFAULT=	DBUS

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_MAKE_ARGS_OFF=	DBUS=0

pre-configure:
	${REINPLACE_CMD} -e 's|resolv dl||'	\
		-e 's|/usr/include/freetype2|${LOCALBASE}/include/freetype2|'	\
		${WRKSRC}/CMakeLists.txt

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/utox
	${INSTALL_DATA} ${WRKSRC}/icons/utox-128x128.png ${STAGEDIR}${PREFIX}/share/pixmaps/utox.png

.include <bsd.port.mk>
