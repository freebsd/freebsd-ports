# Ports collection makefile for:  horde2
# Date created:			  Sun Oct 07, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	horde
PORTVERSION=	2.2.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.horde.org/pub/horde/				\
		ftp://ftp.planetmirror.com/pub/horde/horde/		\
		ftp://ftp.au.horde.org/pub/horde/horde/			\
		ftp://ftp.be.horde.org/horde/				\
		ftp://ftp.es.horde.org/pub/horde/			\
		ftp://ftp.it.horde.org/pub/mirror/horde.org/horde/	\
		ftp://ftp.nl.horde.org/mirror/horde-ftp/pub/horde/	\
		ftp://ftp.uk.horde.org/mirrors/ftp.horde.org/pub/horde/	\
		http://ftp.horde.org/pub/horde/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A common code-base used by Horde applications, written in PHP

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITH_APACHE2: if you run Apache2;
#
# - WITHOUT_SUPPORTED_DB: if you run a database not in the ports tree.
#
# - WITHOUT_MYSQL:	this port is built with MySQL by default
#			but you might choose any other database
#			supported by PHP (e.g. WITH_POSTGRESQL).
#
# - WITHOUT_IMP:	this port is intended to build a default
#			package for IMP; use this knob if for
#			example you only need Chora.
#
# - WITHOUT_LDAP:	if you do not need OpenLDAP.
#
# - WITHOUT_MCAL:	if you don't plan to install Kronolith.
#
# - WITHOUT_FTP:	if you don't plan to install Gollem.
#
#-----------------------------------------------------------------------

