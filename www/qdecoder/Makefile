# New ports collection makefile for:    qDecoder library
# Date created:         Sep 10 1999
# Whom:                 CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qDecoder
PORTVERSION=	7.0
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.qDecoder.org/pub/qDecoder/\
		ftp://ftp2.qDecoder.org/pub/qDecoder/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	CGI library for C/C++ language programming

GNU_CONFIGURE=	YES

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${MKDIR} ${PREFIX}/share/doc/qDecoder
.for doc in AUTHORS DISCLAIMER README REFERENCE qDecoder.jpg
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/qDecoder
.endfor
	${MKDIR} ${PREFIX}/share/examples/qDecoder
	-${RM} ${WRKSRC}/examples/*.o ${WRKSRC}/examples/*.cgi \
	      ${WRKSRC}/examples/Makefile.in
	${INSTALL_DATA} ${WRKSRC}/examples/Makefile ${PREFIX}/share/examples/qDecoder
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${PREFIX}/share/examples/qDecoder
	${INSTALL_DATA} ${WRKSRC}/examples/*.conf ${PREFIX}/share/examples/qDecoder
	${INSTALL_DATA} ${WRKSRC}/examples/*.html ${PREFIX}/share/examples/qDecoder
	${INSTALL_DATA} ${WRKSRC}/examples/*.in ${PREFIX}/share/examples/qDecoder


.include <bsd.port.mk>
