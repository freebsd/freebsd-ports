# New ports collection makefile for:	flog
# Date created:				7 October 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	flog
PORTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://oss.ezic.com/flog/ \
		http://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	ports@FreeBSD.org

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/flog ${WRKSRC}/flog.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flog ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
