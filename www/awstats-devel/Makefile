# New ports collection makefile for:	awstats
# Date created:			May 13, 2002
# Whom:				Munish Chopra <mchopra@engmail.uwaterloo.ca>
#
# $FreeBSD$
#

PORTNAME=	awstats
PORTVERSION=	4.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	mchopra@engmail.uwaterloo.ca

NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/www/cgi-bin/db
	@${MKDIR} ${PREFIX}/www/cgi-bin/lang
	@${MKDIR} ${PREFIX}/www/icons/browser
	@${MKDIR} ${PREFIX}/www/icons/clock
	@${MKDIR} ${PREFIX}/www/icons/cpu
	@${MKDIR} ${PREFIX}/www/icons/flags
	@${MKDIR} ${PREFIX}/www/icons/os
	@${MKDIR} ${PREFIX}/www/icons/other
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/awstats.model.conf ${PREFIX}/www/cgi-bin/awstats.model.conf
	${INSTALL_SCRIPT} ${WRKSRC}/wwwroot/cgi-bin/awstats.pl ${PREFIX}/www/cgi-bin/awstats.pl
	${INSTALL_SCRIPT} ${WRKSRC}/wwwroot/cgi-bin/db/* ${PREFIX}/www/cgi-bin/db
	${INSTALL_DATA} ${WRKSRC}/wwwroot/cgi-bin/lang/* ${PREFIX}/www/cgi-bin/lang
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/browser/* ${PREFIX}/www/icons/browser
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/clock/* ${PREFIX}/www/icons/clock
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/cpu/* ${PREFIX}/www/icons/cpu
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/flags/* ${PREFIX}/www/icons/flags
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/os/* ${PREFIX}/www/icons/os
	${INSTALL_DATA} ${WRKSRC}/wwwroot/icon/other/* ${PREFIX}/www/icons/other
	@${ECHO_CMD} ""
	@${ECHO_CMD} "* Rename ${PREFIX}/www/cgi-bin/awstats.model.conf to awstats.conf to set up AWStats"
	@${ECHO_CMD} "* Documentation has been installed in ${PREFIX}/share/doc/awstats"
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/images && ${CHMOD} -R a+rx ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
