# New ports collection makefile for:	GeekLog
# Date Created: 	22 April 2002
# Whom:			Bob Bomar <bob@fly.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	geeklog
PORTVERSION=	1.3.9.r2
CATEGORIES=	www
MASTER_SITES=	http://www.geeklog.net/filemgmt/upload_dir/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GeekLog is a web content magagement system

USE_MYSQL=	yes

NO_BUILD=	yes
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
.if defined(WITH_APACHE2)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache2/libphp4.so:${PORTSDIR}/www/mod_php4
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
.endif

WWW_DIR=	${PREFIX}/www/data

do-install:
	${MKDIR} ${WWW_DIR}/geeklog
	${CP} -R ${WRKSRC}/* ${WWW_DIR}/geeklog
	${CHOWN} -R www:www ${WWW_DIR}/geeklog
	${CHMOD} -R 775 ${WWW_DIR}/geeklog/logs
	${CHMOD} -R 775 ${WWW_DIR}/geeklog/public_html/images/articles
	${CHMOD} -R 775 ${WWW_DIR}/geeklog/public_html/images/userphotos
	${CHMOD} -R 775 ${WWW_DIR}/geeklog/public_html/backend
	@${ECHO_MSG} ""
	@${ECHO_MSG} "***********************************************************************"
	@${ECHO_MSG} "* You now need to create the database that you want GeekLog           *"
	@${ECHO_MSG} "* to reside in.                                                       *"
	@${ECHO_MSG} "* Then edit the config.php file to your needs.                        *"
	@${ECHO_MSG} "* Once you have done that, the goto                                   *"
	@${ECHO_MSG} "* http://<your_website>/geeklog/public_html/admin/install/install.php *"
	@${ECHO_MSG} "* And follow the instructions, then you are done!!                    *"
	@${ECHO_MSG} "***********************************************************************"

.include <bsd.port.mk>
