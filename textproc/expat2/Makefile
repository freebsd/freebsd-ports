# New ports collection makefile for:	expat
# Date created:		Thu Aug 26 14:38:07 CEST 1999
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	expat
PORTVERSION= 	1.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/xml/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/
DISTNAME=	${PORTNAME}

MAINTAINER=	dirk@FreeBSD.org

USE_ZIP=	yes

SHLIB_MAJOR=	1

PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmlwf/xmlwf ${PREFIX}/bin
	${MKDIR} ${PREFIX}/include/xml
	${INSTALL_DATA} ${WRKSRC}/xmlparse/xmlparse.h ${PREFIX}/include/xml
	${INSTALL_DATA} ${WRKSRC}/xmltok/xmltok.h ${PREFIX}/include/xml
	${INSTALL_DATA} ${WRKSRC}/libexpat.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libexpat.so ${PREFIX}/lib/libexpat.so.${SHLIB_MAJOR}
	${LN} -s libexpat.so.${SHLIB_MAJOR} ${PREFIX}/lib/libexpat.so

.include <bsd.port.mk>
