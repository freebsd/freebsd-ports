# New ports collection makefile for:	calmaris
# Date created:				25 December 1998
# Whom:					Dima Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	calamaris
PORTVERSION=	2.59
CATEGORIES=	www textproc
MASTER_SITES=	http://cord.de/tools/squid/calamaris/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A perl script to produce statistics out of Squid log files

USE_PERL5=	yes
NO_BUILD=	yes
MAN1=		calamaris.1

post-patch:
	@ ${PERL} -pi -e 's#/usr/bin/perl#${PERL}#' ${WRKSRC}/calamaris

do-install:
	@ ${INSTALL_MAN} ${WRKSRC}/calamaris.1 ${PREFIX}/man/man1/calamaris.1
	@ ${INSTALL_SCRIPT} ${WRKSRC}/calamaris ${PREFIX}/bin/calamaris
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/EXAMPLES ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
