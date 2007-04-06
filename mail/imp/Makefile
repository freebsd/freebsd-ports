# Ports collection makefile for:  imp3
# Date created:			  Mon Oct 08, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	imp
PORTVERSION=	4.1.4
DISTVERSIONPREFIX=	h3-
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	HORDE

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	Webmail system for IMAP/POP3 mailboxes

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
# - WITH_HTML		: enable HTML composition mode;
#-----------------------------------------------------------------------

RUN_DEPENDS+=	${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL

CONFLICTS=	imp-3.*

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

.if !defined(WITHOUT_ASPELL)
RUN_DEPENDS+=	${LOCALBASE}/bin/aspell:${PORTSDIR}/textproc/aspell
.elif defined(WITH_ISPELL)
RUN_DEPENDS+=	${LOCALBASE}/bin/ispell:${PORTSDIR}/textproc/ispell
.endif

.if defined(WITH_HTML)
RUN_DEPENDS+=	${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
.endif

NO_BUILD=	yes
USE_GETTEXT=	yes
REINPLACE_ARGS=	-i.beforeIMP

PORTDOCS=	README CHANGES CREDITS INSTALL	\
		RELEASE_NOTES  TODO  UPGRADING
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

post-extract:
	@${MV} ${WRKSRC}/README ${WRKSRC}/docs/

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
	@${INSTALL} -d ${IMPDIR}/
	@${CP} -Rp ${SUB_DIRS:S|^|${WRKSRC}/|} ${IMPDIR}/
	@${CP} -p ${WRKSRC}/*.php ${IMPDIR}/
	@${INSTALL_DATA} ${WRKSRC}/config/conf.xml ${CONFDIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${IMPDIR}/
	@${CHMOD} -R o-rwx ${IMPDIR}/
	${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP}\
		%D/${IMPDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	${ECHO_CMD} @exec ${CHMOD} -R o-rwx\
		%D/${IMPDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
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
