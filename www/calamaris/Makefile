# New ports collection makefile for:	calmaris
# Version required:	2.8
# Date created:         25 December 1998
# Whom:                 Dima Sivachenko
#
# $Id$
#

DISTNAME=	calamaris-2.8
CATEGORIES=	www textproc
MASTER_SITES=	http://calamaris.cord.de/ \
		ftp://ftp.win.or.jp/pub/network/www/log-tools/ \
		ftp://ftp.c-com.net/pub/.30/LinuxBerg/files/console/

MAINTAINER=	dima@Chg.RU

NO_BUILD=	yes

post-patch:

	@ ${MV} ${WRKSRC}/calamaris.pl ${WRKSRC}/calamaris.pl.pre_sed
	@ ${SED} -e 's#/usr/bin/perl#${PERL5}#' ${WRKSRC}/calamaris.pl.pre_sed \
	>> ${WRKSRC}/calamaris.pl

do-install:

	@ ${INSTALL_SCRIPT} ${WRKSRC}/calamaris.pl ${PREFIX}/bin/calamaris

.include <bsd.port.mk>