RUN_DEPENDS=	${PEARDIR}/Date.php:${PORTSDIR}/devel/pear-Date			\
		${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common	\
		${PEARDIR}/Log.php:${PORTSDIR}/sysutils/pear-Log		\
		${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime

NO_BUILD=	yes
USE_PHP=	domxml gettext session
WANT_PHP_MOD=	yes
BROKEN_WITH_PHP=5
USE_REINPLACE=	yes

.if !defined(NOCRYPT)
USE_PHP+=	mcrypt
.endif
.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif
.if !defined(WITHOUT_LDAP)
USE_PHP+=	ldap
.endif
.if !defined(WITHOUT_IMP)
USE_PHP+=	imap
.endif
.if !defined(WITHOUT_MCAL)
USE_PHP+=	mcal
.endif
.if !defined(WITHOUT_FTP)
USE_PHP+=	ftp
.endif

REINPLACE_ARGS=	-i.beforeHorde
DOCS=		COPYING README docs/CHANGES docs/CODING_STANDARDS \
		docs/CONTRIBUTING docs/CREDITS docs/HACKING docs/INSTALL \
		docs/RELEASE_NOTES docs/SECURITY docs/TRANSLATIONS
CONFFILE=	horde.php html.php lang.php mime_drivers.php mime_mapping.php \
		motd.php prefs.php registry.php
SUB_DIRS=	config graphics lib locale po scripts templates util

LHORDEDIR?=	www/horde
LHORDESBIN?=	sbin

PLIST_SUB=	HORDEDIR=${LHORDEDIR} HORDESBIN=${LHORDESBIN}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
HORDESBIN=	${PREFIX}/${LHORDESBIN}
CONFDIR=	${HORDEDIR}/config

APACHE_CONF=	${APACHE_CNFDIR}/httpd.conf
PEARDIR?=	${LOCALBASE}/share/pear
.if defined(WITH_APACHE2)
APACHE_CNFDIR=	${LOCALBASE}/etc/apache2
.else
APACHE_CNFDIR=	${LOCALBASE}/etc/apache
.endif
HORDE_INC=	${PREFIX}/etc/horde
LOG_FILE?=	/var/log/horde.log

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you plan to install IMP, it is better to configure"
	@${ECHO_MSG} "PHP with IMAP / IMAP-SSL, OpenLDAP, OpenSSL, mcrypt, XML,"
	@${ECHO_MSG} "FTP, gettext, zlib, MCAL and a database (like MySQL or"
	@${ECHO_MSG} "PostgreSQL)."
	@${ECHO_MSG} "For Japanese language, please enable mbstring."
	@${ECHO_MSG} ""

pre-install:
	@if [ -f ${HORDEDIR}/index.php3 ]; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please deinstall the port www/horde." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
# N.B.: database dependencies are binded with mod_php#, not with Horde
.if !defined(WITHOUT_SUPPORTED_DB)
	@if ! php -m | ${GREP} -q -e "mysql" ; then \
	 if ! php -m | ${GREP} -q -e "pgsql" ; then \
	  if ! php -m | ${GREP} -q -e "sybase" ; then \
	   if ! php -m | ${GREP} -q -e "sybase_ct" ; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with a database support." ; \
	    ${ECHO_MSG} "MySQL, PostgreSQL and Sybase (CTLIB or DBLIB)" ; \
	    ${ECHO_MSG} "can be used with PHP AND Horde." ; \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "(If everything will run on this machine, do not" ; \
	    ${ECHO_MSG} " forget to install the database server-side!)" ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	   fi ; \
	  fi ; \
	 fi ; \
	fi
.endif

post-patch:
	@${RM} ${WRKSRC}/po/translation.php.orig	\
		${WRKSRC}/scripts/db/README.orig	\
		${WRKSRC}/scripts/set_perms.sh.orig	\
		${WRKSRC}/config/horde.php.dist.orig	\
		${WRKSRC}/config/registry.php.dist.orig	\
		${WRKSRC}/config/mime_drivers.php.dist.orig

do-install:
	@${MKDIR}  ${HORDEDIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${HORDEDIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${HORDEDIR}
	@if [ ! -f ${CONFDIR}/horde.php ]; then \
		${CP} ${CONFDIR}/horde.php.dist ${CONFDIR}/horde.php ; \
		${REINPLACE_CMD} -e "s:/tmp/horde.log:${LOG_FILE}:g" ${CONFDIR}/horde.php ; \
		${RM} ${CONFDIR}/horde.php.beforeHorde ; \
	fi
	@${REINPLACE_CMD} -e "s:/etc/mpasswd:${LOCALBASE}/etc/mpasswd:g" \
		${HORDEDIR}/lib/Auth/mcal.php
	@${RM} ${HORDEDIR}/lib/Auth/mcal.php.beforeHorde
.for FILE in ${CONFFILE}
	@if [ ! -f ${CONFDIR}/${FILE} ]; then \
	  ${CP} ${CONFDIR}/${FILE}.dist ${CONFDIR}/${FILE} ; \
	fi
.endfor
	@${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:" ${CONFDIR}/mime_drivers.php
	@${RM} ${CONFDIR}/mime_drivers.php.beforeHorde
	@${CP} ${WRKSRC}/scripts/set_perms.sh ${HORDESBIN}/horde_set_perms.sh
	@${REINPLACE_CMD} -e "s:UPDATED_BY_THE_PORT:${HORDEDIR}/:g" \
		${HORDESBIN}/horde_set_perms.sh
	@${RM} ${HORDESBIN}/horde_set_perms.sh.beforeHorde
	@${CHMOD} u+x ${HORDESBIN}/horde_set_perms.sh
	@(if [ -f ${APACHE_CONF} ] ; then \
		${MKDIR} ${HORDE_INC} ; \
		${CP} -p ${FILESDIR}/httpd.conf.horde ${HORDE_INC} ; \
		${REINPLACE_CMD} -e "s:/home/httpd/html/horde:${HORDEDIR}:g ; \
			s:/home/httpd/phplib:${PEARDIR}:g" ${HORDE_INC}/httpd.conf.horde ; \
		${RM} ${HORDE_INC}/httpd.conf.horde.beforeHorde ; \
		${ECHO_MSG} "===> Updating ${APACHE_CONF}..." ; \
		${REINPLACE_CMD} -e "s:php_value auto_prepend_file:# php_value auto_prepend_file:g ; \
			s:${HORDEDIR}/phplib:${PEARDIR}:g" ${APACHE_CONF} ; \
		${ECHO_CMD} "# Horde's include directory" >> ${APACHE_CONF} ; \
		${ECHO_CMD} "Include ${HORDE_INC}" >> ${APACHE_CONF} ; \
	fi)
	@${CHOWN} -R www:www ${HORDEDIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${TOUCH} ${LOG_FILE}
	@${CHOWN} www:www ${LOG_FILE}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${REINPLACE_CMD} -e "s:/usr/local/apache/htdocs:${PREFIX}/www:g" ${DOCSDIR}/INSTALL
	@${RM} ${DOCSDIR}/INSTALL.beforeHorde
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO}
	@${SED} -e "s:%%HORDEDIR%%:${HORDEDIR}:g;s:%%APACHE_CONF%%:${APACHE_CONF}:g"	\
		-e "s:%%HORDESBIN%%:${HORDESBIN}:g" ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
