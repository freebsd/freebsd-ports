# New ports collection makefile for:	pktsuckers
# Date created:		31 May 1999
# Whom:			Warren Toomey <wkt@cs.adfa.edu.au>
#
# $FreeBSD$
#

PORTNAME=	pktsuckers
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	ftp://minnie.cs.adfa.edu.au/pub/NetSecurity/
DISTNAME=	${PORTNAME}1_2

MAINTAINER=	wkt@tuhs.org
COMMENT=	Log contents of unwanted UDP packets and TCP connections

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpsuck ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/udpsuck ${PREFIX}/libexec
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
