# New ports collection makefile for:	flog
# Date created:				7 October 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	flog
PORTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://oss.ezic.com/flog/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small STDIN-to-file logger with support for log rotation

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/flog ${WRKSRC}/flog.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flog ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
