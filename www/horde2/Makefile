# Ports collection makefile for:  horde-devel
# Date created:			  Sun Oct 07, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	horde
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.horde.org/pub/horde/tarballs/
PKGNAMESUFFIX=	-devel

MAINTAINER=	thierry@pompo.net

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_SSL		: if you do not need Apache with mod_ssl;
#
#-----------------------------------------------------------------------

LIB_DEPENDS+=	intl.1:${PORTSDIR}/devel/gettext
.if !defined(WITHOUT_MCAL)
LIB_DEPENDS+=	mcal.0:${PORTSDIR}/misc/libmcal
.endif
.if !defined(WITHOUT_SSL)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libssl.so:${PORTSDIR}/www/apache13-modssl
.endif
#RUN_DEPENDS+=	${LOCALBASE}/lib/php/Cache/DB.php:${PORTSDIR}/devel/pear
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

NO_BUILD=	yes
DOCS=		COPYING README docs/CHANGES docs/CODING_STANDARDS \
		docs/CONTRIBUTING docs/CREDITS docs/HACKING docs/INSTALL
CONFFILE=	html.php lang.php mime_drivers.php mime_mapping.php \
		motd.php registry.php

LHORDEDIR?=	www/horde
LHORDESBIN?=	sbin

PLIST_SUB=	HORDEDIR=${LHORDEDIR} HORDESBIN=${LHORDESBIN}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
HORDESBIN=	${PREFIX}/${LHORDESBIN}
CONFDIR=	${HORDEDIR}/config

APACHE_CNFDIR?=	${LOCALBASE}/etc/apache
APACHE_CONF=	${APACHE_CNFDIR}/httpd.conf
PHP_LIB?=	${LOCALBASE}/lib/php
HORDE_INC=	${PREFIX}/etc/horde
LOG_FILE?=	/var/log/horde.log

pre-everything::
.if !defined(WITHOUT_SSL)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press CTRL-C and define WITHOUT_SSL"
	@${ECHO_MSG} " if you do not want to use Apache with SSL."
	@${ECHO_MSG} ""
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you plan to install IMP, it is better to configure"
	@${ECHO_MSG} "PHP with IMAP / IMAP-SSL, OpenLDAP, OpenSSL, mcrypt, XML,"
	@${ECHO_MSG} "FTP, gettext, pspell, zlib, MCAL and"
	@${ECHO_MSG} "a database (like MySQL or PostgreSQL)."
	@${ECHO_MSG} ""

pre-install:
	@if [ -f ${HORDEDIR}/index.php3 ]; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please deinstall the port www/horde." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "lintl.1"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with gettext support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi

do-install:
	@${MKDIR}  ${HORDEDIR}
	@${CP} -Rp ${WRKSRC}/config ${WRKSRC}/graphics ${WRKSRC}/lib ${HORDEDIR}
	@${CP} -Rp ${WRKSRC}/locale ${WRKSRC}/scripts ${WRKSRC}/templates ${HORDEDIR}
	@${CP} -Rp ${WRKSRC}/po ${WRKSRC}/admin ${WRKSRC}/util ${HORDEDIR}
	@${CP} -p  ${WRKSRC}/*.php ${HORDEDIR}
	@if [ ! -f ${CONFDIR}/horde.php ]; then \
		${CP} ${CONFDIR}/horde.php.dist ${CONFDIR}/horde.php ; \
		${PERL} -pi -e "s:/var/www/htdocs/horde/templates:${HORDEDIR}/templates:g" \
			${CONFDIR}/horde.php ; \
		${PERL} -pi -e "s:/tmp/horde.log:${LOG_FILE}:g" ${CONFDIR}/horde.php ; \
	fi
	@${PERL} -pi -e "s:/etc/mpasswd:${LOCALBASE}/etc/mpasswd:g" \
		${HORDEDIR}/lib/Auth/mcal.php
.for FILE in ${CONFFILE}
	@if [ ! -f ${CONFDIR}/${FILE} ]; then \
	  ${CP} ${CONFDIR}/${FILE}.dist ${CONFDIR}/${FILE} ; \
	fi
.endfor
	@${CP} ${WRKSRC}/scripts/set_perms.sh ${HORDESBIN}/horde_set_perms.sh
	@${PERL} -pi -e "s:UPDATED_BY_THE_PORT:${HORDEDIR}/:g" \
		${HORDESBIN}/horde_set_perms.sh
	@${CHMOD} u+x ${HORDESBIN}/horde_set_perms.sh
	@(if [ -f ${APACHE_CONF} ] ; then \
	    ${MKDIR} ${HORDE_INC} ; \
	    ${CP} -p ${FILESDIR}/httpd.conf.horde ${HORDE_INC} ; \
	    ${PERL} -pi -e "s:/home/httpd/html/horde:${HORDEDIR}:g" ${HORDE_INC}/httpd.conf.horde ; \
	    ${PERL} -pi -e "s:/home/httpd/phplib:${PHP_LIB}:g" ${HORDE_INC}/httpd.conf.horde ; \
	    ${ECHO_MSG} "===> Updating ${APACHE_CONF}..." ; \
	    ${CP} -p ${APACHE_CONF} ${APACHE_CONF}.beforeHorde ; \
	    ${PERL} -pi -e "s:php_value auto_prepend_file:# php_value auto_prepend_file:g" ${APACHE_CONF} ; \
	    ${PERL} -pi -e "s:${HORDEDIR}/phplib:${PHP_LIB}:g" ${APACHE_CONF} ; \
	    ${ECHO} "# Horde's include directory" >> ${APACHE_CONF} ; \
	    ${ECHO} "Include ${HORDE_INC}" >> ${APACHE_CONF} ; \
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
	@${PERL} -pi -e "s:/usr/local/apache/htdocs/horde:${DOCSDIR}:g" ${DOCSDIR}/INSTALL
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE} | ${SED} -e \
	"s:%%HORDEDIR%%:${HORDEDIR}:g;s:%%APACHE_CONF%%:${APACHE_CONF}:g;s:%%HORDESBIN%%:${HORDESBIN}:g"
	@${ECHO}

.include <bsd.port.mk>
