# Created by: dlowe
# $FreeBSD$

PORTNAME=	bulk_mailer
PORTVERSION=	1.13
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.utk.edu/pub/moore/bulk_mailer/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mat/

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Speeds delivery to mailing lists by sorting & batching addresses

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--cache-file=/dev/null

ALL_TARGET=	bulk_mailer

MAN1=		bulk_mailer.1

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bulk_mailer ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bulk_mailer.1 ${PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/bulk_mailer.README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/bulk_mailer.ps ${DOCSDIR}
.endif

.include <bsd.port.mk>
