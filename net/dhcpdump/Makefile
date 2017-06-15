# Created by: Edwin Groothuis (edwin@mavetju.org)
# $FreeBSD$

PORTNAME=	dhcpdump
PORTVERSION=	1.8
CATEGORIES=	net
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Decode and diagnose sniffed DHCP packets

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5
USE_PERL5=	build

PLIST_FILES=	bin/dhcpdump man/man8/dhcpdump.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhcpdump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dhcpdump.8 ${STAGEDIR}${PREFIX}/man/man8

.include <bsd.port.mk>
