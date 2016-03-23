# Created by: Steve Polyack <spolyack@collaborativefusion.com>
# $FreeBSD$

PORTNAME=	phpmustache
PORTVERSION=	2.10.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP5 code for Mustache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	bobthecow
GH_PROJECT=	mustache.php

USE_PHP=	yes
USE_PHP_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	EXAMPLES

do-build:
	@${WRKSRC}/bin/build_bootstrap.php

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mustache.php ${STAGEDIR}${DATADIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/test/fixtures/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
