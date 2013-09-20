# Created by: Brad Davis <so14k@so14k.com>
# $FreeBSD$

PORTNAME=	rtg
PORTVERSION=	0.7.4
PORTREVISION=	9
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

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ( ${OSVERSION} >= 800040 )
CFLAGS+=	-fstack-protector
LDFLAGS+=	-fstack-protector
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's,-pthread,${PTHREAD_LIBS},g' ${WRKSRC}/configure

post-patch:
	@${MV} ${WRKSRC}/etc/rtg.conf ${WRKSRC}/etc/rtg.conf.sample
	@${MV} ${WRKSRC}/etc/routers ${WRKSRC}/etc/routers.sample

post-install:
	@${ECHO} "To enable the web interface, copy ${PREFIX}/bin/rtgplot to your site cgi-bin as rtgplot.cgi"

.include <bsd.port.post.mk>
