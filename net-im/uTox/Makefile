# $FreeBSD$

PORTNAME=	uTox
PORTVERSION=	0.7.0.20160321
CATEGORIES=	net-im net-p2p

MAINTAINER=	fidaj@ukr.net
COMMENT=	Lightweight Tox client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:net-im/tox \
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libsodium.so:security/libsodium \
		libv4lconvert.so:multimedia/libv4l \
		libvpx.so:multimedia/libvpx \
		libfilteraudio.so:audio/libfilteraudio
RUN_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:net-im/tox

USE_GITHUB=	yes
GH_ACCOUNT=	GrayHatter
GH_TAGNAME=	9524f98

USES=		compiler:c11 desktop-file-utils gmake openal:al pkgconfig
USE_XORG=	x11 xext xrender
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		DBUS
OPTIONS_DEFAULT=	DBUS

DBUS_LIB_DEPENDS=	libdbus-1.so:devel/dbus
DBUS_MAKE_ARGS_OFF=	DBUS=0

post-patch:
	@${REINPLACE_CMD} -e 's|$$(GIT_V)|${DISTVERSION}-${GH_TAGNAME}|' \
		-e 's|(DATAROOTDIR)/man|(PREFIX)/man|' ${WRKSRC}/${MAKEFILE}

pre-configure:
	@(if [ ! -e "${LOCALBASE}/lib/libtoxav.so" ]; then \
		${ECHO_CMD} "==> ${PKGNAME} requires net-im/tox port to be built with SODIUM option enabled"; \
		${FALSE}; \
	fi)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/utox

.include <bsd.port.mk>
