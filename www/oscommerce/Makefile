#
# New ports collection makefile for: osCommerce
#
# Date Created:	Dec  5 2003
# Whom:		Travis Campbell <hcoyote@ghostar.org>
#
# $FreeBSD$
#

PORTNAME=	oscommerce
PORTVERSION=	2.2r2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tep
DISTNAME=	${PORTNAME}-${PORTVERSION:S/r/ms/}

MAINTAINER=	hcoyote@ghostar.org
COMMENT=	An full-featured open source e-commerce system

USE_PHP=	mysql session
WANT_PHP_WEB=	yes
NO_BUILD=	yes
OSCOMMERCE=	${PREFIX}/www/data/oscommerce
PKGMESSAGE=	${WRKDIR}/pkg-message

WWWOWN?=	www
WWWGRP?=	www

do-install:
	${MKDIR} ${OSCOMMERCE}
	${CP} -R ${WRKSRC}/catalog ${OSCOMMERCE}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${OSCOMMERCE}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/STANDARD ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tep_database-pr2.2-CVS.pdf ${DOCSDIR}
.endif

post-install:
	@${SED} -e 's#%%OSCOMMERCE%%#${OSCOMMERCE}#g' pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
