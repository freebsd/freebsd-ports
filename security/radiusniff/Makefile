# New ports collection makefile for:	radiusniff
# Date created:		21 April 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	radiusniff
PORTVERSION=	0.2
CATEGORIES=	security
MASTER_SITES=	http://adm.freelsd.net/ADM/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sniffer for RADIUS traffic

WRKSRC=		${WRKDIR}/radiusniff-0.2

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -DOPENBSD -DCLIENTS_FILENAME=\"${PREFIX}/share/radiusniff/clients\" -DDICTIONARY_FILENAME=\"${PREFIX}/share/radiusniff/dictionary\" -o radiusniff radiusniff.c md5.c -lpcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/radiusniff ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/radiusniff/
	${INSTALL_DATA} ${WRKSRC}/dictionary ${PREFIX}/share/radiusniff/
	${INSTALL_DATA} ${WRKSRC}/clients ${PREFIX}/share/radiusniff/

.include <bsd.port.mk>
