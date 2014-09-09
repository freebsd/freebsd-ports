# Created by: Michael L. Hostbaek (mich@freebsdcluster.org)
# $FreeBSD$

PORTNAME=	ttlscan
PORTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.wormulon.net/files/ttlscan/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	TCP based scanner, showing ttl responses

DEPRECATED=	Depends on expired net/libnet10
EXPIRATION_DATE=	2014-09-30

BUILD_DEPENDS=	${LOCALBASE}/include/dnet.h:${PORTSDIR}/net/libdnet \
		${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

LDFLAGS+=	-lpcap -ldnet

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib -D_XOPEN_SOURCE \
	`${LIBNET_CONFIG} --defines --cflags` ${PORTNAME}.c -o ${PORTNAME} `${LIBNET_CONFIG} --libs` ${LDFLAGS})

do-install:
	${INSTALL_PROGRAM} -s ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
