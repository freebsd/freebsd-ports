# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	toxic
PORTVERSION=	0.5.2.141025
CATEGORIES=	net-im

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Console client for Tox

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:${PORTSDIR}/net-im/tox
LIB_DEPENDS=	libvpx.so:${PORTSDIR}/multimedia/libvpx		\
		libopus.so:${PORTSDIR}/audio/opus		\
		libconfig.so:${PORTSDIR}/devel/libconfig
RUN_DEPENDS=	${LOCALBASE}/lib/libtoxcore.a:${PORTSDIR}/net-im/tox

USE_GITHUB=	yes
GH_ACCOUNT=	tox
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	e22b7a3

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_USE=	XORG=x11
X11_MAKE_ARGS_OFF=	DISABLE_X11=1 DISABLE_DESKTOP_NOTIFY=1
X11_LIB_DEPENDS=libnotify.so:${PORTSDIR}/devel/libnotify

WRKSRC=		${WRKDIR}/Tox-${PORTNAME}-${GH_COMMIT}
BUILD_WRKSRC=	${WRKSRC}/build
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MAKE_ENV=	USER_CFLAGS="${CFLAGS}" USER_LDFLAGS="${LDFLAGS}"
SUB_FILES=	pkg-message

USES=		desktop-file-utils ncurses openal:al,alut gmake pkgconfig

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900033
USE_BINUTILS=	yes
LDFLAGS+=	-B${LOCALBASE}/bin
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|PREFIX =|PREFIX?=|;s|$$(shell git rev-list HEAD.*$$|${GH_COMMIT}|'	\
		${WRKSRC}/cfg/global_vars.mk

post-install:
	${RM} ${STAGEDIR}${MANPREFIX}/man/man1/toxic.1-e ${STAGEDIR}${MANPREFIX}/man/man5/toxic.conf.5-e
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/toxic

.include <bsd.port.post.mk>
