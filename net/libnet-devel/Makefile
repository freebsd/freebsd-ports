# Ports collection makefile for:  libnet11
# Date created:			Jan 7, 2003
# Whom:				smace@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	libnet-devel
PORTVERSION=	1.1.0
CATEGORIES=	net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/
DISTNAME=	${PORTNAME:S/-devel$//}-${PORTVERSION}

MAINTAINER=	smace@freebsd.org

WRKSRC=		${WRKDIR}/Libnet-latest

USE_AUTOMAKE=   yes
USE_AUTOCONF=	yes

MAN3=		libnet.3

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/libnet-config ${PREFIX}/bin

.include <bsd.port.mk>
