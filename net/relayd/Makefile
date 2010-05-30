# New ports collection makefile for: relayd
# Date created:         5 Jun 2007
# Whom:                 Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	relayd
PORTVERSION=	4.6.20090813
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mm

MAINTAINER=	mm@FreeBSD.org
COMMENT=	OpenBSD relay daemon

USE_BZIP2=	yes
MANCOMPRESSED=	yes

WRKSRC=		${WRKDIR}/usr.sbin
MAN5=		relayd.conf.5
MAN8=		relayctl.8 relayd.8
USE_RC_SUBR=	relayd

CFLAGS+=	-I${PREFIX}/include

MAKE_ARGS+=	BINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man/man

RUSER=		_relayd
RGROUP=		_relayd
PKGINSTALL=	${WRKDIR}/pkginstall
SUB_FILES+=	pkg-install

SUB_LIST+=	RUSER=${RUSER} \
		RGROUP=${RGROUP}

OPTIONS=	LIBEVENT_STATIC "Build with static libevent" Off

.include <bsd.port.pre.mk>

.if defined(WITH_LIBEVENT_STATIC)
BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent
MAKE_ARGS+=	LIBEVENT=${LOCALBASE}/lib/libevent.a
.else
LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent
MAKE_ARGS+=	LIBEVENT=-levent
.endif

.if (${OSVERSION} < 702104)
IGNORE=		requires newer FreeBSD (osreldate 702104 and higher)
.endif

post-extract:
	@${CP} ${FILESDIR}/Makefile.all ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/Makefile.relayctl ${WRKSRC}/relayctl/Makefile
	@${CP} ${FILESDIR}/Makefile.relayd ${WRKSRC}/relayd/Makefile
	@${CP} ${FILESDIR}/arc4random.c ${WRKSRC}/relayd

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/relayd/relay.c \
		${WRKSRC}/relayd/relayd.h \
		${WRKSRC}/relayd/relayd.conf.5 \
		${WRKSRC}/relayd/relayd.8

pre-su-install:
	@${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install:
	@${INSTALL_DATA} ${FILESDIR}/relayd.conf.sample ${PREFIX}/etc

.include <bsd.port.post.mk>
