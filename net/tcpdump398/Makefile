# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	tcpdump398
PORTVERSION=	1.0
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.mavetju.org/download/adopted/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ubiquitous network traffic analysis tool - FreeBSD 7 version for FreeBSD 8

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/contrib/LICENSE

USES=		ssl tar:bzip2

PLIST_FILES=	bin/tcpdump398 man/man1/tcpdump398.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpdump ${STAGEDIR}${PREFIX}/bin/tcpdump398
	${INSTALL_MAN} ${WRKSRC}/tcpdump.1.gz ${STAGEDIR}${MAN1PREFIX}/man/man1/tcpdump398.1.gz

.include <bsd.port.mk>
