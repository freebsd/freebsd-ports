#
# New ports collection makefile for: osCommerce
#
# Date Created:	Dec  5 2003
# Whom:		Travis Campbell <hcoyote@ghostar.org>
#
# $FreeBSD$
#

PORTNAME=	oscommerce
DISTVERSION=	2.2rc2a
PORTEPOCH=	2
CATEGORIES=	www
MASTER_SITES=	http://www.oscommerce.com/ext/
DISTNAME=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	vlad@vlad.uz.ua
COMMENT=	An full-featured open source e-commerce system

USE_ZIP=	yes
USE_PHP=	mysql session pcre gd curl openssl
WANT_PHP_WEB=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
DOCS=		CHANGELOG LICENSE STANDARD community_docs.pdf \
			documentation.pdf upgrade.html

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
