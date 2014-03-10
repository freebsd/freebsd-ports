# Created by: Travis Campbell <hcoyote@ghostar.org>
# $FreeBSD$

PORTNAME=	oscommerce
DISTVERSION=	2.3.3.4
PORTEPOCH=	2
CATEGORIES=	www
MASTER_SITES=	http://www.oscommerce.com/files/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Full-featured open source e-commerce system

USES=		zip
USE_PHP=	mysql session pcre gd curl openssl
WANT_PHP_WEB=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
DOCS=		CHANGELOG LICENSE STANDARD release_notes.pdf documentation.pdf

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${STAGEDIR}/${WWWDIR}
	${CP} -R ${WRKSRC}/catalog ${STAGEDIR}/${WWWDIR}
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}/${WWWDIR}

	${CHMOD} 777 ${STAGEDIR}/${WWWDIR}/catalog/includes/configure.php
	${CHMOD} 777 ${STAGEDIR}/${WWWDIR}/catalog/admin/includes/configure.php
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}/${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
