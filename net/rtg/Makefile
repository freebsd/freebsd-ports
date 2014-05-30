# Created by: Brad Davis <so14k@so14k.com>
# $FreeBSD$

PORTNAME=	rtg
PORTVERSION=	0.7.4
PORTREVISION=	10
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	A flexible, high-performance SNMP statistics monitoring system

LICENSE=	GPLv2

LIB_DEPENDS=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp

USE_RC_SUBR=	rtgpoll
USE_MYSQL=	yes
WANT_PERL=	yes
USES=		shebangfix
SHEBANG_FILES=	etc/95.pl etc/report.pl
SUB_FILES=	pkg-message
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/${PORTNAME} \
			--with-mysql=${LOCALBASE} \
			--with-snmp=${LOCALBASE}

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

.include <bsd.port.post.mk>
