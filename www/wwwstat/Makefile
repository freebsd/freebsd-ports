# New ports collection makefile for:	wwwstat
# Date created:			So   2 M-Aär 1997 18:10:49 MET$)B
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	wwwstat
PORTVERSION=	2.01
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://www.ics.uci.edu/pub/websoft/wwwstat/ \
		ftp://ftp.gwdg.de/pub/misc/www-stat/websoft/wwwstat/
DISTNAME=	${PORTNAME}-2.0

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	patch-2.01.txt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Webserver logfile analysis package

RUN_DEPENDS=	${LOCALBASE}/etc/apache/httpd.conf:${PORTSDIR}/${APACHE_PORT}

USE_PERL5=	yes
MAKE_ENV+=	PERL5=${PERL5}
DIST_SUBDIR=	wwwstat
MAN1=		wwwstat.1 splitlog.1
SITEPERL=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}

do-install:
	@if [ ! -d ${SITEPERL} ]; then \
		${MKDIR} ${SITEPERL}; \
	fi
	@${INSTALL_SCRIPT} ${WRKSRC}/wwwstat    ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/splitlog   ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/monthly    ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/wwwerrs    ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/oldlog2new ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/wwwstat.rc  	${SITEPERL}
	@${INSTALL_DATA} ${WRKSRC}/splitlog.rc 	${SITEPERL}
	@${INSTALL_DATA} ${WRKSRC}/domains.pl 	${SITEPERL}
	@${INSTALL_MAN} ${WRKSRC}/wwwstat.1  ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/splitlog.1 ${PREFIX}/man/man1
	@${ECHO_MSG} "Edit the wwwstat.rc and splitlog.rc file ..."
	@${ECHO_MSG} "If needed, edit wwwstat and splitlog directly ..."
	@${ECHO_MSG} "These files are located in:"
	@${ECHO_MSG} "	${SITEPERL}"

.include <bsd.port.mk>
