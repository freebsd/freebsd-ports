# New ports collection makefile for:	wwwstat
# Version required:		2.01
# Date created:			So   2 Mär 1997 18:10:49 MET
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id: Makefile,v 1.7 1997/10/13 21:06:15 andreas Exp $
#

DISTNAME=	wwwstat-2.01
CATEGORIES=	www
MASTER_SITES=	ftp://www.ics.uci.edu/pub/websoft/wwwstat/
DISTFILES=	wwwstat-2.0.tar.gz

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	patch-2.01.txt

MAINTAINER=	andreas@FreeBSD.ORG

RUN_DEPENDS=    ${PREFIX}/etc/apache/srm.conf:${PORTSDIR}/www/apache13

USE_PERL5=	yes
DIST_SUBDIR=	wwwstat
WRKSRC=		${WRKDIR}/wwwstat-2.0
MAN1=		wwwstat.1 splitlog.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/wwwstat    ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/splitlog   ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/monthly    ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/wwwerrs    ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/oldlog2new ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/wwwstat.rc  \
			 ${PREFIX}/lib/perl5/site_perl/i386-freebsd
	@${INSTALL_DATA} ${WRKSRC}/splitlog.rc \
			 ${PREFIX}/lib/perl5/site_perl/i386-freebsd
	@${INSTALL_DATA} ${WRKSRC}/domains.pl \
			 ${PREFIX}/lib/perl5/site_perl/i386-freebsd
	@${INSTALL_MAN} ${WRKSRC}/wwwstat.1  ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/splitlog.1 ${PREFIX}/man/man1
	@${ECHO_MSG} "Edit the wwwstat.rc and splitlog.rc file ..."
	@${ECHO_MSG} "If needed, edit wwwstat and splitlog directly ..."
	@${ECHO_MSG} "These files are located in:"
	@${ECHO_MSG} "	${PREFIX}/lib/perl5/site_perl/i386-freebsd"

.include <bsd.port.mk>
