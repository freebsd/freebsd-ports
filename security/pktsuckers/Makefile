# New ports collection makefile for:	pktsuckers
# Version required:	1.2
# Date created:		31 May 1999
# Whom:			Warren Toomey <wkt@cs.adfa.edu.au>
#
# $FreeBSD$
#

DISTNAME=	pktsuckers1_2
PKGNAME=	pktsuckers-1.2
CATEGORIES=	security net
MASTER_SITES=	ftp://minnie.cs.adfa.edu.au/pub/NetSecurity/

MAINTAINER=	wkt@cs.adfa.edu.au

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcpsuck ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/udpsuck ${PREFIX}/libexec
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
