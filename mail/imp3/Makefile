# Ports collection makefile for:  imp3
# Date created:			  Mon Oct 08, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	imp
PORTVERSION=	3.2.2
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.horde.org/pub/imp/				\
		ftp://ftp.au.horde.org/pub/horde/imp/			\
		ftp://ftp.es.horde.org/pub/imp/				\
		ftp://ftp.it.horde.org/pub/mirror/horde.org/imp/	\
		ftp://ftp.nl.horde.org/mirror/horde-ftp/pub/imp/	\
		ftp://ftp.pt.horde.org/pub/horde-ftp/imp/

MAINTAINER=	thierry@pompo.net
COMMENT=	A webmail system which accesses mail over IMAP

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITH_APACHE2	: if you run Apache2;
#
# - WITHOUT_LDAP	: if you do not need OpenLDAP;
#
# - WITHOUT_SUPPORTED_DB: if you run a database not in the ports tree;
#
# - WITHOUT_WV		: if your users never receive MS-Word docs;
#
# - WITHOUT_XL		: if your users never receive MS-Excel sheets
#			  (or .ppt presentations);
#
# - WITHOUT_ZIP		: if not interested by zipinfo;
#
# - WITH_RAR		: if interested by rar (shareware archiver);
#
# - WITHOUT_ASPELL	: for spelling bees...
#
# - NOCRYPT		: if crypto is restricted in your country;
#
# - WITHOUT_SSL		: if you have not installed c-client WITH_SSL;
#
# - WITH_VALID_CERT	: if you own a valid SSL certificate;
#
# - WITHOUT_TURBA	: if you do not want adressbooks;
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
# These choices are mutually exclusive, and imap-uw is the default.
#
#-----------------------------------------------------------------------

.if defined(WITHOUT_TURBA)
.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=	yes
.endif
RUN_DEPENDS+=	${LOCALBASE}/www/horde/index.php:${PORTSDIR}/www/horde2
NOTURBA=	"@comment "
.else
RUN_DEPENDS+=	${LOCALBASE}/www/horde/turba/index.php:${PORTSDIR}/mail/turba
.endif

# Support of GnuPG is not implemented in this release
#.if !defined(NOCRYPT)
#RUN_DEPENDS+=	${LOCALBASE}/bin/gpg:${PORTSDIR}/security/gnupg
#.endif

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

.if !defined(WITHOUT_X11)
.if !defined(WITHOUT_WV)
RUN_DEPENDS+=	${LOCALBASE}/bin/wvHtml:${PORTSDIR}/textproc/wv
.endif
.if !defined(WITHOUT_XL)
RUN_DEPENDS+=	${LOCALBASE}/bin/xlhtml:${PORTSDIR}/textproc/xlhtml
.endif
.if !defined(WITHOUT_ZIP)
RUN_DEPENDS+=	${LOCALBASE}/bin/zipinfo:${PORTSDIR}/archivers/unzip
.endif
.if defined(WITH_RAR)
RUN_DEPENDS+=	${LOCALBASE}/bin/rar:${PORTSDIR}/archivers/rar
.endif
.if !defined(WITHOUT_ASPELL)
RUN_DEPENDS+=	${LOCALBASE}/bin/aspell:${PORTSDIR}/textproc/aspell
.endif
.endif

NO_BUILD=	yes
USE_REINPLACE=	yes

LDD=		/usr/bin/ldd

REINPLACE_ARGS=	-i.beforeIMP
DOCS=		COPYING README docs/CHANGES docs/CREDITS docs/INSTALL
CONFFILE=	conf.php filter.txt header.txt html.php menu.php \
		mime_drivers.php motd.php prefs.php servers.php \
		trailer.txt
SUB_DIRS=	config download graphics lib locale po scripts templates

LHORDEDIR?=	www/horde
LIMPDIR?=	${LHORDEDIR}/imp
HORDESBIN?=	${PREFIX}/sbin

PLIST_SUB=	HORDEDIR=${LHORDEDIR} IMPDIR=${LIMPDIR} TURBA=${NOTURBA}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
IMPDIR=		${PREFIX}/${LIMPDIR}
TURBADIR?=	${HORDEDIR}/turba
CONFDIR=	${IMPDIR}/config
HCONFDIR=	${HORDEDIR}/config

