# Ports collection makefile for:  ADMsnmp
# Date created:                   16 Apr 2003
# Whom:                           onatan@gmail.com
#
# $FreeBSD$
#

PORTNAME=	ADMsnmp
PORTVERSION=	0.1
CATEGORIES=	security
MASTER_SITES=	ftp://adm.freelsd.net/pub/ADM/ \
		http://adm.freelsd.net/ADM/ \
		${MASTER_SITE_PACKETSTORM:=groups/ADM/}
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	onatan@gmail.com
COMMENT=	SNMP audit scanner

WRKSRC=		${WRKDIR}/ADMsnmp

do-build:
	${CC} ${CFLAGS} -DPORTSHAREDIR="${PREFIX}/share/ADMsnmp" \
		-o ${WRKSRC}/ADMsnmp ${WRKSRC}/snmp.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ADMsnmp ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/ADMsnmp
	${MKDIR} ${PREFIX}/share/doc/ADMsnmp
	${INSTALL_DATA} ${WRKSRC}/snmp.passwd ${PREFIX}/share/ADMsnmp
	${INSTALL_DATA} ${WRKSRC}/ADMsnmp.README ${PREFIX}/share/doc/ADMsnmp

.include <bsd.port.mk>
