# Created by: kris@FreeBSD.org
# $FreeBSD$

PORTNAME=	scanssh
PORTVERSION=	2.1
PORTREVISION=	9
CATEGORIES=	security net
MASTER_SITES=	http://www.monkey.org/~provos/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scans networks for open proxies, SSH, web, and SMTP servers

LIB_DEPENDS=	libdnet.so:net/libdnet \
		libevent.so:devel/libevent2

GNU_CONFIGURE=	YES
PLIST_FILES=	bin/scanssh man/man1/scanssh.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scanssh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/scanssh.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
