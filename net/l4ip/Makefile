# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	l4ip
PORTVERSION=	1.0.294
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.lundman.net/ftp/l4ip/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/([0-9]*)\.([0-9]*)\.([0-9]*)/v\1.\2.b\3/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	L4 health check daemon for IPFILTER

USES=		gmake ssl tar:tgz
WRKSRC=		${WRKDIR}/${PORTNAME}/src

post-patch:
	${REINPLACE_CMD} -e 's,service_type_t,script_type_t,g' ${WRKSRC}/service.c
	${REINPLACE_CMD} -e 's,/usr/sbin,/sbin,g' ${WRKSRC}/l4ip.conf
	${REINPLACE_CMD} -e '/^CC/d' ${WRKSRC}/${MAKEFILE} ${WRKSRC}/../lion/${MAKEFILE}
	${REINPLACE_CMD} -e "s|/usr/local/ssl|${OPENSSLBASE}|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/l4ip ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/l4ip.conf ${STAGEDIR}${PREFIX}/etc/l4ip.conf.sample
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL} ${WRKSRC}/../samples/*.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
