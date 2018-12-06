# Created by: vanilla
# $FreeBSD$

PORTNAME=	templates
PORTVERSION=	1.7.2
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.7:ext \
		SF/${PORTNAME}/${PORTNAME}-doc/html:doc
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
DISTNAME=	php_templates-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:ext
DISTFILES+=	php_templates-doc-eng-1.1${EXTRACT_SUFX}:doc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Template framework for PHP

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

WRKSRC=		${WRKDIR}/templates
USES=		dos2unix php:phpize

IGNORE_WITH_PHP=	71 72 73

CONFIGURE_ARGS=	--enable-templates=shared

SUB_FILES=	pkg-message

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
	${INSTALL_LIB} ${WRKSRC}/modules/templates.so \
		${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}-doc/* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/php
	@${ECHO_CMD} "extension=${PREFIX}/lib/php/${PHP_EXT_DIR}/templates.so" > \
		${STAGEDIR}${PREFIX}/etc/php/ext-20-templates.ini

.include <bsd.port.mk>