HORDE_INC=	${LOCALBASE}/etc/horde
.if defined(WITH_APACHE2)
PHPSO=		${LOCALBASE}/libexec/apache2/libphp4.so
.else
PHPSO=		${LOCALBASE}/libexec/apache/libphp4.so
.endif

HOSTNAME?=	`/bin/hostname`
SERVOS?=	${OPSYS}-${OSREL}

PORTREV_H?=	${LOCALBASE}/include/c-client/portrevision.h

# Where you want to store the public keyrings needed for gpg
# (in a subdirectory in that directory called .gnupg)
GNUPG_CNFDIR?=	${LOCALBASE}/etc

pre-everything::
.if !defined(WITHOUT_IMAPSERVER)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press CTRL-C and define WITHOUT_IMAPSERVER"
	@${ECHO_MSG} "if you intend to run an IMAP server on an other machine."
	@${ECHO_MSG} ""
.endif

post-patch:
	@${RM} ${WRKSRC}/config/prefs.php.dist.orig
	@${RM} ${WRKSRC}/config/servers.php.dist.orig

pre-install:
# N.B.: database dependencies are binded with mod_php#, neither by Horde nor IMP.
	@if [ -f ${IMPDIR}/index.php3 ]; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please deinstall the port mail/imp." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
	@if ! ${LDD} ${PHPSO} | ${GREP} -q -e "libc-client4"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with IMAP or IMAP-SSL support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.if !defined(BATCH)
.if !defined(WITHOUT_SSL)
	@if ! ${GREP} -q -e 'CCLIENT_SSLENABLED "yes"' ${PORTREV_H}; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure c-client with SSL support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.endif
.endif
.if !defined(WITHOUT_LDAP)
	@if ! ${LDD} ${PHPSO} | ${GREP} -q -e "libldap.so"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with OpenLDAP or OpenLDAP2 support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.endif
.if !defined(NOCRYPT)
	@if ! ${LDD} ${PHPSO} | ${GREP} -q -e "libmcrypt.so"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with mcrypt support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.endif
