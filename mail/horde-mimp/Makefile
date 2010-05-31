# Ports collection makefile for:	mimp3
# Date created:			Mon Feb 05, 2007
# Whom:				Beech Rintoul <beech@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mimp
PORTVERSION=	1.1.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	mail www

MAINTAINER=	ports@FreeBSD.org
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
# - WITH_VALID_CERT	if you own a valid SSL certificate;
#-----------------------------------------------------------------------

RUN_DEPENDS+=	${PEARDIR}/Auth/SASL.php:${PORTSDIR}/security/pear-Auth_SASL \
		${HORBAS}/imp/index.php:${PORTSDIR}/mail/horde-imp

USE_PHP=	imap
. if !defined(WITHOUT_LDAP)
USE_PHP+=	ldap
. endif
.if !defined(WITHOUT_SMIME)
USE_PHP+=	openssl
.endif
.if !defined(NOCRYPT)
RUN_DEPENDS+=	${LOCALBASE}/bin/gpg:${PORTSDIR}/security/gnupg
.endif

USE_HORDE=	base
USE_GETTEXT=	yes
PORTDOCS=	README CHANGES CREDITS INSTALL RELEASE_NOTES

pre-configure:
.if !defined(NOCRYPT)
	@${REINPLACE_CMD} -e "s:%%GPG%%:${LOCALBASE}/bin/gpg:" \
		${WRKSRC}/config/conf.xml
.else
	@${REINPLACE_CMD} -e "s:%%GPG%%::" ${WRKSRC}/config/conf.xml
.endif

pre-install:
.if !defined(BATCH)
	@if ! ${GREP} -q -e 'CCLIENT_SSLENABLED "yes"' ${PORTREV_H}; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure c-client with SSL support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.endif

.include "${.CURDIR}/../../www/horde-base/bsd.horde.mk"
.include <bsd.port.mk>
