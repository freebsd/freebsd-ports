# New ports collection makefile for:	rtg
# Date created:				6 January 2004
# Whom:					Brad Davis <so14k@so14k.com>
#
# $FreeBSD$
#

PORTNAME=	rtg
PORTVERSION=	0.7.4
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	A flexible, high-performance SNMP statistics monitoring system

LIB_DEPENDS=	netsnmp:${PORTSDIR}/net-mgmt/net-snmp

MAN1=	rtgplot.1 rtgpoll.1

USE_RC_SUBR=	rtgpoll
USE_MYSQL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/${PORTNAME} \
			--with-mysql=${LOCALBASE} \
			--with-snmp=${LOCALBASE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800040
CFLAGS+=	-fstack-protector
LDFLAGS+=	-fstack-protector
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's,-pthread,${PTHREAD_LIBS},g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
