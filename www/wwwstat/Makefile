# $FreeBSD$

PORTNAME=	wwwstat
PORTVERSION=	2.01
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.ics.uci.edu/pub/websoft/wwwstat/ \
		ftp://ftp.gwdg.de/pub/misc/www-stat/websoft/wwwstat/
DISTNAME=	${PORTNAME}-2.0

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	patch-2.01.txt

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Webserver logfile analysis package


USE_APACHE_RUN=	22+
USES=		perl5
MAKE_ENV+=	PERL5=${PERL5}

MAN1=	wwwstat.1 splitlog.1

NO_STAGE=	yes
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
