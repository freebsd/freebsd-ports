# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zendopcache
PORTVERSION=	7.0.2
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Opcode cacher and optimizer for PHP

LICENSE=	PHP301

OPTIONS_DEFINE=	DOCS

USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_ZENDEXT=	yes
PHP_MODNAME=	opcache

PORTDOCS=	*

IGNORE_WITH_PHP=	55

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
