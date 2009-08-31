# New ports collection makefile for:	www/typo
# Date created:				May 29th 2005
# Whom:					Jonathan Weiss <jw@innerewut.de>
#
# $FreeBSD$
#

PORTNAME=	typo
PORTVERSION=	5.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jw@innerewut.de
COMMENT=	An absolutely minimal weblogging engine powered by rails

RUN_DEPENDS=	rails:${PORTSDIR}/www/rubygem-rails \
		redcloth:${PORTSDIR}/www/rubygem-redcloth \
		rails-app-installer-setup:${PORTSDIR}/www/rubygem-rails-app-installer

NO_BUILD=	yes

TYPODIR=	www/${DISTNAME}

do-install:
	${CP} -R ${WRKSRC} ${PREFIX}/${TYPODIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${TYPODIR}/log
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${TYPODIR}/public
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${TYPODIR}/tmp

post-install:
	@${FIND} ${PREFIX}/${TYPODIR} -not -type d \
		| ${SED} -ne 's,^${PREFIX}/,,p' >> ${TMPPLIST}
	@${FIND} -d ${PREFIX}/${TYPODIR} -type d \
		| ${SED} -ne 's,^${PREFIX}/${TYPODIR},@dirrm ${TYPODIR},p' >> ${TMPPLIST}

.include <bsd.port.mk>
