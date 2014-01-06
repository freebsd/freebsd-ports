# Created by: jkoshy
# $FreeBSD$

PORTNAME=	rxp
PORTVERSION=	1.4.4
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cogsci.ed.ac.uk/pub/richard/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Validating XML parser written in C

RXP_HEADERS=	charset.h ctype16.h dtd.h hash.h input.h namespaces.h \
		rxputil.h stdio16.h string16.h system.h url.h version.h \
		xmlparser.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rxp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/librxp.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/rxp.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/rxp
	${INSTALL_DATA} ${RXP_HEADERS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/include/rxp

.include <bsd.port.mk>
