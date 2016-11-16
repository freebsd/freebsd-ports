# Created by: Edwin Groothuis (edwin@mavetju.org)
# $FreeBSD$

PORTNAME=	dhcpdump
PORTVERSION=	1.8
CATEGORIES=	net
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Decode and diagnose sniffed DHCP packets

PLIST_FILES=	bin/dhcpdump man/man8/dhcpdump.8.gz

USES=		perl5
USE_PERL5=	build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhcpdump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dhcpdump.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
