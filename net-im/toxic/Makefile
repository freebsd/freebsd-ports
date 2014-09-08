# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	toxic
PORTVERSION=	0.5.0.140908
CATEGORIES=	net-im

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Console client for Tox

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:${PORTSDIR}/net-im/tox
LIB_DEPENDS=	libvpx.so:${PORTSDIR}/multimedia/libvpx		\
		libopus.so:${PORTSDIR}/audio/opus		\
		libalut.so:${PORTSDIR}/audio/freealut		\
		libconfig.so:${PORTSDIR}/devel/libconfig	\
		libopenal.so.1:${PORTSDIR}/audio/openal-soft
RUN_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:${PORTSDIR}/net-im/tox

USE_GITHUB=	yes
GH_ACCOUNT=	tox
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	09f90d0

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_USE=	XORG=x11
X11_CFLAGS_OFF=	DISABLE_X11=1 DISABLE_DESKTOP_NOTIFY=1
X11_LIB_DEPENDS=libnotify.so:${PORTSDIR}/devel/libnotify

WRKSRC=		${WRKDIR}/Tox-${PORTNAME}-${GH_COMMIT}
BUILD_WRKSRC=	${WRKSRC}/build
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MAKE_ENV=	USER_CFLAGS="${CFLAGS}" USER_LDFLAGS="${LDFLAGS}"
SUB_FILES=	pkg-message

USES=		ncurses:port gmake pkgconfig

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900033
USE_BINUTILS=	yes
LDFLAGS+=	-B${LOCALBASE}/bin
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|PREFIX =|PREFIX?=|;s|$$(shell git rev-list HEAD --count)|${GH_COMMIT}|'	\
		${WRKSRC}/cfg/global_vars.mk

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/toxic

.include <bsd.port.post.mk>
