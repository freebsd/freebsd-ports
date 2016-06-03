# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	radiusniff
PORTVERSION=	0.2
CATEGORIES=	security
MASTER_SITES=	http://adm.freelsd.net/ADM/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sniffer for RADIUS traffic

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

WRKSRC=		${WRKDIR}/radiusniff-0.2

CFLAGS+=	-DOPENBSD -DCLIENTS_FILENAME=\"${DATADIR}/clients\" \
		-DDICTIONARY_FILENAME=\"${DATADIR}/dictionary\"

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/radiusniff ${WRKSRC}/radiusniff.c \
		${WRKSRC}/md5.c -lpcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/radiusniff ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/dictionary ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/clients ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
