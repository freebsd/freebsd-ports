# New ports collection makefile for:	www/typo
# Date created:				May 29th 2005
# Whom:					Jonathan Weiss <jw@innerewut.de>
#
# $FreeBSD$
#

PORTNAME=	typo
PORTVERSION=	2.0.6
CATEGORIES=	www
MASTER_SITES=	http://rubyforge.org/frs/download.php/4205/

MAINTAINER=	jw@innerewut.de
COMMENT=	An absolutely minimal weblogging engine powered by rails

RUN_DEPENDS=	rails:${PORTSDIR}/www/rubygem-rails \
		${LOCALBASE}/lib/ruby/gems/1.8/specifications/RedCloth-3.0.3.gemspec:${PORTSDIR}/www/rubygem-redcloth

NO_BUILD=	yes

TYPODIR=	www/${DISTNAME}

do-install:
	${CP} -R ${WRKSRC} ${PREFIX}/${TYPODIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${TYPODIR}

post-install:
	@${FIND} ${PREFIX}/${TYPODIR} -not -type d \
		| ${SED} -ne 's,^${PREFIX}/,,p' >> ${TMPPLIST}
	@${FIND} -d ${PREFIX}/${TYPODIR} -type d \
		| ${SED} -ne 's,^${PREFIX}/${TYPODIR},@dirrm ${TYPODIR},p' >> ${TMPPLIST}

.include <bsd.port.mk>
