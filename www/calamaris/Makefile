# New ports collection makefile for:	calmaris
# Date created:         25 December 1998
# Whom:                 Dima Sivachenko
#
# $FreeBSD$
#

PORTNAME=	calamaris
PORTVERSION= 	2.29
CATEGORIES=	www textproc
MASTER_SITES=	http://calamaris.cord.de/ \
		ftp://ftp.gpad.ac.ru/pub/FreeBSD/distfiles/

MAINTAINER=	dima@Chg.RU

USE_PERL5=	yes
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
