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

USE_MYSQL=	yes
WANT_MYSQL_VER=	323
NO_BUILD=	YES
PHP4_PORT?=	www/mod_php4
OSCOMMERCE?=	${PREFIX}/www/data/oscommerce
PKGMESSAGE=	${WRKDIR}/pkg-message

.if defined(WITH_APACHE2)
MOD_DIR=	libexec/apache2
.else
MOD_DIR=	libexec/apache
.endif

MOD_PHP=	${PREFIX}/${MOD_DIR}/libphp4.so

WWWOWN?=	www
WWWGRP?=	www

RUN_DEPENDS+=	${MOD_PHP}:${PORTSDIR}/${PHP4_PORT}
RUN_DEPENDS+=	${PREFIX}/bin/mysql:${PORTSDIR}/databases/mysql323-client

do-install:
	${MKDIR} ${OSCOMMERCE}
	${CP} -R ${WRKSRC}/catalog ${OSCOMMERCE}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${OSCOMMERCE}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP}	${WRKSRC}/LICENSE ${DOCSDIR}
	${CP}	${WRKSRC}/FAQ ${DOCSDIR}
	${CP}	${WRKSRC}/INSTALL ${DOCSDIR}
	${CP}	${WRKSRC}/README ${DOCSDIR}
	${CP}	${WRKSRC}/STANDARD ${DOCSDIR}
	${CP}	${WRKSRC}/tep_database-pr2.2-CVS.pdf ${DOCSDIR}
.endif

post-install:
	@ ${SED} -e 's#%%OSCOMMERCE%%#${OSCOMMERCE}#g' pkg-message > ${PKGMESSAGE}
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
