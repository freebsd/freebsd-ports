# New ports collection makefile for:	libcgic
# Date created:				27 July 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	cgic
PORTVERSION= 	1.06
CATEGORIES=	www
MASTER_SITES=	http://www.boutell.com/cgic/
DISTNAME=	${PORTNAME}106
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org

INSTALL_SHLIBS=	yes

ALL_TARGET=	libcgic.so.1

do-install:
	@ ${INSTALL_DATA} ${WRKSRC}/cgic.h ${PREFIX}/include
	@ ${INSTALL_DATA} ${WRKSRC}/libcgic.so.1 ${PREFIX}/lib
	@ ${LN} -s ${PREFIX}/lib/libcgic.so.1 ${PREFIX}/lib/libcgic.so
	@ ${MKDIR} ${PREFIX}/share/examples/cgic
	@ ${INSTALL_DATA} ${WRKSRC}/capture.c ${PREFIX}/share/examples/cgic
	@ ${INSTALL_DATA} ${WRKSRC}/cgictest.c ${PREFIX}/share/examples/cgic

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/cgic
.for file in cgic.html cgic.txt license.txt readme.txt support.txt testform.html
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/cgic
.endfor
.endif

.include <bsd.port.mk>
