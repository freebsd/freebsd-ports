# New ports collection makefile for:	l4ip
# Date created:				17 February 2006
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	l4ip
PORTVERSION=	1.0.294
CATEGORIES=	net
MASTER_SITES=	http://www.lundman.net/ftp/l4ip/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/([0-9]*)\.([0-9]*)\.([0-9]*)/v\1.\2.b\3/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	L4 health check daemon for IPFILTER

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}/src

post-patch:
	${REINPLACE_CMD} -e 's,service_type_t,script_type_t,g' ${WRKSRC}/service.c
	${REINPLACE_CMD} -e 's,/usr/sbin,/sbin,g' ${WRKSRC}/l4ip.conf
	${REINPLACE_CMD} -e '/^CC/d' ${WRKSRC}/${MAKEFILE} ${WRKSRC}/../lion/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/l4ip ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/l4ip.conf ${PREFIX}/etc/l4ip.conf.sample
.if !exists(${PREFIX}/etc/l4ip.conf)
	${CP} ${PREFIX}/etc/l4ip.conf.sample ${PREFIX}/etc/l4ip.conf
.endif
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL} ${WRKSRC}/../samples/*.conf ${EXAMPLESDIR}

.include <bsd.port.mk>
