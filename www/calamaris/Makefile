# New ports collection makefile for:	calmaris
# Version required:	2.16
# Date created:         25 December 1998
# Whom:                 Dima Sivachenko
#
# $Id: Makefile,v 1.1.1.1 1999/01/21 23:28:03 billf Exp $
#

DISTNAME=	calamaris-2.16
CATEGORIES=	www textproc
MASTER_SITES=	http://calamaris.cord.de/ \
		ftp://ftp.bse.bg/pub/Unix/proxy/ \
		ftp://ftp.sai.msu.su/pub/unix/WWW/cache/squid/

MAINTAINER=	dima@Chg.RU

NO_BUILD=	yes
MAN1=		calamaris.1

post-patch:

	@ ${MV} ${WRKSRC}/calamaris ${WRKSRC}/calamaris.pre_sed
	@ ${SED} -e 's#/usr/bin/perl#${PERL5}#' ${WRKSRC}/calamaris.pre_sed \
	>> ${WRKSRC}/calamaris

do-install:

	@ ${INSTALL_MAN} ${WRKSRC}/calamaris.1 ${PREFIX}/man/man1/calamaris.1
	@ ${INSTALL_SCRIPT} ${WRKSRC}/calamaris ${PREFIX}/bin/calamaris

.include <bsd.port.mk>
