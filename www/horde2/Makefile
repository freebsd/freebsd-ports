# Ports collection makefile for:  horde-devel
# Date created:			  Sun Oct 07, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	horde
PORTVERSION=	2.0
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.horde.org/pub/horde/tarballs/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION}-RC2

MAINTAINER=	thierry@thomas.as

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
RUN_DEPENDS+=	${LOCALBASE}/lib/php/Cache/DB.php:${PORTSDIR}/devel/pear
#RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

NO_BUILD=	yes
DOCS=		COPYING README docs/CHANGES docs/CREDITS docs/CODING_STANDARDS \
		docs/HELP docs/INSTALL docs/RELEASE

LHORDEDIR?=	www/horde
LHORDESBIN?=	sbin

PLIST_SUB=	HORDEDIR=${LHORDEDIR} HORDESBIN=${LHORDESBIN}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
HORDESBIN=	${PREFIX}/${LHORDESBIN}

APACHE_CNFDIR?=	${LOCALBASE}/etc/apache
APACHE_CONF=	${APACHE_CNFDIR}/httpd.conf
PHP_LIB?=	${LOCALBASE}/lib/php
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
	@${ECHO_MSG} "PHP with IMAP, OpenLDAP, OpenSSL, mcrypt, XML, FTP,"
	@${ECHO_MSG} "gettext, pspell, zlib, MCAL and"
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
	${MKDIR}  ${HORDEDIR}
	${CP} -Rp ${WRKSRC}/config ${WRKSRC}/graphics ${WRKSRC}/lib ${HORDEDIR}
	${CP} -Rp ${WRKSRC}/locale ${WRKSRC}/scripts ${WRKSRC}/templates ${HORDEDIR}
	${CP} -Rp ${WRKSRC}/po ${WRKSRC}/admin ${WRKSRC}/util ${HORDEDIR}
	${CP} -p  ${WRKSRC}/*.php ${HORDEDIR}
	@if [ ! -f ${HORDEDIR}/config/horde.php ]; then \
		${CP} ${HORDEDIR}/config/horde.php.dist ${HORDEDIR}/config/horde.php ; \
		${PERL} -pi -e "s:/var/www/htdocs/horde/templates:${HORDEDIR}/templates:g" \
			${HORDEDIR}/config/horde.php ; \
		${PERL} -pi -e "s:/tmp/horde.log:${LOG_FILE}:g" ${HORDEDIR}/config/horde.php ; \
	fi
	@if [ ! -f ${HORDEDIR}/config/html.php ]; then \
		${CP} ${HORDEDIR}/config/html.php.dist ${HORDEDIR}/config/html.php ; \
	fi
	@if [ ! -f ${HORDEDIR}/config/lang.php ]; then \
		${CP} ${HORDEDIR}/config/lang.php.dist ${HORDEDIR}/config/lang.php ; \
	fi
	@if [ ! -f ${HORDEDIR}/config/mime_drivers.php ]; then \
		${CP} ${HORDEDIR}/config/mime_drivers.php.dist ${HORDEDIR}/config/mime_drivers.php ; \
	fi
	@if [ ! -f ${HORDEDIR}/config/mime_mapping.php ]; then \
		${CP} ${HORDEDIR}/config/mime_mapping.php.dist ${HORDEDIR}/config/mime_mapping.php ; \
	fi
	@if [ ! -f ${HORDEDIR}/config/motd.php ]; then \
		${CP} ${HORDEDIR}/config/motd.php.dist ${HORDEDIR}/config/motd.php ; \
	fi
	@if [ ! -f ${HORDEDIR}/config/registry.php ]; then \
		${CP} ${HORDEDIR}/config/registry.php.dist ${HORDEDIR}/config/registry.php ; \
	fi
	${CP} ${WRKSRC}/scripts/set_perms.sh ${HORDESBIN}/horde_set_perms.sh
	${PERL} -pi -e "s:UPDATED_BY_THE_PORT:${HORDEDIR}/:g" ${HORDESBIN}/horde_set_perms.sh
	 (if [ -f ${APACHE_CONF} ] ; then \
	    (if [ ! -f ${APACHE_CONF}.beforeHorde ] ; then \
		${ECHO} "===> Updating ${APACHE_CONF}..." ; \
		${CP} -p ${FILESDIR}/httpd.conf.horde ${WRKDIR}/httpd.conf.horde ; \
		${PERL} -pi -e "s:/home/httpd/html/horde:${HORDEDIR}:g" ${WRKDIR}/httpd.conf.horde ; \
		${PERL} -pi -e "s:/home/httpd/phplib:${PHP_LIB}:g" ${WRKDIR}/httpd.conf.horde ; \
		${CP} -p ${APACHE_CONF} ${APACHE_CONF}.beforeHorde ; \
		${GREP} -qw 'Added for Horde' ${APACHE_CONF} || ${CAT} ${WRKDIR}/httpd.conf.horde >> ${APACHE_CONF} ; \
	    else \
		${ECHO} "===> Updating ${APACHE_CONF}..." ; \
		${CP} -p ${APACHE_CONF} ${APACHE_CONF}.reinstHorde ; \
		${PERL} -pi -e "s:php_value auto_prepend_file:# php_value auto_prepend_file:g" ${APACHE_CONF} ; \
		${PERL} -pi -e "s:${HORDEDIR}/phplib:${PHP_LIB}:g" ${APACHE_CONF} ; \
	    fi) ; \
	fi)
	${CHOWN} -R www:www ${HORDEDIR}
	${CHMOD} -R o-rwx ${HORDEDIR}/config
	${TOUCH} ${LOG_FILE}
	${CHOWN} www:www ${LOG_FILE}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	${PERL} -pi -e "s:/usr/local/apache/htdocs/horde:${DOCSDIR}:g" ${DOCSDIR}/INSTALL
	@${ECHO} "Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE} | ${SED} -e \
	"s:%%HORDEDIR%%:${HORDEDIR}:g;s:%%APACHE_CONF%%:${APACHE_CONF}:g;s:%%HORDESBIN%%:${HORDESBIN}:g"
	@${ECHO}

.include <bsd.port.mk>
