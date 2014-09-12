# Created by: mich@freebsdcluster.org
# $FreeBSD$

PORTNAME=	vida
PORTVERSION=	0.7.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://vidatapipe.sourceforge.net/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Vida is a multi-datapipe handler

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10
RUN_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

LDFLAGS+=	${PTHREAD_LIBS} -lncurses -lpcap `${LIBNET_CONFIG} --libs`

WRKSRC=		${WRKDIR}/${PORTNAME}

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

PLIST_FILES=	bin/vida \
		man/man1/vida.1.gz

DEPRECATED=	Depends on expired net/libnet10
EXPIRATION_DATE=2014-09-30

do-build:
	(cd ${WRKSRC} && \
		${CC} `${LIBNET_CONFIG} --defines --cflags` ${CFLAGS} \
		vida.c funz.c dnshijacking.c ${LDFLAGS} -o ${PORTNAME})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/vida.1.gz ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
