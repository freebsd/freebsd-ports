# New ports collection makefile for:   dhcpdump
# Date created:        1 March 2001
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	dhcpdump
PORTVERSION=	1.8
CATEGORIES=	net
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Decode and diagnose sniffed DHCP packets

MAN8=		dhcpdump.8
PLIST_FILES=	bin/dhcpdump

USE_PERL5_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhcpdump ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dhcpdump.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
