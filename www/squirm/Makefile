# New ports collection makefile for:	squirm
# Date created:				24 May 1999
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	squirm
PORTVERSION=	1.23
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://squirm.foote.com.au/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast & configurable redirector for the Squid

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid

NO_PACKAGE=	must set SQUID_UID and SQUID_GID before building

MAKE_ENV+=	SQUID_UID=${SQUID_UID} SQUID_GID=${SQUID_GID}

PLIST_SUB=	SQUID_UID=${SQUID_UID} SQUID_GID=${SQUID_GID}

pre-install:
.if defined(SQUID_UID) && defined(SQUID_GID)
.if (${SQUID_UID} == "nobody") || (${SQUID_GID} == "nogroup")
	@${ECHO_MSG}
	@${ECHO_MSG}	'WARNING! You are going to install squirm files with either nobody owner or'
	@${ECHO_MSG}	'nogroup group, which may be insecure.'
	@${ECHO_MSG}
.endif
.else
	@${ECHO_MSG}
	@${ECHO_MSG} 	'You should set SQUID_UID and SQUID_GID variables to your squid effective'
	@${ECHO_MSG}	'user/group. For example: SQUID_UID=squid SQUID_GID=squid.'
	@${ECHO_MSG}
	@${FALSE}
.endif

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} ' +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++'
	@${ECHO_MSG} '  You have to manually add "redirect_program ${PREFIX}/bin/squirm"'
	@${ECHO_MSG} '  into your squid.conf file.'
	@${ECHO_MSG} '  For help on configuring squirm try http://www.senet.com.au/squirm/'
	@${ECHO_MSG} ' +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++'
	@${ECHO_MSG}

.include <bsd.port.mk>
