# ex:ts=8
# Ports collection makefile for:  ttlscan
# Date created:                Wed Apr 2, 2003
# Whom:                        Michael L. Hostbaek (mich@freebsdcluster.org)
#
# $FreeBSD$
#

PORTNAME=	ttlscan
PORTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.wormulon.net/files/ttlscan/

MAINTAINER=	mich@FreeBSD.org
COMMENT=	A TCP based scanner, showing ttl responses

BUILD_DEPENDS=	${LOCALBASE}/include/dnet.h:${PORTSDIR}/net/libdnet \
		${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

LDFLAGS+=	-lpcap -ldnet

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib -D_XOPEN_SOURCE \
	`${LIBNET_CONFIG} --defines --cflags` ${PORTNAME}.c -o ${PORTNAME} `${LIBNET_CONFIG} --libs` ${LDFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
