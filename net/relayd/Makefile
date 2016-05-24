# $FreeBSD$

PORTNAME=	relayd
PORTVERSION=	5.5.20140810
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	mm@FreeBSD.org
COMMENT=	OpenBSD relay daemon

LICENSE=	ISCL

GH_ACCOUNT=	mmatuska

USES=		uidfix
USE_GITHUB=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	relayd
WRKSRC_SUBDIR=	src/usr.sbin

CFLAGS+=	-Wall

MAKE_ARGS+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man

USERS=		_relayd
GROUPS=		_relayd

.include <bsd.port.pre.mk>

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
