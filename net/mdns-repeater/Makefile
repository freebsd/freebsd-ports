# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mdns-repeater
PORTVERSION=	1.10
CATEGORIES=	net dns
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Multicast DNS repeater to re-broadcast mDNS packets across interfaces

LICENSE=	GPLv2

CFLAGS+=	-DHGVERSION="\"${PORTVERSION}\""

PLIST_FILES=	bin/mdns-repeater

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
