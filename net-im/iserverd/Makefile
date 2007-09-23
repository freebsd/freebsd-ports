# New ports collection makefile for:	iserverd
# Date created:				Sun Jun 10 17:51:00 GMT 2007
# Whom:					Denis Rakhmangulov <danfocus@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	iserverd
PORTVERSION=	2.5.5
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	http://iserverd.khstu.ru/download/

MAINTAINER=	danfocus@gmail.com
COMMENT=	Groupware ICQ server clone

CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
USE_PGSQL=	YES
GNU_CONFIGURE=	YES
USE_RC_SUBR=	iserverd

OPTIONS=	KQUEUE "Use kqueue(2) instead of poll(2)" on \
		DEBUG "Enable debugging symbols" off

CONFIGURE_ARGS=	--with-pgsql=${LOCALBASE} \
		--with-bindir=${PREFIX}/bin \
		--with-etcdir=${PREFIX}/etc/iserverd \
		--with-vardir=/var/run/iserverd \
		--with-sbindir=${PREFIX}/bin \
		--with-mandir=${PREFIX}/man \
		--with-logdir=/var/log/iserverd

MAN1=		db_convert.1
MAN5=		iserv.conf.5 v3_proto.conf.5 v5_proto.conf.5
MAN8=		iserverd.8

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif
.if defined(WITH_KQUEUE)
CONFIGURE_ARGS+=--with-kqueue
.endif

post-install:
	@${SETENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CHMOD} 644 ${PREFIX}/etc/iserverd/iserv.conf.default
	@${CHMOD} 644 ${PREFIX}/etc/iserverd/aim_proto.conf
	@${CHMOD} 644 ${PREFIX}/etc/iserverd/actions.conf.default
	@${CHMOD} 644 ${PREFIX}/etc/iserverd/v3_proto.conf.default
	@${CHMOD} 644 ${PREFIX}/etc/iserverd/v5_proto.conf.default
	@${CHMOD} 644 ${PREFIX}/etc/iserverd/v7_proto.conf.default
	@${CHMOD} 644 ${PREFIX}/etc/iserverd/texts/*
	@${CHMOD} 644 ${PREFIX}/etc/iserverd/translate/*
	@${CHOWN} -R iserv /var/log/iserverd
	@${CHOWN} -R iserv /var/run/iserverd

.include <bsd.port.post.mk>
