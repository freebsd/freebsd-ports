# New ports collection makefile for:	calmaris
# Version required:	2.22
# Date created:         25 December 1998
# Whom:                 Dima Sivachenko
#
# $Id: Makefile,v 1.3 1999/02/23 22:30:57 billf Exp $
#

DISTNAME=	calamaris-2.23
CATEGORIES=	www textproc
MASTER_SITES=	http://calamaris.cord.de/ \
		ftp://ftp.gpad.ac.ru/pub/FreeBSD/distfiles/

MAINTAINER=	dima@Chg.RU

NO_BUILD=	yes
MAN1=		calamaris.1

post-patch:

	@ ${MV} ${WRKSRC}/calamaris ${WRKSRC}/calamaris.pre_sed
	@ ${SED} -e 's#/usr/bin/perl#${PERL5}#' ${WRKSRC}/calamaris.pre_sed \
	> ${WRKSRC}/calamaris

do-install:

	@ ${INSTALL_MAN} ${WRKSRC}/calamaris.1 ${PREFIX}/man/man1/calamaris.1
	@ ${INSTALL_SCRIPT} ${WRKSRC}/calamaris ${PREFIX}/bin/calamaris

.include <bsd.port.mk>
