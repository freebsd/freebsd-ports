# New ports collection Makefile for: rxp
# Date created:		12 Jan 2001
# Whom:			jkoshy
#
# $FreeBSD$
#

PORTNAME=	rxp
PORTVERSION=	1.3.0
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cogsci.ed.ac.uk/pub/richard/

MAINTAINER=	jkoshy@freebsd.org
COMMENT=	A validating XML parser written in C

MAN1=	rxp.1

RXP_HEADERS=	charset.h ctype16.h dtd.h hash.h input.h namespaces.h \
		rxputil.h stdio16.h string16.h system.h url.h version.h \
		xmlparser.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rxp ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/librxp.a ${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/rxp.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/include/rxp
.for h in ${RXP_HEADERS}
	${INSTALL_DATA} ${WRKSRC}/${h} ${PREFIX}/include/rxp
.endfor

.include <bsd.port.mk>
