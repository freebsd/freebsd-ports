# New ports collection makefile for:	Drupal
# Date Created: 			10 Nov 2003
# Whom:					Sebastian Yepes F. <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	drupal
PORTVERSION=	4.3.1
CATEGORIES=	www
MASTER_SITES=	http://drupal.org/drupal/${PORTVERSION}/drupal/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	esn@x123.info
COMMENT=	CMS that supports pgsql and mysql

RUN_DEPENDS=	${PEARDIR}/DB.php:${PORTSDIR}/databases/pear-DB

NO_BUILD=	yes
DRUPDIR=	www/data/drupal
DOCS=		CHANGELOG INSTALL LICENSE MAINTAINERS

do-install:

	${MKDIR} ${PREFIX}/${DRUPDIR}
	${CP} ${WRKSRC}/.htaccess ${PREFIX}/${DRUPDIR}
	${CP} ${WRKSRC}/cron.php ${PREFIX}/${DRUPDIR}
	${CP} -R ${WRKSRC}/database ${PREFIX}/${DRUPDIR}
	${CP} ${WRKSRC}/error.php ${PREFIX}/${DRUPDIR}
	${CP} ${WRKSRC}/favicon.ico ${PREFIX}/${DRUPDIR}
	${CP} -R ${WRKSRC}/includes ${PREFIX}/${DRUPDIR}
	${CP} ${WRKSRC}/index.php ${PREFIX}/${DRUPDIR}
	${CP} -R ${WRKSRC}/misc ${PREFIX}/${DRUPDIR}
	${CP} -R ${WRKSRC}/modules ${PREFIX}/${DRUPDIR}
	${CP} -R ${WRKSRC}/scripts ${PREFIX}/${DRUPDIR}
	${CP} -R ${WRKSRC}/themes ${PREFIX}/${DRUPDIR}
	${CP} ${WRKSRC}/update.php ${PREFIX}/${DRUPDIR}
	${CP} ${WRKSRC}/xmlrpc.php ${PREFIX}/${DRUPDIR}
	${MKDIR} ${PREFIX}/${DRUPDIR}/doc
.for FILE in ${DOCS}
	${CP} ${WRKSRC}/${FILE} ${PREFIX}/${DRUPDIR}/doc
.endfor
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${DRUPDIR}

	@${ECHO_MSG} ""
	@${ECHO_MSG} " You now need to create the database"
	@${ECHO_MSG} " where Drupal is going to live"
	@${ECHO_MSG} ""
	@${ECHO_MSG} " PostgreSQL::"
	@${ECHO_MSG} "    createdb -U pgsql -W drupal"
	@${ECHO_MSG} "    createuser -U pgsql -e drupal"
	@${ECHO_MSG} "    createlang -U pgsql -W plpgsql drupal"
	@${ECHO_MSG} "    psql -U drupal drupal < ${PREFIX}/${DRUPDIR}/database/database.pgsql"
	@${ECHO_MSG} ""
	@${ECHO_MSG} " MySQL::"
	@${ECHO_MSG} "    mysqladmin -u dba_user -p create drupal"
	@${ECHO_MSG} "    mysql -u dba_user -p"
	@${ECHO_MSG} "    GRANT ALL PRIVILEGES ON drupal.* TO nobody@localhost IDENTIFIED BY 'password';"
	@${ECHO_MSG} "    mysql -u nobody -p drupal <  ${PREFIX}/${DRUPDIR}/database/database.mysql"
	@${ECHO_MSG} ""
	@${ECHO_MSG} " Then edit the ${PREFIX}/${DRUPDIR}/includes/conf.php to your needs."
	@${ECHO_MSG} " Once you have done that"
	@${ECHO_MSG} " GoTo: http://<your_website>/drupal"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
