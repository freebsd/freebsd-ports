# Ports collection makefile for:  imp3
# Date created:			  Mon Oct 08, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	imp
PORTVERSION=	4.1.1
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.horde.org/pub/imp/				\
		ftp://ftp.planetmirror.com/pub/horde/imp/		\
		ftp://ftp.au.horde.org/pub/horde/imp/			\
		ftp://ftp.be.horde.org/imp/				\
		ftp://ftp.es.horde.org/pub/imp/				\
		http://ftp.horde.org/pub/imp/
DISTNAME=	${PORTNAME}-h3-${PORTVERSION}

MAINTAINER=	shaun@inerd.com
COMMENT=	A webmail system which accesses mail over IMAP

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_LDAP	: if you do not need OpenLDAP;
#
# - WITHOUT_SMIME	: disable S/MIME;
#
# - WITHOUT_SUPPORTED_DB: if you run a database not in the ports tree;
#
# - WITHOUT_ASPELL	: for spelling bees...
#
# - WITH_ISPELL		: if you prefer ispell;
#
# - NOCRYPT		: if crypto is restricted in your country;
#
# - WITHOUT_SSL		: if you have not installed c-client WITH_SSL;
#
# - WITH_VALID_CERT	: if you own a valid SSL certificate;
#
# - WITHOUT_INGO	: if you don't need filters management;
#
# - WITHOUT_NAG		: if you don't want tasks management;
#
# - WITHOUT_TURBA	: if you do not want adressbooks;
#
# - WITH_HTML		: enable HTML composition mode;
#
# - WITHOUT_IMAPSERVER	: if your IMAP server runs on another machine;
#
# or you can select to work with one of these servers:
#
# - WITH_CYRUS-IMAPD	: IMP will work with cyrus-imapd;
#
# - WITH_IMAP-UW	: IMP will work with imap-uw;
#
# - WITH_DOVECOT	: IMP will work with dovecot;
#
# - WITH_COURIER-IMAP	: IMP will work with courier-imap.
#
# These choices are mutually exclusive, and imap-uw is the default.
#
#-----------------------------------------------------------------------

