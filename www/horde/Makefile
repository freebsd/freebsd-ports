# Ports collection makefile for:  horde
# Date created:			  Sat Jul 07, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
# N.B.: parts of this ports come from the Horde's port by NetBSD (jlam@netbsd.org)
#
# $FreeBSD$
#

PORTNAME=	horde
PORTVERSION=	1.2.8
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.horde.org/pub/horde/tarballs/

MAINTAINER=	thierry@pompo.net

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_SSL		: if you do not need Apache with mod_ssl;
#
# - WITH_PHP3		: if you do not need PHP4.
#
#-----------------------------------------------------------------------

.if !defined(WITHOUT_SSL)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libssl.so:${PORTSDIR}/www/apache13-modssl
.endif
.if defined(WITH_PHP3)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp3.so:${PORTSDIR}/www/mod_php3
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
.endif

NO_BUILD=	yes
USE_REINPLACE=	yes

REINPLACE_ARGS=	-i.beforeHorde
DOCS=		COPYING README docs/CHANGES docs/CREDITS docs/DATABASE \
		docs/HELP docs/INSTALL docs/SECURITY

LHORDEDIR?=	www/horde
LPHPLIBDIR?=	www/horde/phplib
LHORDESBIN?=	sbin

PLIST_SUB=	HORDEDIR=${LHORDEDIR} PHPLIBDIR=${LPHPLIBDIR} HORDESBIN=${LHORDESBIN}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
PHPLIBDIR=	${PREFIX}/${LPHPLIBDIR}
HORDESBIN=	${PREFIX}/${LHORDESBIN}

APACHE_CNFDIR?=	${LOCALBASE}/etc/apache
PHP_DIR?=	${LOCALBASE}/etc
APACHE_CONF=	${APACHE_CNFDIR}/httpd.conf
MIMETYPES=	${APACHE_CNFDIR}/mime.types

.if defined(WITH_PHP3)
PHP_INI=	${PHP_DIR}/php3.ini
.else
PHP_INI=	${PHP_DIR}/php.ini
.endif

pre-everything::
.if !defined(WITHOUT_SSL)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press CTRL-C and define WITHOUT_SSL"
	@${ECHO_MSG} " if you do not want to use Apache with SSL."
	@${ECHO_MSG} ""
.endif
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you plan to install IMP, it is better to configure"
	@${ECHO_MSG} "PHP with IMAP, OpenLDAP, OpenSSL,"
	@${ECHO_MSG} "and a database (like MySQL or PostgreSQL), and pspell."
	@${ECHO_MSG} ""
.if !defined(WITH_PHP3)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press CTRL-C and define WITH_PHP3 if you want to use horde with PHP3."
	@${ECHO_MSG} ""
.endif

pre-install:
	@if [ -f ${HORDEDIR}/index.php ]; then \
		${ECHO_MSG} "" ; \
		${ECHO_MSG} "Please deinstall the port www/horde2." ; \
		${ECHO_MSG} "" ; \
		${FALSE} ; \
	 fi

