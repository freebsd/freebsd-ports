# New ports collection makefile for:   scamper
# Date created:        17 July 2006
# Whom:                Janos Mohacsi <janos.mohacsi@bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	scamper
PORTVERSION=	20060331
CATEGORIES=	net-mgmt ipv6
MASTER_SITES=	http://www.wand.net.nz/scamper/
DISTNAME=	${PORTNAME}-cvs-${PORTVERSION}

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Dual-stack traceroute software

MAKE_ENV+=	WITH_DEBUG=yes	# recommended by the the software developer

PLIST_FILES=	bin/scamper

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scamper ${PREFIX}/bin

.include <bsd.port.mk>
