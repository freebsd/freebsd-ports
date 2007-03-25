# Ports collection makefile for:	mimp3
# Date created:			Mon Feb 05, 2007
# Whom:				Beech Rintoul <beech@alaskaparadise.com>
#
# $FreeBSD$
#

PORTNAME=	mimp
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	h3-
CATEGORIES=	mail www
MASTER_SITES=	HORDE

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	Mobile webmail system

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_LDAP	if you do not need OpenLDAP;
#
# - WITHOUT_SMIME	disable S/MIME;
#
# - WITHOUT_SUPPORTED_DB	if you run a database not in the ports tree;
#
# - NOCRYPT	if crypto is restricted in your country;
#
# - WITHOUT_SSL	if you have not installed c-client WITH_SSL;
#
# - WITH_VALID_CERT	if you own a valid SSL certificate;
#
# - WITH_IMAPSERVER	if you want to depend on an IMAP server;
#
# or you can select to work with one of these servers:
#
# - WITH_CYRUS-IMAPD	MIMP will work with cyrus-imapd;
#
# - WITH_IMAP-UW		MIMP will work with imap-uw;
#
# - WITH_DOVECOT	 MIMP will work with dovecot;
#
# - WITH_COURIER-IMAP	MIMP will work with courier-imap.
#
# These choices are mutually exclusive, and imap-uw is the default.
#
#-----------------------------------------------------------------------

RUN_DEPENDS+=	${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL

USE_PHP=	imap
. if !defined(WITHOUT_LDAP)
USE_PHP+=	ldap
. endif

RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde-base

.if !defined(WITHOUT_SMIME)
USE_PHP+=	openssl
.endif

.if !defined(NOCRYPT)
RUN_DEPENDS+=	${LOCALBASE}/bin/gpgv:${PORTSDIR}/security/gnupg1
.endif

NO_BUILD=	yes
USE_APACHE=	1.3+	# needed to test APACHE_VERSION
USE_GETTEXT=	yes
REINPLACE_ARGS=	-i.beforeMIMP

PORTDOCS=	README CHANGES CREDITS INSTALL RELEASE_NOTES
CONFFILE=	filter.txt header.php menu.php mime_drivers.php motd.php \
		prefs.php servers.php trailer.txt conf.xml .htaccess
SUB_DIRS=	config lib locale po templates themes

LHORDEDIR?=	www/horde
LMIMPDIR=	${LHORDEDIR}/mimp
PEARDIR?=	${LOCALBASE}/share/pear

PLIST_SUB=	MIMPDIR=${LMIMPDIR} HORDE_INC=${HORDE_INC:S|^${LOCALBASE}/||}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	MIMPDIR=${MIMPDIR} PORTSDIR=${PORTSDIR} CONFDIR=${CONFDIR}

MIMPDIR=	${PREFIX}/${LMIMPDIR}
CONFDIR=	${MIMPDIR}/config

HOSTNAME?=	`/bin/hostname`
SERVOS?=	${OPSYS}-${OSREL}

PORTREV_H?=	${LOCALBASE}/include/c-client/portrevision.h

PATCH2RM=	prefs.php.dist.orig servers.php.dist.orig

.include <bsd.port.pre.mk>

.if defined(WITH_IMAPSERVER)
. if defined(WITH_IMAP-UW) || exists(${LOCALBASE}/libexec/imapd)
RUN_DEPENDS+=	${LOCALBASE}/libexec/imapd:${PORTSDIR}/mail/imap-uw
. elif defined(WITH_CYRUS-IMAPD) || exists(${LOCALBASE}/cyrus/bin/master)
RUN_DEPENDS+=	${LOCALBASE}/cyrus/bin/master:${PORTSDIR}/mail/cyrus-imapd23
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

post-extract:
	@${MV} ${WRKSRC}/README ${WRKSRC}/docs/

pre-configure:
	@${REINPLACE_CMD} -e "s:/usr/local:${LOCALBASE}:" ${WRKSRC}/config/conf.xml
.if !defined(NOCRYPT)
	@${REINPLACE_CMD} -e "s:%%GPG%%:${LOCALBASE}/bin/gpg:" \
		${WRKSRC}/config/conf.xml
.else
	@${REINPLACE_CMD} -e "s:%%GPG%%::" ${WRKSRC}/config/conf.xml
.endif
	@${REINPLACE_CMD} -e "s:MIMP_VERSION:MIMP_VERSION . ' / ${SERVOS}':" \
		${WRKSRC}/lib/MIME/Headers.php
	@${REINPLACE_CMD} -e "s:example.com:${HOSTNAME}:g"	\
		${WRKSRC}/config/servers.php.dist
.if defined(WITHOUT_SSL)
	@${REINPLACE_CMD} -e "s:%%PROTOCOL%%:imap/notls:;s:%%IMAPPORT%%:143:"
\
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
	@${SED} -e "s:/home/httpd/html/horde/mimp:${MIMPDIR}:" \
		${FILESDIR}/httpd.conf.mimp > ${WRKDIR}/httpd-mimp.conf

pre-install:
.if !defined(BATCH) && !defined(WITHOUT_SSL)
	@if ! ${GREP} -q -e 'CCLIENT_SSLENABLED "yes"' ${PORTREV_H}; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure c-client with SSL support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.endif
.for fc in ${PATCH2RM}
	@${RM} ${WRKSRC}/config/${fc}
.endfor

do-install:
	@${INSTALL} -d ${MIMPDIR}/
	@${CP} -Rp ${SUB_DIRS:S|^|${WRKSRC}/|} ${MIMPDIR}/
	@${CP} -p ${WRKSRC}/*.php ${MIMPDIR}/
	@${INSTALL_DATA} ${WRKSRC}/config/conf.xml ${CONFDIR}/
	@${INSTALL_DATA} ${WRKDIR}/httpd-mimp.conf ${HORDE_INC}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${MIMPDIR}/
	@${CHMOD} -R o-rwx ${CONFDIR}/
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
