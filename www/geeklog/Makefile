# New ports collection makefile for:	GeekLog
# Date Created: 	22 April 2002
# Whom:			Bob Bomar <bob@fly.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	geeklog
PORTVERSION=	1.3.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=geeklog

MAINTAINER=	bob@fly.homeunix.org

RUN_DEPENDS=    ${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql323-server
RUN_DEPENDS+=   ${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

NO_BUILD=	yes
APACHEDIR=	${LOCALBASE}/www/data
do-install:
	${MKDIR} ${APACHEDIR}/geeklog
	${CP} -R ${WRKSRC}/* ${APACHEDIR}/geeklog
	${CHOWN} -R www:www ${APACHEDIR}/geeklog
	${CHMOD} -R 777 ${APACHEDIR}/geeklog/logs
	${CHMOD} -R 777 ${APACHEDIR}/geeklog/public_html/backend
	@${ECHO} ""
	@${ECHO} "***********************************************************************"
	@${ECHO} "* You now need to create the database that you want GeekLog           *"
	@${ECHO} "* to reside in.                                                       *"
	@${ECHO} "* Once you have done that, the goto                                   *"
	@${ECHO} "* http://<;your_website>/geeklog/public_html/admin/install/install.php *"
	@${ECHO} "* And follow the instructions, then you are done!!                    *"
	@${ECHO} "***********************************************************************"
.include <bsd.port.mk>
