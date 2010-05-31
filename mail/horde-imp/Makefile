# Ports collection makefile for:  imp3
# Date created:			  Mon Oct 08, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	imp
PORTVERSION=	4.3.7
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	mail www
DISTFILES=	${PORTNAME}-h3-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Webmail system for IMAP/POP3 mailboxes

WRKSRC=		${WRKDIR}/${PORTNAME}-h3-${PORTVERSION}

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

USE_PHP=	imap
. if !defined(WITHOUT_LDAP)
USE_PHP+=	ldap
. endif

.if !defined(WITHOUT_SMIME)
USE_PHP+=	openssl
.endif

.if !defined(NOCRYPT)
RUN_DEPENDS+=	${PEARDIR}/Mail/mimeDecode.php:${PORTSDIR}/mail/pear-Mail_mimeDecode \
		${LOCALBASE}/bin/gpg:${PORTSDIR}/security/gnupg
.endif

.if !defined(WITHOUT_ASPELL)
RUN_DEPENDS+=	${LOCALBASE}/bin/aspell:${PORTSDIR}/textproc/aspell
.elif defined(WITH_ISPELL)
RUN_DEPENDS+=	${LOCALBASE}/bin/ispell:${PORTSDIR}/textproc/ispell
.endif

.if defined(WITH_HTML)
RUN_DEPENDS+=	${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
.endif

CONFLICTS=	imp-3.*
USE_HORDE=	base
USE_GETTEXT=	yes
PORTDOCS=	README CHANGES CREDITS INSTALL	\
		RELEASE_NOTES  TODO  UPGRADING

pre-configure:
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

pre-install:
.if !defined(BATCH) && !defined(WITHOUT_SSL)
	@if ! ${GREP} -q -e 'CCLIENT_SSLENABLED "yes"' ${PORTREV_H}; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure c-client with SSL support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.endif

.include "${.CURDIR}/../../www/horde-base/bsd.horde.mk"
.include <bsd.port.mk>
