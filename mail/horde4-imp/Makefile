# Ports collection makefile for:  imp
# Date created:			  Sun Jul 08, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
# N.B.: parts of this ports come from the Horde's port by NetBSD (jlam@netbsd.org)
#
# $FreeBSD$
#

PORTNAME=	imp
PORTVERSION=	2.2.7
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.horde.org/pub/imp/tarballs/

MAINTAINER=	thierry@pompo.net

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_LDAP	: if you do not need OpenLDAP;
# - WITH_LDAP2		: if you prefer OpenLDAP2.
#
# - WITHOUT_SUPPORTED_DB: if you run a database not in the ports tree;
#
# - WITHOUT_WV		: if your users never receive MS-Word docs;
#
# - WITHOUT_XL		: if your users never receive MS-Excel sheets;
#
# - WITHOUT_ZIP		: if not interested by zipinfo;
#
# - WITHOUT_ISPELL	: for spelling bees...
#
# - WITHOUT_IMAPSERVER	: if your IMAP server runs on another machine;
#
# or you can select to work with one of these servers:
#
# - WITH_CYRUS-IMAPD	: IMP will work with cyrus-imapd;
#
# - WITH_CYRUS		: IMP will work with cyrus;
#
# - WITH_IMAP-UW	: IMP will work with imap-uw;
#
# - WITH_COURIER-IMAP	: IMP will work with courier-imap.
#
# These choice are mutually exclusive, and imap-uw is the default.
#
#-----------------------------------------------------------------------

LIB_DEPENDS=	c-client4.8:${PORTSDIR}/mail/cclient

.if !defined(WITHOUT_LDAP)
.if defined(WITH_LDAP2)
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/net/openldap2 \
		lber.2:${PORTSDIR}/net/openldap2
.else
LIB_DEPENDS+=	ldap.1:${PORTSDIR}/net/openldap \
		lber.1:${PORTSDIR}/net/openldap
.endif
.endif

RUN_DEPENDS+=	${LOCALBASE}/www/horde/index.php3:${PORTSDIR}/www/horde

# I have no report about the support of dkimap4 by IMP,
# but I shall be happy to add it if somebody report success with it.
# If an IMAP server is already installed, we just record the dependence,
# else we shall install imap-uw.
# IMAP servers are ordered according to my tastes, if several are
# installed, we just record the first one.
.if !defined(WITHOUT_IMAPSERVER)
.if defined(WITH_IMAP-UW)
RUN_DEPENDS+=	${LOCALBASE}/libexec/imapd:${PORTSDIR}/mail/imap-uw
.elif defined(WITH_CYRUS-IMAPD)
RUN_DEPENDS+=	${LOCALBASE}/lib/libacap.a:${PORTSDIR}/mail/cyrus-imapd
.elif defined(WITH_CYRUS)
RUN_DEPENDS+=	${LOCALBASE}/cyrus/:${PORTSDIR}/mail/cyrus
.elif defined(WITH_COURIER-IMAP)
RUN_DEPENDS+=	${LOCALBASE}/libexec/courier-imap/:${PORTSDIR}/mail/courier-imap
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/imapd:${PORTSDIR}/mail/imap-uw
.endif
.endif

.if !defined(WITHOUT_WV)
RUN_DEPENDS+=	${LOCALBASE}/bin/wvHtml:${PORTSDIR}/textproc/wv
.endif
.if !defined(WITHOUT_XL)
RUN_DEPENDS+=	${LOCALBASE}/bin/xlHtml:${PORTSDIR}/textproc/xlhtml
.endif
.if !defined(WITHOUT_ZIP)
RUN_DEPENDS+=	${LOCALBASE}/bin/zipinfo:${PORTSDIR}/archivers/unzip
.endif
.if !defined(WITHOUT_ISPELL)
RUN_DEPENDS+=	${LOCALBASE}/bin/ispell:${PORTSDIR}/textproc/ispell
.endif

NO_BUILD=	yes
DOCS=		COPYING README docs/CHANGES docs/CREDITS docs/DATABASE \
		docs/HELP docs/INSTALL docs/SECURITY docs/KNOWN_BUGS \
		docs/PACKAGES

LHORDEDIR?=	www/horde
LIMPDIR?=	${LHORDEDIR}/imp
HORDESBIN?=	${PREFIX}/sbin

PLIST_SUB=	HORDEDIR=${LHORDEDIR} IMPDIR=${LIMPDIR}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
IMPDIR=		${PREFIX}/${LIMPDIR}

APACHE_CNFDIR?=	${LOCALBASE}/etc/apache
APACHE_CONF=	${APACHE_CNFDIR}/httpd.conf

pre-everything::
.if !defined(WITHOUT_IMAPSERVER)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press CTRL-C and define WITHOUT_IMAPSERVER"
	@${ECHO_MSG} "if you intend to run an IMAP server on an other machine."
	@${ECHO_MSG} ""
.endif

pre-install:
# N.B.: database dependencies are binded with mod_php#, neither by Horde nor IMP.
	@if [ -f ${IMPDIR}/index.php ]; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please deinstall the port mail/imp-devel." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "c-client4.8"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with IMAP support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.if !defined(WITHOUT_LDAP)
