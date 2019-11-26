# Created by: Steve Polyack <spolyack@collaborativefusion.com>
# $FreeBSD$

PORTNAME=	phpmustache
PORTVERSION=	2.13.0
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	marc@bumblingdork.com
COMMENT=	PHP5 code for Mustache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

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

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/test/fixtures/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
