# New ports collection makefile for:	calmaris
# Date created:         25 December 1998
# Whom:                 Dima Sivachenko
#
# $FreeBSD$
#

PORTNAME=	calamaris
PORTVERSION=	2.40
CATEGORIES=	www textproc
MASTER_SITES=	http://cord.de/tools/squid/calamaris/ \
		ftp://ftp.gpad.ac.ru/pub/FreeBSD/distfiles/

MAINTAINER=	demon@FreeBSD.org

USE_PERL5=	yes
NO_BUILD=	yes
MAN1=		calamaris.1

post-patch:
	@ ${PERL} -pi -e 's#/usr/bin/perl#${PERL5}#' ${WRKSRC}/calamaris

do-install:
	@ ${INSTALL_MAN} ${WRKSRC}/calamaris.1 ${PREFIX}/man/man1/calamaris.1
	@ ${INSTALL_SCRIPT} ${WRKSRC}/calamaris ${PREFIX}/bin/calamaris

.include <bsd.port.mk>
