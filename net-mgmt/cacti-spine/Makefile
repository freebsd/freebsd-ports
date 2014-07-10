# Created by: clement@FreeBSD.org
# $FreeBSD$

PORTNAME=	spine
PORTVERSION=	0.8.8b
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.cacti.net/downloads/${PORTNAME}/
DISTNAME=	cacti-${PORTNAME}-${PORTVERSION}

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Multithreaded poller for Cacti written in C

LICENSE=	GPLv2

LIB_DEPENDS=	libnetsnmp.so:${PORTSDIR}/net-mgmt/net-snmp

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-mysql=${LOCALBASE} --with-snmp=${LOCALBASE}
CPPFLAGS+=	`net-snmp-config --cflags`
LDFLAGS+=	`net-snmp-config --libs`
USE_MYSQL=	YES
USE_OPENSSL=	YES

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800040
LDFLAGS+=	-fstack-protector
.endif

post-patch:
	@${REINPLACE_CMD} 's,#define\ *DEFAULT_CONF_FILE .*,#define DEFAULT_CONF_FILE "${PREFIX}/etc/spine.conf",' ${WRKSRC}/spine.h

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/spine ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/spine.conf.dist ${STAGEDIR}${PREFIX}/etc/spine.conf.sample

.include <bsd.port.post.mk>
