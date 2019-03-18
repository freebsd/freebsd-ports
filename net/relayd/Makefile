# $FreeBSD$

PORTNAME=	relayd
PORTVERSION=	5.5.20140810
PORTREVISION=	3
CATEGORIES=	net

MAINTAINER=	ports@FreeBSD.or
COMMENT=	OpenBSD relay daemon

LICENSE=	ISCL

GH_ACCOUNT=	mmatuska

USES=		uidfix ssl
USE_GITHUB=	yes
USE_RC_SUBR=	relayd
WRKSRC_SUBDIR=	src/usr.sbin

CFLAGS+=	-Wall

MAKE_ARGS+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man

USERS=		_relayd
GROUPS=		_relayd

BROKEN_FreeBSD_12=	does not build, OpenSSL 1.1 unsupported	

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1300000
BROKEN=	does not build, OpenSSL 1.1 unsupported	
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
