# New ports collection makefile for:  squirm
# Date created:     24 May 1999
# Whom:             Maxim Sobolev <sobomax@altavista.net>
#
# $FreeBSD$
#

PORTNAME=	squirm
PORTVERSION= 	1.0b
CATEGORIES=	www
MASTER_SITES=	http://www.senet.com.au/squirm/ \
		http://www.elab.co.za/squirm/
DISTNAME=	squirm-1.0betaB

MAINTAINER=	sobomax@altavista.net

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid22

NO_PACKAGE=	must set SQUID_UID and SQUID_GID before building

MAKE_ENV+=	SQUID_UID=${SQUID_UID} SQUID_GID=${SQUID_GID}

post-patch:
	@${PERL} -pi -e "s.%PREFIX%.${PREFIX}.g" ${WRKSRC}/paths.h

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
