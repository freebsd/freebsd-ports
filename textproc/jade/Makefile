# New ports collection makefile for:	jade
# Version required:	1.2
# Date created:		June 19, 1997
# Whom:			jfieber
#
# $Id: Makefile,v 1.14 1999/01/27 12:47:14 dirk Exp $
#

DISTNAME=	jade-1.2.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/jade/

MAINTAINER=	jfieber@FreeBSD.ORG

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CFLAGS}"

post-install:
.for i in jade nsgmls sgmlnorm spam spent sx
	strip ${PREFIX}/bin/$i
.endfor
	${MKDIR} ${PREFIX}/include/sp
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/sp
	${MKDIR} ${PREFIX}/share/doc/jade
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${PREFIX}/share/doc/jade
	${MKDIR} ${PREFIX}/share/sgml/jade
	${INSTALL_DATA} ${WRKSRC}/dsssl/* ${PREFIX}/share/sgml/jade
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m $(PREFIX)/lib

.include <bsd.port.mk>
