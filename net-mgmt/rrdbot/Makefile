# Created by: Jeremy Chadwick <koitsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rrdbot
PORTVERSION=	0.9.7
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://thewalter.net/stef/software/rrdbot/

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

.if defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--disable-ipv6
.endif

NO_STAGE=	yes
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