RUN_DEPENDS+=	${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL

CONFLICTS=	imp-3.*

USE_PHP=	imap
.if defined(WITHOUT_TURBA)
. if !defined(WITHOUT_LDAP)
USE_PHP+=	ldap
. endif
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde
.else
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/turba/minisearch.php:${PORTSDIR}/mail/turba
.endif

.if !defined(WITHOUT_INGO)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/ingo/filters.php:${PORTSDIR}/mail/ingo
.endif

.if !defined(WITHOUT_NAG)
RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/nag/data.php:${PORTSDIR}/deskutils/nag
.endif

.if !defined(WITHOUT_SMIME)
USE_PHP+=	openssl
.endif

.if !defined(NOCRYPT)
RUN_DEPENDS+=	${LOCALBASE}/bin/gpg:${PORTSDIR}/security/gnupg
.endif

.if !defined(WITHOUT_ASPELL)
RUN_DEPENDS+=	${LOCALBASE}/bin/aspell:${PORTSDIR}/textproc/aspell
.elif defined(WITH_ISPELL)
RUN_DEPENDS+=	${LOCALBASE}/bin/ispell:${PORTSDIR}/textproc/ispell
.endif

.if defined(WITH_HTML)
RUN_DEPENDS+=	${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
.endif

NO_BUILD=	yes
USE_APACHE=	1.3+	# needed to test APACHE_VERSION
USE_GETTEXT=	yes
REINPLACE_ARGS=	-i.beforeIMP

DOCS=		COPYING README docs/CHANGES docs/CREDITS docs/INSTALL	\
		docs/RELEASE_NOTES  docs/TODO  docs/UPGRADING
CONFFILE=	filter.txt header.php menu.php mime_drivers.php motd.php \
		prefs.php servers.php trailer.txt
SUB_DIRS=	config js lib locale po scripts templates themes

LHORDEDIR?=	www/horde
LIMPDIR=	${LHORDEDIR}/imp
PEARDIR?=	${LOCALBASE}/share/pear

PLIST_SUB=	IMPDIR=${LIMPDIR} HORDE_INC=${HORDE_INC:S|^${LOCALBASE}/||}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	IMPDIR=${IMPDIR} PORTSDIR=${PORTSDIR} CONFDIR=${CONFDIR}

IMPDIR=		${PREFIX}/${LIMPDIR}
CONFDIR=	${IMPDIR}/config

HOSTNAME?=	`/bin/hostname`
SERVOS?=	${OPSYS}-${OSREL}

PORTREV_H?=	${LOCALBASE}/include/c-client/portrevision.h

PATCH2RM=	prefs.php.dist.orig servers.php.dist.orig conf.xml.orig	\
		conf.xml.beforeIMP servers.php.dist.beforeIMP

.include <bsd.port.pre.mk>

# I have no report about the support of dkimap4 by IMP,
# but I shall be happy to add it if someone report success with it.
# If an IMAP server is already installed, we just record the dependence,
# else we shall install imap-uw.
# IMAP servers are ordered according to my tastes, if several are
# installed, we just record the first one.
.if !defined(WITHOUT_IMAPSERVER)
. if defined(WITH_IMAP-UW) || exists(${LOCALBASE}/libexec/imapd)
RUN_DEPENDS+=	${LOCALBASE}/libexec/imapd:${PORTSDIR}/mail/imap-uw
. elif defined(WITH_CYRUS-IMAPD) || exists(${LOCALBASE}/lib/libacap.a)
RUN_DEPENDS+=	${LOCALBASE}/lib/libacap.a:${PORTSDIR}/mail/cyrus-imapd2
. elif defined(WITH_COURIER-IMAP) || exists(${LOCALBASE}/bin/deliverquota)
RUN_DEPENDS+=	${LOCALBASE}/bin/deliverquota:${PORTSDIR}/mail/courier-imap
. elif defined(WITH_DOVECOT) || exists(${LOCALBASE}/libexec/dovecot/imap)
RUN_DEPENDS+=	${LOCALBASE}/libexec/dovecot/imap:${PORTSDIR}/mail/dovecot
. else
RUN_DEPENDS+=	${LOCALBASE}/libexec/imapd:${PORTSDIR}/mail/imap-uw
. endif
.endif

.if ${APACHE_VERSION} >= 20
HORDE_INC=	${LOCALBASE}/etc/apache${APACHE_VERSION:S/20/2/}/Includes/
.else
HORDE_INC=	${LOCALBASE}/etc/horde/
.endif

pre-everything::
.if !defined(WITHOUT_IMAPSERVER)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press CTRL-C and define WITHOUT_IMAPSERVER"
	@${ECHO_MSG} "if you intend to run an IMAP server on an other machine."
	@${ECHO_MSG} ""
.endif

pre-configure:
	@${REINPLACE_CMD} -e "s:/usr/local:${LOCALBASE}:" ${WRKSRC}/config/conf.xml
.if !defined(WITHOUT_ASPELL)
	@${REINPLACE_CMD} -e "s:%%ASPELL%%:${LOCALBASE}/bin/aspell:" \
		${WRKSRC}/config/conf.xml
.elif defined(WITH_ISPELL)
	@${REINPLACE_CMD} -e "s:%%ASPELL%%:${LOCALBASE}/bin/ispell:" \
		${WRKSRC}/config/conf.xml
.else
	@${REINPLACE_CMD} -e "s:%%ASPELL%%::" ${WRKSRC}/config/conf.xml
.endif
.if !defined(NOCRYPT)
	@${REINPLACE_CMD} -e "s:%%GPG%%:${LOCALBASE}/bin/gpg:" \
		${WRKSRC}/config/conf.xml
.else
	@${REINPLACE_CMD} -e "s:%%GPG%%::" ${WRKSRC}/config/conf.xml
.endif
	@${REINPLACE_CMD} -e "s:IMP_VERSION:IMP_VERSION . ' / ${SERVOS}':"	\
		${WRKSRC}/lib/MIME/Headers.php
	@${REINPLACE_CMD} -e "s:example.com:${HOSTNAME}:g"	\
		${WRKSRC}/config/servers.php.dist
.if defined(WITHOUT_SSL)
	@${REINPLACE_CMD} -e "s:%%PROTOCOL%%:imap/notls:;s:%%IMAPPORT%%:143:"	\
		${WRKSRC}/config/servers.php.dist
.else
	@${REINPLACE_CMD} -e "s:%%IMAPPORT%%:993:" ${WRKSRC}/config/servers.php.dist
. if defined(WITH_VALID_CERT)
	@${REINPLACE_CMD} -e "s:%%PROTOCOL%%:imap/ssl:" ${WRKSRC}/config/servers.php.dist
. else
	@${REINPLACE_CMD} -e "s:%%PROTOCOL%%:imap/ssl/novalidate-cert:"	\
		${WRKSRC}/config/servers.php.dist
. endif
.endif
	@${SED} -e "s:/home/httpd/html/horde/imp:${IMPDIR}:"		\
		${FILESDIR}/httpd.conf.imp > ${WRKDIR}/httpd-imp.conf
.for fc in ${PATCH2RM}
	@${RM} ${WRKSRC}/config/${fc}
.endfor
	@${RM} ${WRKSRC}/lib/MIME/Headers.php.beforeIMP

pre-install:
.if !defined(BATCH) && !defined(WITHOUT_SSL)
	@if ! ${GREP} -q -e 'CCLIENT_SSLENABLED "yes"' ${PORTREV_H}; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure c-client with SSL support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.endif

do-install:
	@${MKDIR}  ${IMPDIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${IMPDIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${IMPDIR}

	@${INSTALL_DATA} ${WRKSRC}/config/conf.xml ${CONFDIR}
	@${INSTALL_DATA} ${WRKDIR}/httpd-imp.conf ${HORDE_INC}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${IMPDIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
