# Created by: Dmitry Yu Okunev dyokunev@ut.mephi.ru
# $FreeBSD$

PORTNAME=	clsync
DISTVERSION=	0.4~rc2
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	dyokunev@ut.mephi.ru
COMMENT=	Live file sync daemon based on inotify, written in GNU C

LICENSE=	GPLv3

LIB_DEPENDS=	libinotify.so:devel/libinotify

GNU_CONFIGURE=	yes
USES=		autoreconf compiler:features gmake gnome libtool pkgconfig
USE_GNOME=	glib20

USE_RC_SUBR=	clsync

SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_ACCOUNT=	xaionaro
GH_TAGNAME=	85e5475

OPTIONS_DEFINE=	PARANOID VERYPARANOID SOCKET DEBUG LIBCLSYNC

PARANOID_DESC=	Enable paranoid secure routines
VERYPARANOID_DESC=Enable extra paranoid secure routines and disable some extra features
SOCKET_DESC=	Enable control socket support
LIBCLSYNC_DESC=	Build libclsync.so for control socket clients

OPTIONS_DEFAULT=PARANOID

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MVERYPARANOID}
CONFIGURE_ARGS+=	--enable-paranoid=2
.else
.if ${PORT_OPTIONS:MPARANOID}
CONFIGURE_ARGS+=	--enable-paranoid=1
.else
CONFIGURE_ARGS+=	--enable-paranoid=0
.endif
.endif

.if ${PORT_OPTIONS:MSOCKET}
CONFIGURE_ARGS+=	--enable-socket
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MLIBCLSYNC}
CONFIGURE_ARGS+=	--enable-libclsync
.endif

.if ${COMPILER_TYPE} == clang
post-patch:
	@${REINPLACE_CMD} -e 's|-fstack-check||' ${WRKSRC}/configure.ac
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/clsync ${STAGEDIR}${PREFIX}/sbin/clsync
	${INSTALL_DATA} ${WRKSRC}/man/man1/clsync.1 ${STAGEDIR}${PREFIX}/man/man1/clsync.1
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/freebsd/usr/local/etc/clsync/${PORTNAME}.conf ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample

.include <bsd.port.post.mk>
