PORTNAME=	mtrace
PORTVERSION=	5.2
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Multicast traceroute program for IPv4
WWW=		https://sourceforge.net/projects/mtrace/

ALL_TARGET=	mtrace
PLIST_FILES=	sbin/mtrace share/man/man8/mtrace.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtrace ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/mtrace.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
