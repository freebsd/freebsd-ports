# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ptunnel
PORTVERSION=	0.72
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.cs.uit.no/~daniels/PingTunnel/
DISTNAME=	PingTunnel-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Tunneling TCP connections over ICMP echo request and reply

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
WRKSRC=		${WRKDIR}/PingTunnel
PLIST_FILES=	bin/ptunnel man/man8/ptunnel.8.gz

post-patch:
	@${REINPLACE_CMD} -e '/^CC/d' -e "/^CFLAGS/d" ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's/stdint.h/inttypes.h/' ${WRKSRC}/ptunnel.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ptunnel ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ptunnel.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
