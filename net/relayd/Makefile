# $FreeBSD$

PORTNAME=	relayd
PORTVERSION=	5.4.20131122
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	GH

MAINTAINER=	mm@FreeBSD.org
COMMENT=	OpenBSD relay daemon

LICENSE=	ISCL

GH_ACCOUNT=	mmatuska
GH_COMMIT=	a4f6140

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}/src/usr.sbin
USES=		uidfix
USE_GITHUB=	yes
USE_RC_SUBR=	relayd

CFLAGS+=	-I${PREFIX}/include -Wall

MAKE_ARGS+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man

USERS=		_relayd
GROUPS=		_relayd

OPTIONS_DEFINE=	LIBEVENT_STATIC
LIBEVENT_STATIC_DESC=	Build with static libevent

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MLIBEVENT_STATIC}
BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent
MAKE_ARGS+=	LIBEVENT=${LOCALBASE}/lib/libevent.a
.else
LIB_DEPENDS=	libevent-1.4.so:${PORTSDIR}/devel/libevent
MAKE_ARGS+=	LIBEVENT=-levent
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/relayd/relay.c \
		${WRKSRC}/relayd/relayd.h \
		${WRKSRC}/relayd/relayd.conf.5 \
		${WRKSRC}/relayd/relayd.8

post-install:
	@${INSTALL_DATA} ${WRKSRC}/../etc/relayd.conf \
		${STAGEDIR}${PREFIX}/etc/relayd.conf.sample

.include <bsd.port.post.mk>
