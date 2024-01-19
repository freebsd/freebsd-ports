PORTNAME=	dhcpdump
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Decode and diagnose sniffed DHCP packets
WWW=		https://www.mavetju.org/unix/general.php

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5
USE_PERL5=	build

PLIST_FILES=	bin/dhcpdump share/man/man8/dhcpdump.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhcpdump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dhcpdump.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
