# New ports collection makefile for:  squirm
# Version required: 1.0betaB
# Date created:     24 May 1999
# Whom:             Maxim Sobolev <sobomax@altavista.net>
#
# $Id$
#

DISTNAME=	squirm-1.0betaB
PKGNAME=	squirm-1.0b
CATEGORIES=	www
MASTER_SITES=	http://www.senet.com.au/squirm/ \
		http://www.elab.co.za/squirm/

MAINTAINER=	sobomax@altavista.net

RUN_DEPENDS=	${PREFIX}/sbin/squid:${PORTSDIR}/www/squid22

post-patch:
	@${PERL} -pi -e "s.%PREFIX%.${PREFIX}.g" ${WRKSRC}/paths.h

post-install:
	@echo
	@echo ' +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++'
	@echo '  You have to manually add "redirect_program ${PREFIX}/bin/squirm"'
	@echo '  into your squid.conf file.'
	@echo '  For help on configuring squirm try http://www.senet.com.au/squirm/'
	@echo ' +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++'
	@echo

.include <bsd.port.mk>
