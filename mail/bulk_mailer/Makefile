# New ports collection makefile for:	bulk_mailer
# Version required:	1.11
# Date created:	20 March 1997
# Whom:		dlowe
#
# $Id: Makefile,v 1.5 1998/10/12 18:33:55 jseger Exp $
#

DISTNAME=	bulk_mailer-1.11
CATEGORIES=	mail
MASTER_SITES=	ftp://cs.utk.edu/pub/moore/bulk_mailer/

MAINTAINER=	dlowe@saturn5.com

MAN1=		bulk_mailer.1

WRKSRC=	${WRKDIR}/bulk_mailer

HAS_CONFIGURE=	YES

ALL_TARGET=	bulk_mailer

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/bulk_mailer ${PREFIX}/bin/bulk_mailer
	@ ${INSTALL_DATA} ${WRKSRC}/bulk_mailer.README \
 		${PREFIX}/share/doc/bulk_mailer.README
	@ ${INSTALL_MAN} ${WRKSRC}/bulk_mailer.1 ${PREFIX}/man/man1/bulk_mailer.1

.include <bsd.port.mk>
