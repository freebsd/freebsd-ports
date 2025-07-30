PORTNAME=	phpmustache
PORTVERSION=	2.14.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	marc@bumblingdork.com
COMMENT=	PHP5 code for Mustache
WWW=		https://github.com/bobthecow/mustache.php

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Installation mode changed from systemwide to per-application with Composer
EXPIRATION_DATE=2025-10-31

USES=		php:build
USE_GITHUB=	yes
GH_ACCOUNT=	bobthecow
GH_PROJECT=	mustache.php

NO_ARCH=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	EXAMPLES

do-build:
	@${WRKSRC}/bin/build_bootstrap.php

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mustache.php ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
