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

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--cache-file=/dev/null

ALL_TARGET=	bulk_mailer

MAN1=		bulk_mailer.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/bulk_mailer ${PREFIX}/bin/bulk_mailer
	@ ${MKDIR} ${PREFIX}/share/doc/bulk_mailer
	@ ${INSTALL_MAN} ${WRKSRC}/bulk_mailer.README \
		${PREFIX}/share/doc/bulk_mailer/README
	@ ${INSTALL_MAN} ${WRKSRC}/bulk_mailer.1 ${PREFIX}/man/man1/bulk_mailer.1

.include <bsd.port.mk>
