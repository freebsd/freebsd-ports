# New ports collection makefile for:	cracklib
# Date created:				22 April 2000
# Whom:					ajk@iu.edu
#
# $FreeBSD$
#

PORTNAME=	cracklib
PORTVERSION=	2.7
CATEGORIES=	security
MASTER_SITES=	http://www.users.dircon.co.uk/~crypto/download/
DISTNAME=	${PORTNAME},${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ajk@iu.edu

pre-install:
	${INSTALL_DATA} ${WRKSRC}/cracklib/libcrack.a ${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/util/mkdict ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/util/packer ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/util/testlib ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/util/testnum ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/util/teststr ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/util/unpacker ${PREFIX}/bin
	${MKDIR} ${PREFIX}/libdata/cracklib

.include <bsd.port.mk>
