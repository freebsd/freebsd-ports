# New ports collection makefile for:	bulk_mailer
# Date created:	20 March 1997
# Whom:		dlowe
#
# $FreeBSD$
#

PORTNAME=	bulk_mailer
PORTVERSION=	1.13
CATEGORIES=	mail
MASTER_SITES=	ftp://cs.utk.edu/pub/moore/bulk_mailer/

MAINTAINER=	dlowe@saturn5.com
COMMENT=	Speeds delivery to mailing lists by sorting & batching addresses

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--cache-file=/dev/null

ALL_TARGET=	bulk_mailer

MAN1=		bulk_mailer.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bulk_mailer ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bulk_mailer.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/bulk_mailer.README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/bulk_mailer.ps ${DOCSDIR}
.endif

.include <bsd.port.mk>
