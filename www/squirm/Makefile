# New ports collection makefile for:  squirm
# Version required: 1.0betaB
# Date created:     24 May 1999
# Whom:             Maxim Sobolev <sobomax@altavista.net>
#
# $Id: Makefile,v 1.1.1.1 1999/06/09 01:39:19 steve Exp $
#

DISTNAME=	squirm-1.0betaB
PKGNAME=	squirm-1.0b
CATEGORIES=	www
MASTER_SITES=	http://www.senet.com.au/squirm/ \
		http://www.elab.co.za/squirm/

MAINTAINER=	sobomax@altavista.net

RUN_DEPENDS=	${PREFIX}/sbin/squid:${PORTSDIR}/www/squid22

NO_PACKAGE=	must set SQUID_UID and SQUID_GID before building

MAKE_ENV+=	SQUID_UID=${SQUID_UID} SQUID_GID=${SQUID_GID}

post-patch:
	@${PERL} -pi -e "s.%PREFIX%.${PREFIX}.g" ${WRKSRC}/paths.h

pre-install:
.if defined(SQUID_UID) && defined(SQUID_GID)
.if (${SQUID_UID} == "nobody") || (${SQUID_GID} == "nogroup")
	@echo
	@echo	'WARNING! You are going to install squirm files with either nobody owner or'
	@echo	'nogroup group, which may be insecure.'
	@echo
.endif
.else
	@echo
	@echo 	'You should set SQUID_UID and SQUID_GID variables to your squid effective'
	@echo	'user/group. For example: SQUID_UID=squid SQUID_GID=squid.'
	@echo
	@false
.endif

post-install:
	@echo
	@echo ' +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++'
	@echo '  You have to manually add "redirect_program ${PREFIX}/bin/squirm"'
	@echo '  into your squid.conf file.'
	@echo '  For help on configuring squirm try http://www.senet.com.au/squirm/'
	@echo ' +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++'
	@echo

.include <bsd.port.mk>