.if defined(WITH_LDAP2)
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "ldap.2"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with OpenLDAP2 support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.else
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "ldap.1"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with OpenLDAP support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.endif
.endif
.if !defined(WITHOUT_SUPPORTED_DB)
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "mysqlclient.10" ; then \
	 if ! ${LDCONFIG} -r | ${GREP} -q -e "pq.2" ; then \
	  if ! ${LDCONFIG} -r | ${GREP} -q -e "sybdb.1" ; then \
	   if ! ${LDCONFIG} -r | ${GREP} -q -e "ct.0" ; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with a database support." ; \
	    ${ECHO_MSG} "MySQL, PostgreSQL and Sybase (CTLIB or DBLIB)" ; \
	    ${ECHO_MSG} "can be used with PHP AND IMP." ; \
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
	${MKDIR}  ${IMPDIR}
	${CP} -Rp ${WRKSRC}/config ${WRKSRC}/graphics ${WRKSRC}/lib ${IMPDIR}
	${CP} -Rp ${WRKSRC}/locale ${WRKSRC}/scripts ${WRKSRC}/templates ${IMPDIR}
	${CP} -p  ${WRKSRC}/*.php3 ${WRKSRC}/*.css ${IMPDIR}
	${PERL} -pi -e "s:/usr/bin/ispell:${LOCALBASE}/bin/ispell:g" \
			${IMPDIR}/config/defaults.php3.dist
	${PERL} -pi -e "s:/usr/bin/wvHtml:${LOCALBASE}/bin/wvHtml:g" \
			${IMPDIR}/config/defaults.php3.dist
	${PERL} -pi -e "s:/usr/bin/xlHtml:${LOCALBASE}/bin/xlHtml:g" \
			${IMPDIR}/config/defaults.php3.dist
	${PERL} -pi -e "s:/bin/tar:/usr/bin/tar:g" ${IMPDIR}/config/defaults.php3.dist
	${PERL} -pi -e "s:/usr/bin/zipinfo:${LOCALBASE}/bin/zipinfo:g" \
			${IMPDIR}/config/defaults.php3.dist
	${PERL} -pi -e "s:sh ./secure.sh:${HORDESBIN}/horde_secure.sh:g" \
			${IMPDIR}/templates/index/imp_notconfigured.inc
	${PERL} -pi -e "s:sh ./install.sh:${HORDESBIN}/horde_setup.sh:g" \
			${IMPDIR}/templates/index/imp_notconfigured.inc
	${PERL} -pi -e "s:sh ./secure.sh:${HORDESBIN}/horde_secure.sh:g" \
			${HORDEDIR}/templates/setup/imp/write_file.inc
	@if [ ! -f ${IMPDIR}/config/defaults.php3 ]; then \
	    ${CP}     ${IMPDIR}/config/defaults.php3.dist ${IMPDIR}/config/defaults.php3; \
	fi
	${CHMOD}  777 ${IMPDIR}/config/defaults.php3
	@if [ ! -f ${IMPDIR}/config/mime.php3 ]; then \
	    ${CP}     ${IMPDIR}/config/mime.php3.dist ${IMPDIR}/config/mime.php3; \
	fi
	@if [ ! -f ${IMPDIR}/config/ldap.php3 ]; then \
	    ${CP}     ${IMPDIR}/config/ldap.php3.dist ${IMPDIR}/config/ldap.php3; \
	fi
	@if [ ! -f ${IMPDIR}/config/servers.php3 ]; then \
	    ${CP}     ${IMPDIR}/config/servers.php3.dist ${IMPDIR}/config/servers.php3; \
	fi
	${CHOWN} -R www:www ${IMPDIR}
	${CHMOD}  444 ${HORDEDIR}/setup.php3
	@(if [ -f ${APACHE_CONF} ] ; then \
	   (if [ ! -f ${APACHE_CONF}.beforeIMP ] ; then \
		${ECHO} "===> Updating ${APACHE_CONF}..." ; \
		${CP} -p ${.CURDIR}/httpd.conf.imp ${WRKDIR}/httpd.conf.imp ; \
		${PERL} -pi -e "s:/home/httpd/html/horde/imp:${IMPDIR}:g" \
			${WRKDIR}/httpd.conf.imp ; \
		${CP} -p ${APACHE_CONF} ${APACHE_CONF}.beforeIMP ; \
		${GREP} -qw 'Added for IMP' ${APACHE_CONF} || ${CAT} ${WRKDIR}/httpd.conf.imp \
			>> ${APACHE_CONF} ; \
	    fi) ; \
	fi)
.if !defined(NOPORTDOCS)
	${PERL} -pi -e "s:/home/httpd/html/horde/imp:${IMPDIR}:g" ${WRKSRC}/docs/SECURITY
	${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO} "Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO} "******************************************************************"
	@${ECHO} "IMP has been installed in ${IMPDIR} with your blank"
	@${ECHO} "configuration files."
	@${ECHO} ""
	@${ECHO} "Please refer to the file ${DOCSDIR}/SECURITY"
	@${ECHO} "on how to secure the IMP installation."
	@${ECHO} "It is at least recommended that you change the default database"
	@${ECHO} "password used by horde-phplib and imp."
	@${ECHO} ""
	@${ECHO} "In order to end IMP's configuration, please read the"
	@${ECHO} "file ${DOCSDIR}/INSTALL."
	@${ECHO} ""
	@${ECHO} "If ${APACHE_CONF} has been updated,"
	@${ECHO} "you have to restart Apache."
	@${ECHO} ""
	@${ECHO} "The configuration utitility is located at"
	@${ECHO} "<URL:http://localhost/horde/setup.php3>".
	@${ECHO} ""
	@${ECHO} "IMP requires an IMAP server. If you want to install one on this"
	@${ECHO} "machine, you may install the ports mail/cyrus-imapd, or"
	@${ECHO} "mail/imap-uw, or mail/courier-imap."
	@${ECHO} ""
	@${ECHO} "IMP uses c-client (from the port mail/cclient), the client of"
	@${ECHO} "IMAP-UW; you may want to reinstall it with SSL support, or"
	@${ECHO} "if you need an SSL connection to your IMAP server, you can"
	@${ECHO} "install the port security/stunnel."
	@${ECHO} "******************************************************************"

.include <bsd.port.mk>
