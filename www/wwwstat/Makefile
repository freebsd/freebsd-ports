# New ports collection makefile for:	wwwstat
# Date created:			So   2 M-Aär 1997 18:10:49 MET$)B
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	wwwstat
PORTVERSION=	2.01
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.ics.uci.edu/pub/websoft/wwwstat/ \
		ftp://ftp.gwdg.de/pub/misc/www-stat/websoft/wwwstat/
DISTNAME=	${PORTNAME}-2.0

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	patch-2.01.txt

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Webserver logfile analysis package

USE_APACHE=	1.3
USE_PERL5=	yes
MAKE_ENV+=	PERL5=${PERL5}

MAN1=	wwwstat.1 splitlog.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/wwwstat    ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/splitlog   ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/monthly    ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/wwwerrs    ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/oldlog2new ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/wwwstat.1  ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/splitlog.1 ${PREFIX}/man/man1
	@${INSTALL_DATA} ${WRKSRC}/wwwstat.rc  	${SITE_PERL}
	@${INSTALL_DATA} ${WRKSRC}/splitlog.rc 	${SITE_PERL}
	@${INSTALL_DATA} ${WRKSRC}/domains.pl 	${SITE_PERL}
	@${ECHO_MSG} "Edit the wwwstat.rc and splitlog.rc file ..."
	@${ECHO_MSG} "If needed, edit wwwstat and splitlog directly ..."
	@${ECHO_MSG} "These files are located in:"
	@${ECHO_MSG} "	${SITE_PERL}"

.include <bsd.port.mk>
