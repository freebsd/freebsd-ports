# Created by: Travis Campbell <hcoyote@ghostar.org>
# $FreeBSD$

PORTNAME=	oscommerce
DISTVERSION=	2.3.3.4
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	www
MASTER_SITES=	http://www.oscommerce.com/files/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Full-featured open source e-commerce system

USES=		cpe zip
USE_PHP=	mysql session pcre gd curl openssl
WANT_PHP_WEB=	yes
NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message
PORTDOCS=	CHANGELOG LICENSE STANDARD release_notes.pdf documentation.pdf
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}/${WWWDIR}
	${CP} -R ${WRKSRC}/catalog ${STAGEDIR}/${WWWDIR}
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${DOCSDIR}
.endfor

.include <bsd.port.mk>