do-install:
	${MKDIR}  ${HORDEDIR}
	${MKDIR}  ${PHPLIBDIR}
	${CP} -Rp ${WRKSRC}/config ${WRKSRC}/graphics ${WRKSRC}/lib ${HORDEDIR}
	${CP} -Rp ${WRKSRC}/locale ${WRKSRC}/scripts ${WRKSRC}/templates ${HORDEDIR}
	${CP} -p  ${WRKSRC}/phplib/* ${PHPLIBDIR}
	${CP} -p  ${WRKSRC}/*.php3 ${HORDEDIR}
	${REINPLACE_CMD} -e "s:-d imp:-d ${HORDEDIR}/imp:g	; \
		s:config/horde:${HORDEDIR}/config/horde:g	; \
		s:imp/config:${HORDEDIR}/imp/config:g		; \
		s:chmod 444 :chmod 444 ${HORDEDIR}/:g" ${WRKSRC}/install.sh
	${CP} ${WRKSRC}/install.sh ${HORDESBIN}/horde_setup.sh
	${REINPLACE_CMD} -e "s:%%HORDEDIR%%:${HORDEDIR}:g" ${WRKSRC}/secure.sh
	${CP} ${WRKSRC}/secure.sh  ${HORDESBIN}/horde_secure.sh
	${CHMOD} u+x ${HORDESBIN}/horde_secure.sh
	${CHMOD} u+x ${HORDESBIN}/horde_setup.sh
	${REINPLACE_CMD} -e "s:go to the top level directory for your installation and run:run:g ; \
		s:sh ./install.sh:${HORDESBIN}/horde_setup.sh:g" ${HORDEDIR}/setup.php3
	@${RM} ${HORDEDIR}/setup.php3.beforeHorde
	${REINPLACE_CMD} -e "s:sh ./install.sh:${HORDESBIN}/horde_setup.sh:g"	\
		${HORDEDIR}/templates/index/horde_notconfigured.inc
	@${RM} ${HORDEDIR}/templates/index/horde_notconfigured.inc.beforeHorde
	${REINPLACE_CMD} -e "s:sh ./secure.sh:${HORDESBIN}/horde_secure.sh:g"	\
		${HORDEDIR}/templates/setup/imp/write_file.inc
	@${RM} ${HORDEDIR}/templates/setup/imp/write_file.inc.beforeHorde
	${CP}     ${HORDEDIR}/config/horde.php3.dist ${HORDEDIR}/config/horde.php3
	${CHMOD}  444 ${HORDEDIR}/config/horde.php3
	${CHMOD}  444 ${HORDEDIR}/setup.php3
.if !defined(WITH_PHP3)
# Enabling execution of .php3, in case you only run php4
	@(if [ -f ${MIMETYPES} ] ; then \
	    (if [ ! -f ${MIMETYPES}.beforeHorde ] ; then \
		${ECHO} "===> Updating mime.types..." ; \
		${CP} -p ${MIMETYPES} ${MIMETYPES}.beforeHorde ; \
		${ECHO_CMD} "" >> ${MIMETYPES} ; \
		${ECHO_CMD} "# Added by Horde to support php3" >> ${MIMETYPES} ; \
		(if ! ${GREP} -q x-httpd-php3 ${MIMETYPES} ; then \
		    ${ECHO_CMD} "application/x-httpd-php		phtml pht php php3" >> ${MIMETYPES} ; \
		    ${ECHO_CMD} "application/x-httpd-php3	php3.none" >> ${MIMETYPES} ; \
		fi) ; \
		${ECHO_CMD} "# End of Horde's additions." >> ${MIMETYPES} ; \
	    fi) ; \
	fi)
.endif
	@(if [ -f ${APACHE_CONF} ] ; then \
	    (if [ ! -f ${APACHE_CONF}.beforeHorde ] ; then \
		${ECHO} "===> Updating httpd.conf..." ; \
		${CP} -p ${MASTERDIR}/httpd.conf.phplib ${WRKDIR}/httpd.conf.phplib ; \
		${REINPLACE_CMD} -e "s:/home/httpd/html/horde:${HORDEDIR}:g ; \
			s:/home/httpd/phplib:${PHPLIBDIR}:g" ${WRKDIR}/httpd.conf.phplib ; \
		${CP} -p ${APACHE_CONF} ${APACHE_CONF}.beforeHorde ; \
		${GREP} -qw 'phplib' ${APACHE_CONF} || ${CAT} ${WRKDIR}/httpd.conf.phplib >> ${APACHE_CONF} ; \
	    fi) ; \
	fi)
	@if [ ! -f ${PHP_INI} ]; then \
		${ECHO_MSG} "===> Creating ${PHP_INI} for PHP" ; \
		${CP} ${PHP_INI}-dist ${PHP_INI} ; \
	fi
	@if ! ${GREP} -q -e '^upload_tmp_dir' ${PHP_INI} ; then \
		${ECHO_MSG} "===> Configuring ${PHP_INI} for imp" ; \
		${REINPLACE_CMD} -e 's!;upload_tmp_dir =!upload_tmp_dir = /tmp!' \
			${PHP_INI} ; \
		${MV} ${PHP_INI}.beforeHorde ${PHP_INI}.beforeHorde1 ; \
	fi
	${CHOWN} -R www:www ${HORDEDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO} "Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO} "*****************************************************************"
	@${ECHO} "Horde has been installed in ${HORDEDIR} with your blank"
	@${ECHO} "configuration files."
	@${ECHO} ""
	@${ECHO} "If ${APACHE_CONF} has been updated,"
	@${ECHO} "you have to restart Apache."
	@${ECHO} ""
	@${ECHO} "In order to end Horde's configuration, please read the"
	@${ECHO} "file ${PHPLIBDIR}/README."
	@${ECHO} "If you want Horde to access a database, you have to"
	@${ECHO} "configure ${PHPLIBDIR}/local.inc"
	@${ECHO} "and ${PHPLIBDIR}/prepend.php3"
	@${ECHO} "and you'll have to run the appropriate scripts located in"
	@${ECHO} "${HORDEDIR}/scripts/database"
	@${ECHO} ""
	@${ECHO} "Horde is setup by default to access MySQL."
	@${ECHO} ""
	@${ECHO} "It is recommended that you change the password of the 'hordemgr'"
	@${ECHO} "user used to connect to the horde database.  For localhost"
	@${ECHO} "security, the file ${PHPLIBDIR}/local.inc"
	@${ECHO} "should be accessible only to the webserver process as it contains"
	@${ECHO} "the horde database password."
	@${ECHO} ""
	@${ECHO} "When everything is OK, you should be able to access Horde from"
	@${ECHO} "<URL:http://localhost/horde/>."
	@${ECHO} "(If <URL:http://localhost/horde/> does not run, but"
	@${ECHO} " <URL:http://localhost/horde/index.php3> is OK, then you have"
	@${ECHO} " to define index.php3 as a DirectoryIndex in ${APACHE_CONF}.)"
	@${ECHO} ""
	@${ECHO} "The configuration utitility is located at"
	@${ECHO} "<URL:http://localhost/horde/setup.php3>"
	@${ECHO} "and there is a testing script at"
	@${ECHO} "<URL:http://localhost/horde/test.php3>."
	@${ECHO} ""
	@${ECHO} "The scripts horde_setup.sh and horde_secure.sh have been installed"
	@${ECHO} "in ${HORDESBIN}."
	@${ECHO} "*****************************************************************"

.include <bsd.port.mk>
