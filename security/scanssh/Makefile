# Created by: kris@FreeBSD.org

PORTNAME=	scanssh
PORTVERSION=	2.1
PORTREVISION=	12
CATEGORIES=	security net
MASTER_SITES=	http://www.monkey.org/~provos/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scans networks for open proxies, SSH, web, and SMTP servers

DEPRECATED=	Abandonware, last release in 2005. Please consider using security/nmap or security/rustscan
EXPIRATION_DATE=2022-03-31

LIB_DEPENDS=	libdnet.so:net/libdnet \
		libevent.so:devel/libevent

GNU_CONFIGURE=	YES
PLIST_FILES=	bin/scanssh man/man1/scanssh.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scanssh ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/scanssh.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
