# Ports collection makefile for:  imp-devel
# Date created:			  Mon Oct 08, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	imp
PORTVERSION=	3.0
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.horde.org/pub/imp/tarballs/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION}-RC3

MAINTAINER=	thierry@thomas.as

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_LDAP	: if you do not need OpenLDAP;
# - WITH_LDAP1		: if you prefer OpenLDAP1.
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
# - WITHOUT_ASPELL	: for spelling bees...
#
# - NOCRYPT		: if crypto is restricted in your country;
#
# - WITHOUT_SSL		: if you have not installed c-client WITH_SSL;
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
# These choice are mutually exclusive, and imap-uw is the default.
#
#-----------------------------------------------------------------------

LIB_DEPENDS=	c-client4.8:${PORTSDIR}/mail/cclient

.if defined(WITHOUT_TURBA)
.if !defined(WITHOUT_LDAP)
.if defined(WITH_LDAP1)
LIB_DEPENDS+=	ldap.1:${PORTSDIR}/net/openldap \
		lber.1:${PORTSDIR}/net/openldap
.else
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/net/openldap2 \
		lber.2:${PORTSDIR}/net/openldap2
.endif
.endif
RUN_DEPENDS+=	${LOCALBASE}/www/horde/index.php:${PORTSDIR}/www/horde${PKGNAMESUFFIX}
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
RUN_DEPENDS+=	${LOCALBASE}/bin/xlHtml:${PORTSDIR}/textproc/xlhtml
.endif
.if !defined(WITHOUT_ZIP)
RUN_DEPENDS+=	${LOCALBASE}/bin/zipinfo:${PORTSDIR}/archivers/unzip
.endif
.if !defined(WITHOUT_ASPELL)
RUN_DEPENDS+=	${LOCALBASE}/bin/aspell:${PORTSDIR}/textproc/aspell
.endif
.endif

NO_BUILD=	yes
DOCS=		COPYING README docs/CHANGES docs/CREDITS \
		docs/INSTALL docs/SECURITY docs/FEATURES \
		docs/PACKAGES
CONFFILE=	conf.php filter.txt header.txt html.php menu.php \
		mime_drivers.php motd.php prefs.php servers.php \
		trailer.txt

LHORDEDIR?=	www/horde
LIMPDIR?=	${LHORDEDIR}/imp
HORDESBIN?=	${PREFIX}/sbin

PLIST_SUB=	HORDEDIR=${LHORDEDIR} IMPDIR=${LIMPDIR}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
IMPDIR=		${PREFIX}/${LIMPDIR}
TURBADIR?=	${HORDEDIR}/turba
CONFDIR=	${IMPDIR}/config

HORDE_INC=	${LOCALBASE}/etc/horde

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

pre-install:
# N.B.: database dependencies are binded with mod_php#, neither by Horde nor IMP.
	@if [ -f ${IMPDIR}/index.php3 ]; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please deinstall the port mail/imp." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "c-client4.8"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with IMAP or IMAP-SSL support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.if !defined(WITHOUT_SSL)
	@if ! ${GREP} -q -e 'CCLIENT_SSLENABLED "yes"' ${PORTREV_H}; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure c-client with SSL support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.endif
.if !defined(WITHOUT_LDAP)
.if defined(WITH_LDAP1)
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "ldap.1"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with OpenLDAP support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.else
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "ldap.2"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with OpenLDAP2 support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.endif
.endif
.if !defined(NOCRYPT)
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "mcrypt.6"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with mcrypt support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.endif
.if !defined(WITHOUT_ASPELL)
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "pspell.4"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with pspell support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
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
	@${MKDIR}  ${IMPDIR}
	@${CP} -Rp ${WRKSRC}/config ${WRKSRC}/graphics ${WRKSRC}/lib ${IMPDIR}
	@${CP} -Rp ${WRKSRC}/locale ${WRKSRC}/scripts ${WRKSRC}/templates ${IMPDIR}
	@${CP} -Rp ${WRKSRC}/po ${IMPDIR}
	@${CP} -p  ${WRKSRC}/*.php ${IMPDIR}
.for FILE in ${CONFFILE}
	@if [ ! -f ${CONFDIR}/${FILE} ]; then \
	  ${CP} ${CONFDIR}/${FILE}.dist ${CONFDIR}/${FILE} ; \
	fi
.endfor
	@${PERL} -pi -e "s:example.com:${HOSTNAME}:g" ${CONFDIR}/servers.php
	@${PERL} -pi -e "s:%%LOCALBASE%%:${LOCALBASE}:g" ${CONFDIR}/mime_drivers.php
	@${PERL} -pi -e "s:IMP_VERSION:IMP_VERSION . ' / ${SERVOS}':" ${IMPDIR}/compose.php
.if !defined(WITHOUT_ASPELL)
	@${PERL} -pi -e "s:\/\* BEGBSDASPELL::;s:ENDBSDASPELL \*\/::" \
			${CONFDIR}/mime_drivers.php
	@${PERL} -pi -e "s:spellchecker'] = '':spellchecker'] = 'true':" \
		${CONFDIR}/conf.php
.endif
.if !defined(WITHOUT_X11)
.if !defined(WITHOUT_WV)
	@${PERL} -pi -e "s:\/\* BEGBSDWV::;s:ENDBSDWV \*\/::" ${CONFDIR}/mime_drivers.php
.endif
.if !defined(WITHOUT_XL)
	@${PERL} -pi -e "s:\/\* BEGBSDXL::;s:ENDBSDXL \*\/::g" ${CONFDIR}/mime_drivers.php
.endif
.endif
#.if !defined(NOCRYPT)
#	@(if [ ! -d ${GNUPG_CNFDIR} ] ; then \
#		${MKDIR} ${GNUPG_CNFDIR} ; \
#	fi)
#	@${PERL} -pi -e "s:pgp']['enabled'] = false:pgp']['enabled'] = true:g" \
#			${CONFDIR}/conf.php
#	@${PERL} -pi -e "s:%%GNUPG_CNFDIR%%:${GNUPG_CNFDIR}:" \
#			${CONFDIR}/conf.php
#.endif
.if !defined(WITHOUT_ZIP)
	@${PERL} -pi -e "s:\/\* BEGBSDZIP::;s:ENDBSDZIP \*\/::" ${CONFDIR}/mime_drivers.php
.endif
	@${CHOWN} -R www:www ${IMPDIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${CP} -p ${FILESDIR}/httpd.conf.imp ${HORDE_INC}/httpd.conf.imp
	@${PERL} -pi -e "s:/home/httpd/html/horde/imp:${IMPDIR}:g" ${HORDE_INC}/httpd.conf.imp
# Let's Horde use IMP for auth
	@${PERL} -pi -e "s://UNCOMMENTWHENINSTIMP::" ${HORDEDIR}/config/registry.php
# Provide a link to IMP from Turba
.if !defined(WITHOUT_TURBA)
	@${PERL} -pi -e "s://UNCOMMENTWHENINSTIMP::" ${TURBADIR}/config/conf.php
.endif
.if !defined(NOPORTDOCS)
	@${PERL} -pi -e "s:/home/httpd/html/horde/imp:${IMPDIR}:g" ${WRKSRC}/docs/SECURITY
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | \
	${SED} -e "s:%%IMPDIR%%:${IMPDIR}:g;s:%%PORTSDIR%%:${PORTSDIR}:g;s:%%CONFDIR%%:${CONFDIR}:g;s:%%DOCSDIR%%:${DOCSDIR}:g"
	@${ECHO_MSG}

.include <bsd.port.mk>
