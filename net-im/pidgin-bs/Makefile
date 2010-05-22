# New ports collection makefile for:	pidgin-bs
# Date created:				15 Mar 2010
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pidgin-bs
PORTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	SF/${PORTNAME}/bot-sentry/${PORTVERSION}
DISTNAME=	bot-sentry-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Pidgin plugin to prevent instant message spam

LIB_DEPENDS=	purple.7:${PORTSDIR}/net-im/libpurple
RUN_DEPENDS=	pidgin:${PORTSDIR}/net-im/pidgin

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_LDCONFIG=	${PREFIX}/lib/pidgin

PLIST_FILES=	lib/purple-2/bot-sentry.so lib/purple-2/bot-sentry.la

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		configure fails on 6.x
.endif

.include <bsd.port.post.mk>
