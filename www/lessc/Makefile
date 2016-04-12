# Created by: Rodrigo Osorio <rodrigo@freebsd.org>
# $FreeBSD$

PORTNAME=	lessc
PORTVERSION=	2.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www devel

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Javascript CSS pre-processor

LICENSE=	APACHE20

BUILD_DEPENDS=	npm>=0:www/npm
RUN_DEPENDS=	npm>=0:www/npm

NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	less
GH_PROJECT=	less.js

do-install:
	(cd ${STAGEDIR}${PREFIX}/lib ; ${SETENV} HOME=${WRKDIR} npm install ${WRKSRC})
	# this is a dirty hack
	${LN} -s ${PREFIX}/lib/node_modules/.bin/lessc ${STAGEDIR}${PREFIX}/bin/lessc

.include <bsd.port.mk>
