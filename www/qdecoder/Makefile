# New ports collection makefile for:    qDecoder library
# Date created:         Sep 10 1999
# Whom:                 CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qDecoder
PORTVERSION=	6.0.3
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.qDecoder.org/pub/qDecoder/\
		ftp://ftp2.qDecoder.org/pub/qDecoder/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	cjh@FreeBSD.org

GNU_CONFIGURE=	YES

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${MKDIR} ${PREFIX}/share/doc/qDecoder
.for doc in AUTHORS DISCLAIMER README README.pdf qDecoder.jpg
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/qDecoder
.endfor
	${MKDIR} ${PREFIX}/share/examples/qDecoder
	-${RM} ${WRKSRC}/examples/*.o ${WRKSRC}/examples/*.cgi \
	      ${WRKSRC}/examples/Makefile.in
	${INSTALL_DATA} ${WRKSRC}/examples/* ${PREFIX}/share/examples/qDecoder


.include <bsd.port.mk>
