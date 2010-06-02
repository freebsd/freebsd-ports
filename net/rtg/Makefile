# New ports collection makefile for:	rtg
# Date created:				6 January 2004
# Whom:					Brad Davis <so14k@so14k.com>
#
# $FreeBSD$
#

PORTNAME=	rtg
PORTVERSION=	0.7.4
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A flexible, high-performance SNMP statistics monitoring system

LIB_DEPENDS=	netsnmp.20:${PORTSDIR}/net-mgmt/net-snmp

MAN1=	rtgplot.1 rtgpoll.1

USE_MYSQL=      yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/${PORTNAME} \
			--with-mysql=${LOCALBASE} \
			--with-snmp=${LOCALBASE}

pre-configure:
	@${REINPLACE_CMD} -e 's,-pthread,${PTHREAD_LIBS},g' ${WRKSRC}/configure

.include <bsd.port.mk>
