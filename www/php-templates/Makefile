# Created by: vanilla
# $FreeBSD$

PORTNAME=	php-templates
PORTVERSION=	1.7.2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.7:ext \
		SF/${PORTNAME}/${PORTNAME}-doc/html:doc
DISTNAME=	php_templates-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:ext
.if !defined(NOPORTDOCS)
DISTFILES+=	php_templates-doc-eng-1.1${EXTRACT_SUFX}:doc
.endif

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A template framework for PHP

WRKSRC=		${WRKDIR}/templates
USE_DOS2UNIX=	yes

USE_PHP=	yes
USE_PHPIZE=	yes

CONFIGURE_ARGS=	--enable-templates=shared

SUB_FILES=	pkg-message

PORTDOCS=	*

NO_STAGE=	yes
do-install:
	@${MKDIR} ${PREFIX}/lib/php/${PHP_EXT_DIR}
	@${INSTALL_DATA} ${WRKSRC}/modules/templates.so \
		${PREFIX}/lib/php/${PHP_EXT_DIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}-doc/* ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
