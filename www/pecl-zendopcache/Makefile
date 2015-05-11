# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zendopcache
PORTVERSION=	7.0.5
CATEGORIES=	www
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Opcode cacher and optimizer for PHP

LICENSE=	PHP301

OPTIONS_DEFINE=	DOCS

USES=		tar:tgz
USE_PHP=	yes
USE_PHP_BUILD=	yes
USE_ZENDEXT=	yes
PHP_MODNAME=	opcache
PHP_DEFAULT=	5
IGNORE_WITH_PHP=55 56

PORTDOCS=	*

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
