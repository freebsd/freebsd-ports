#
# New ports collection makefile for: osCommerce
#
# Date Created:	Dec  5 2003
# Whom:		Travis Campbell <hcoyote@ghostar.org>
#
# $FreeBSD$
#

PORTNAME=	oscommerce
DISTVERSION=	2.2r2-060817
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tep
DISTNAME=	${PORTNAME}-${DISTVERSION:S/r/ms/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	vlad@vlad.uz.ua
COMMENT=	An full-featured open source e-commerce system

USE_PHP=	mysql session pcre
WANT_PHP_WEB=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
DOCS=		CHANGELOG LICENSE STANDARD documentation.pdf \
		tep_database-pr2.2-CVS.pdf update-20060817.txt

do-install:
	${MKDIR} ${WWWDIR}
	${CP} -R ${WRKSRC}/catalog ${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
