# Ports collection makefile for:  horde2
# Date created:			  Sun Oct 07, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	horde
PORTVERSION=	2.2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.horde.org/pub/horde/				\
		ftp://ftp.au.horde.org/pub/horde/			\
		ftp://ftp.es.horde.org/pub/horde/			\
		ftp://ftp.it.horde.org/pub/mirror/horde.org/horde/	\
		ftp://ftp.nl.horde.org/mirror/horde-ftp/pub/horde/	\
		ftp://ftp.pt.horde.org/pub/horde-ftp/horde/

MAINTAINER=	thierry@pompo.net

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_SUPPORTED_DB: if you run a database not in the ports tree;
#
#-----------------------------------------------------------------------

LIB_DEPENDS+=	intl.4:${PORTSDIR}/devel/gettext
.if !defined(WITHOUT_MCAL)
LIB_DEPENDS+=	mcal.0:${PORTSDIR}/misc/libmcal
.endif
# Remark: pear-XML_sql2xml is included, but never used.
RUN_DEPENDS=	${PHP_LIB}/Console/Getopt.php:${PORTSDIR}/devel/pear-Console_Getopt \
		${PHP_LIB}/Crypt/CBC.php:${PORTSDIR}/security/pear-Crypt_CBC	\
		${PHP_LIB}/Date.php:${PORTSDIR}/devel/pear-Date		\
		${PHP_LIB}/DB.php:${PORTSDIR}/databases/pear-DB		\
		${PHP_LIB}/HTML/Select.php:${PORTSDIR}/devel/pear-HTML_Select	\
		${PHP_LIB}/Log.php:${PORTSDIR}/sysutils/pear-Log	\
		${PHP_LIB}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime \
		${PHP_LIB}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket

NO_BUILD=	yes
USE_REINPLACE=	yes

LDD=		/usr/bin/ldd

REINPLACE_ARGS=	-i.beforeHorde
DOCS=		COPYING README docs/CHANGES docs/CODING_STANDARDS \
		docs/CONTRIBUTING docs/CREDITS docs/HACKING docs/INSTALL
CONFFILE=	html.php lang.php mime_drivers.php mime_mapping.php \
		motd.php prefs.php registry.php
SUB_DIRS=	config graphics lib locale po scripts templates util

LHORDEDIR?=	www/horde
LHORDESBIN?=	sbin

PLIST_SUB=	HORDEDIR=${LHORDEDIR} HORDESBIN=${LHORDESBIN}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
HORDESBIN=	${PREFIX}/${LHORDESBIN}
CONFDIR=	${HORDEDIR}/config

APACHE_CNFDIR?=	${LOCALBASE}/etc/apache
APACHE_CONF=	${APACHE_CNFDIR}/httpd.conf
PHP_LIB?=	${LOCALBASE}/lib/php
PHPSO?=		${LOCALBASE}/libexec/apache/libphp4.so
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
	@if ! ${LDD} ${PHPSO} | ${GREP} -q -e "libintl.so"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with gettext support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
# N.B.: database dependencies are binded with mod_php#, not with Horde
.if !defined(WITHOUT_SUPPORTED_DB)
	@if ! ${LDD} ${PHPSO} | ${GREP} -q -e "libmysqlclient" ; then \
	 if ! ${LDD} ${PHPSO} | ${GREP} -q -e "libpq.so" ; then \
	  if ! ${LDD} ${PHPSO} | ${GREP} -q -e "libsybdb.so" ; then \
	   if ! ${LDD} ${PHPSO} | ${GREP} -q -e "libct.so" ; then \
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
			s:/home/httpd/phplib:${PHP_LIB}:g" ${HORDE_INC}/httpd.conf.horde ; \
		${RM} ${HORDE_INC}/httpd.conf.horde.beforeHorde ; \
		${ECHO_MSG} "===> Updating ${APACHE_CONF}..." ; \
		${REINPLACE_CMD} -e "s:php_value auto_prepend_file:# php_value auto_prepend_file:g ; \
			s:${HORDEDIR}/phplib:${PHP_LIB}:g" ${APACHE_CONF} ; \
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
	@${CAT} ${PKGMESSAGE} | ${SED} -e \
	"s:%%HORDEDIR%%:${HORDEDIR}:g;s:%%APACHE_CONF%%:${APACHE_CONF}:g;s:%%HORDESBIN%%:${HORDESBIN}:g"
	@${ECHO}

.include <bsd.port.mk>
