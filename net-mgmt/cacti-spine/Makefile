# New ports collection makefile for:   cactid
# Date created:        Feb 26 2005
# Whom:                clement@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cactid
PORTVERSION=	0.8.6.d
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.cacti.net/downloads/cactid/
DISTNAME=	cacti-${PORTNAME}-0.8.6d

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multithreaded poller for Cacti written in C

LIB_DEPENDS=	netsnmp.7:${PORTSDIR}/net-mgmt/net-snmp

GNU_CONFIGURE=	YES
USE_MYSQL=	YES
USE_OPENSSL=	YES
USE_REINPLACE=	YES

post-patch:
	@${REINPLACE_CMD} 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/cactid.h

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/cactid.conf ${EXAMPLESDIR}
	@[ -e ${PREFIX}/etc/cactid.conf ] || \
		${INSTALL_DATA} ${EXAMPLESDIR}/cactid.conf ${PREFIX}/etc/

.include <bsd.port.mk>
