# New ports collection makefile for:	ser
# Date created:				6 November 2002
# Whom:					andrei
#
# $FreeBSD$
#

PORTNAME=	ser
PORTVERSION=	0.8.11
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.berlios.de/pub/ser/${PORTVERSION}/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	A very fast and configurable SIP proxy

BUILD_DEPENDS=	${LOCALBASE}/lib/mysql/libmysqlclient.a:${PORTSDIR}/databases/mysql40-client
LIB_DEPENDS=	radiusclient.0:${PORTSDIR}/net/radiusclient
RUN_DEPENDS=	${LOCALBASE}/lib/mysql/libmysqlclient.a:${PORTSDIR}/databases/mysql40-client

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE= yes
CFLAGS+=	-I${LOCALBASE}/include

MAN8=		ser.8
MAN5=		ser.cfg.5
MANCOMPRESSED=	no

post-install:
	${SED} 's|%%LOCALBASE%%|${LOCALBASE}|g ; s|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/modules/acc/etc/radiusclient.conf > \
			${WRKDIR}/radiusclient.conf
	${INSTALL_DATA} ${WRKSRC}/modules/acc/etc/sip_dictionary \
		${PREFIX}/etc/ser
	${INSTALL_DATA} ${WRKSRC}/modules/acc/etc/servers \
		${PREFIX}/etc/ser/servers.sample
	${INSTALL_DATA} ${WRKDIR}/radiusclient.conf \
		${PREFIX}/etc/ser/radiusclient.conf.default
	if [ ! -e ${PREFIX}/etc/ser/radiusclient.conf ]; then \
		${INSTALL_DATA} ${WRKDIR}/radiusclient.conf \
			${PREFIX}/etc/ser/radiusclient.conf; \
	fi

.include <bsd.port.mk>