.if !defined(WITHOUT_SUPPORTED_DB)
	@if ! ${LDD} ${PHPSO} | ${GREP} -q -e "libmysqlclient.so"; then \
	 if ! ${LDD} ${PHPSO} | ${GREP} -q -e "libpq.so" ; then \
	  if ! ${LDD} ${PHPSO} | ${GREP} -q -e "libsybdb.so" ; then \
	   if ! ${LDD} ${PHPSO} | ${GREP} -q -e "libct.so" ; then \
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
	@${MKDIR}  ${IMPDIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${IMPDIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${IMPDIR}
.for FILE in ${CONFFILE}
	@if [ ! -f ${CONFDIR}/${FILE} ]; then \
	  ${CP} ${CONFDIR}/${FILE}.dist ${CONFDIR}/${FILE} ; \
	fi
.endfor
	@${CP} -p ${HCONFDIR}/mime_drivers.php ${HCONFDIR}/mime_drivers.php.beforeIMP3
	@${CP} -p ${HCONFDIR}/registry.php ${HCONFDIR}/registry.php.beforeIMP3
.if !defined(WITHOUT_TURBA)
	@${CP} -p ${TURBADIR}/config/conf.php ${TURBADIR}/config/conf.php.beforeIMP3
.endif
	@${REINPLACE_CMD} -e "s:example.com:${HOSTNAME}:g" ${CONFDIR}/servers.php
	@${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:g" ${CONFDIR}/mime_drivers.php
	@${RM} ${CONFDIR}/mime_drivers.php.beforeIMP
	@${REINPLACE_CMD} -e "s:IMP_VERSION:IMP_VERSION . ' / ${SERVOS}':" \
		${IMPDIR}/compose.php
	@${RM} ${IMPDIR}/compose.php.beforeIMP
.if defined(WITHOUT_SSL)
	@${REINPLACE_CMD} -e "s:%%PROTOCOL%%:imap/notls:;s:%%IMAPPORT%%:143:" \
		${CONFDIR}/servers.php
.else
	@${REINPLACE_CMD} -e "s:%%IMAPPORT%%:993:" ${CONFDIR}/servers.php
.if defined(WITH_VALID_CERT)
	@${REINPLACE_CMD} -e "s:%%PROTOCOL%%:imap/ssl:" ${CONFDIR}/servers.php
.else
	@${REINPLACE_CMD} -e "s:%%PROTOCOL%%:imap/ssl/novalidate-cert:" \
		${CONFDIR}/servers.php
.endif
	@${RM} ${CONFDIR}/servers.php.beforeIMP
.endif
.if !defined(WITHOUT_ASPELL)
	@${REINPLACE_CMD} -e "s:spellchecker'] = '':spellchecker'] = '${LOCALBASE}/bin/aspell':" \
		${CONFDIR}/conf.php
.endif
.if !defined(WITHOUT_X11)
.if !defined(WITHOUT_WV)
	@${REINPLACE_CMD} -e "s://UNCOMMENTIFWV ::" ${HCONFDIR}/mime_drivers.php
.endif
.if !defined(WITHOUT_XL)
	@${REINPLACE_CMD} -e "s://UNCOMMENTIFXL ::" ${HCONFDIR}/mime_drivers.php
.endif
.endif
#.if !defined(NOCRYPT)
#	@(if [ ! -d ${GNUPG_CNFDIR} ] ; then \
#		${MKDIR} ${GNUPG_CNFDIR} ; \
#	fi)
#	@${REINPLACE_CMD} -e "s:pgp']['enabled'] = false:pgp']['enabled'] = true:g" \
#			${CONFDIR}/conf.php
#	@${REINPLACE_CMD} -e "s:%%GNUPG_CNFDIR%%:${GNUPG_CNFDIR}:" \
#			${CONFDIR}/conf.php
#.endif
.if !defined(WITHOUT_ZIP)
	@${REINPLACE_CMD} -e "s://UNCOMMENTIFZIP ::" ${HCONFDIR}/mime_drivers.php
.endif
.if defined(WITH_RAR)
	@${REINPLACE_CMD} -e "s://UNCOMMENTIFRAR ::" ${HCONFDIR}/mime_drivers.php
.endif
	@${CHOWN} -R www:www ${IMPDIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${CP} -p ${FILESDIR}/httpd.conf.imp ${HORDE_INC}/httpd.conf.imp
	@${REINPLACE_CMD} -e "s:/home/httpd/html/horde/imp:${IMPDIR}:g" ${HORDE_INC}/httpd.conf.imp
	@${RM} ${HORDE_INC}/httpd.conf.imp.beforeIMP
# Let's Horde use IMP for auth
	@${REINPLACE_CMD} -e "s://UNCOMMENTWHENINSTIMP::" ${HCONFDIR}/registry.php
# Provide a link to IMP from Turba
.if !defined(WITHOUT_TURBA)
	@${REINPLACE_CMD} -e "s://UNCOMMENTWHENINSTIMP::" ${TURBADIR}/config/conf.php
	@${REINPLACE_CMD} -e "s:apps'] = array():apps'] = array('turba'):" \
		${CONFDIR}/conf.php
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif
# Prepare deinstallation
	@${RM} ${CONFDIR}/conf.php.beforeIMP
	@${MV} ${HCONFDIR}/mime_drivers.php.beforeIMP3 ${HCONFDIR}/mime_drivers.php.beforeIMP
	@${MV} ${HCONFDIR}/registry.php.beforeIMP3 ${HCONFDIR}/registry.php.beforeIMP
	@${CP} -p ${HCONFDIR}/mime_drivers.php ${HCONFDIR}/mime_drivers.php.afterIMP
	@${CP} -p ${HCONFDIR}/registry.php ${HCONFDIR}/registry.php.afterIMP
.if !defined(WITHOUT_TURBA)
	@${MV} ${TURBADIR}/config/conf.php.beforeIMP3 ${TURBADIR}/config/conf.php.beforeIMP
	@${CP} -p ${TURBADIR}/config/conf.php ${TURBADIR}/config/conf.php.afterIMP
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | \
	${SED} -e "s:%%IMPDIR%%:${IMPDIR}:g;s:%%PORTSDIR%%:${PORTSDIR}:g;s:%%CONFDIR%%:${CONFDIR}:g;s:%%DOCSDIR%%:${DOCSDIR}:g"
	@${ECHO_MSG}

.include <bsd.port.mk>
