# Created by: vanilla
# $FreeBSD$

PORTNAME=	php-templates
PORTVERSION=	1.7.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.7:ext \
		SF/${PORTNAME}/${PORTNAME}-doc/html:doc
DISTNAME=	php_templates-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:ext
DISTFILES+=	php_templates-doc-eng-1.1${EXTRACT_SUFX}:doc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Template framework for PHP

WRKSRC=		${WRKDIR}/templates
USES=		dos2unix php:phpize

IGNORE_WITH_PHP=	70

CONFIGURE_ARGS=	--enable-templates=shared

SUB_FILES=	pkg-message

PORTDOCS=	*

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
	${INSTALL_LIB} ${WRKSRC}/modules/templates.so \
		${STAGEDIR}${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}-doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
