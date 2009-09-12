# ex:ts=8
# Ports collection makefile for:	libbgpdump
# Date created:			Jan 8, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libbgpdump
PORTVERSION=	1.4.99.9
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	http://www.ris.ripe.net/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analyzing dump files produced by Zebra/Quagga or MRT

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bgpdump ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/libbgpdump.* ${PREFIX}/lib
	@${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include

.include <bsd.port.mk>
