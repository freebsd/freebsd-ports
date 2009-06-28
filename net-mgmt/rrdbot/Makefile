# New ports collection makefile for:	net-mgmt/rrdbot
# Date created:				18 September 2008
# Whom:					Jeremy Chadwick <koitsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rrdbot
PORTVERSION=	0.9.4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://memberwebs.com/stef/software/rrdbot/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Threaded SNMP polling daemon which stores data in RRDs

LIB_DEPENDS=	rrd:${PORTSDIR}/databases/rrdtool

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${LOCALBASE}/lib --includedir=${LOCALBASE}/include \
			--datarootdir=${PREFIX}/share/rrdbot

SUB_FILES=	pkg-message
USE_RC_SUBR=	rrdbot

MAN1=		rrdbot-get.1
MAN5=		rrdbot.conf.5
MAN8=		rrdbot-create.8 rrdbotd.8

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
