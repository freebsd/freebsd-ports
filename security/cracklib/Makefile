# New ports collection makefile for:	cracklib
# Date created:				22 April 2000
# Whom:					ajk@iu.edu
#
# $FreeBSD$
#

PORTNAME=	cracklib
PORTVERSION=	2.7
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.crypticide.com/users/alecm/security/
DISTNAME=	${PORTNAME},${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Password-checking library

MAN3=		cracklib.3
MLINKS=		cracklib.3 FascistCheck.3
INSTALLS_SHLIB=	yes

pre-su-install:
	${INSTALL_DATA} ${WRKSRC}/cracklib/libcrack.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/cracklib/libcrack.so.1 ${PREFIX}/lib
	${LN} -sf libcrack.so.1 ${PREFIX}/lib/libcrack.so
	${INSTALL_DATA} ${WRKSRC}/cracklib/packer.h ${PREFIX}/include
	${INSTALL_SCRIPT} ${WRKSRC}/util/mkdict ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/util/packer ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/util/testlib ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/util/testnum ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/util/teststr ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/util/unpacker ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/cracklib.3 ${MAN3PREFIX}/man/man3
	${MKDIR} ${PREFIX}/libdata/cracklib

.include <bsd.port.mk>
