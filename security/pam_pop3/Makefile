# New ports collection makefile for:    pam_pop3
# Date created:				16 July 2002
# Whom:	      				Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	pam_pop3
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://shum.huji.ac.il/~schapiro/linux/pam_pop3/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	This module authenticates a user against a POP3 server

WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	${CC} ${CFLAGS} -fpic -DPIC -Wall -c ${WRKSRC}/pam_pop3.c -o ${WRKSRC}/pam_pop3.o
	${LD} -x --shared -o ${WRKSRC}/pam_pop3.so ${WRKSRC}/pam_pop3.o -lpam -lcrypt

do-install:
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.so ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
