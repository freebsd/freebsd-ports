# New ports collection makefile for:	rmilter
# Date created:				2007-11-02
# Whom:					vsevolod
#
# $FreeBSD$
#

PORTNAME=		rmilter
PORTVERSION=		1.5.24
CATEGORIES=		mail
MASTER_SITES=		http://cebka.pp.ru/distfiles/

MAINTAINER=		vsevolod@FreeBSD.org
COMMENT=		Milter plugin for rambler mail

PLIST_FILES=	sbin/rmilter etc/rc.d/rmilter.sh etc/rmilter.conf.sample

HAS_CONFIGURE=	yes

.ifdef WITH_DEBUG
CONFIGURE_ARGS+=	--enable-debug
.endif

.ifdef WITH_SENDMAIL
CONFIGURE_ARGS+=	--enable-sendmail
.endif

LIB_DEPENDS+=		pcre.0:${PORTSDIR}/devel/pcre

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 502102
IGNORE=				using libspf2 requires a thread safe resolver
.else
LIB_DEPENDS+=		spf2.3:${PORTSDIR}/mail/libspf2
.endif

CFLAGS+=	${PTHREAD_CFLAGS}
LIBS+=		${PTHREAD_LIBS}

MAN8=		rmilter.8

.include "${PORTSDIR}/mail/sendmail/bsd.milter.mk"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rmilter.sh ${PREFIX}/etc/rc.d/
	${INSTALL_PROGRAM} ${WRKSRC}/rmilter ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/rmilter.conf.sample ${PREFIX}/etc/
	${INSTALL_MAN} ${WRKSRC}/rmilter.8 ${MAN8PREFIX}/man/man8/

.include <bsd.port.post.mk>
