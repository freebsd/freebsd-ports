# Created by: Steve Polyack <spolyack@collaborativefusion.com>
# $FreeBSD$

PORTNAME=	phpmustache
PORTVERSION=	2.4.0
CATEGORIES=	www
MASTER_SITES=	GH

MAINTAINER=	spolyack@collaborativefusion.com
COMMENT=	PHP5 code for Mustache

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	bobthecow
GH_PROJECT=	mustache.php
GH_TAGNAME=	v2.4.0
GH_COMMIT=	8433da6

USE_PHP=	yes
USE_PHP_BUILD=	yes

SUB_FILES=	pkg-message

do-build:
	@${WRKSRC}/bin/build_bootstrap.php

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/mustache.php ${DATADIR}
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/test/fixtures/examples/* ${EXAMPLESDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
