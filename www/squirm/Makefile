# New ports collection makefile for:	squirm
# Date created:				24 May 1999
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	squirm
PORTVERSION=	1.26
CATEGORIES=	www
MASTER_SITES=	http://squirm.foote.com.au/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast & configurable redirector for the Squid

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid

SQUID_UID?=	squid
SQUID_GID?=	squid

MAKE_ENV+=	SQUID_UID=${SQUID_UID} SQUID_GID=${SQUID_GID}

PLIST_SUB=	SQUID_UID=${SQUID_UID} SQUID_GID=${SQUID_GID}

pre-install:
.if (${SQUID_UID} == "nobody") || (${SQUID_GID} == "nogroup")
	@${ECHO_MSG}
	@${ECHO_MSG}	'WARNING! You are going to install squirm files with either nobody owner or'
	@${ECHO_MSG}	'nogroup group, which may be insecure.'
	@${ECHO_MSG}
.endif
post-install:
	@${ECHO_MSG}
.if (${SQUID_UID} == "squid") && (${SQUID_GID} == "squid")
	@${ECHO_MSG}
	@${ECHO_MSG} 'INFO: Your SQUID_UID and SQUID_GID variables are set to the default'
	@${ECHO_MSG} '      squid user/group: SQUID_UID = ${SQUID_UID}  SQUID_GID = ${SQUID_GID}'
	@${ECHO_MSG} '      These values are used by the www/squid port. They must match what you have chosen'
	@${ECHO_MSG} '      for the www/squid port. If you are using different UID/GID they must match,'
	@${ECHO_MSG} '      or else you are asking for problems !'
	@${ECHO_MSG}
.endif
	@${ECHO_MSG} ' +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++'
	@${ECHO_MSG} '  You have to manually add "redirect_program ${PREFIX}/bin/squirm"'
	@${ECHO_MSG} '  into your squid.conf file.'
	@${ECHO_MSG} '  For help on configuring squirm try http://www.senet.com.au/squirm/'
	@${ECHO_MSG} ' +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++'
	@${ECHO_MSG}

.include <bsd.port.mk>
