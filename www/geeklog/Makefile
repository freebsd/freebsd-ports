# New ports collection makefile for:	GeekLog
# Date Created: 	22 April 2002
# Whom:			Bob Bomar <bob@fly.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	geeklog
PORTVERSION=	1.3.7.s.2
CATEGORIES=	www
MASTER_SITES=	http://www.geeklog.net/filemgmt/upload_dir/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.s./sr/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GeekLog is a web content magagement system

RUN_DEPENDS=	${LOCALBASE}/bin/mysql:${PORTSDIR}/databases/mysql323-client
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

NO_BUILD=	yes
APACHEDIR=	${LOCALBASE}/www/data

do-install:
	${MKDIR} ${APACHEDIR}/geeklog
	${CP} -R ${WRKSRC}/* ${APACHEDIR}/geeklog
	${CHOWN} -R www:www ${APACHEDIR}/geeklog
	${CHMOD} -R 775 ${APACHEDIR}/geeklog/logs
	${CHMOD} -R 775 ${APACHEDIR}/geeklog/public_html/images/articles
	${CHMOD} -R 775 ${APACHEDIR}/geeklog/public_html/images/userphotos
	${CHMOD} -R 775 ${APACHEDIR}/geeklog/public_html/backend
	@${ECHO} ""
	@${ECHO} "***********************************************************************"
	@${ECHO} "* You now need to create the database that you want GeekLog           *"
	@${ECHO} "* to reside in.                                                       *"
	@${ECHO} "* Then edit the config.php file to your needs.                        *"
	@${ECHO} "* Once you have done that, the goto                                   *"
	@${ECHO} "* http://<your_website>/geeklog/public_html/admin/install/install.php *"
	@${ECHO} "* And follow the instructions, then you are done!!                    *"
	@${ECHO} "***********************************************************************"

.include <bsd.port.mk>
