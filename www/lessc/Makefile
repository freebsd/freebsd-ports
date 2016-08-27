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

USE_GITHUB=	yes
GH_ACCOUNT=	less
GH_PROJECT=	less.js

# npm install both builds and installs.  To avoid building in the stage phase,
# allow npm to install in a temporary directory and move from there.
# Moreover, only a fraction of what is installed by npm needs to be packaged
do-build:
	${MKDIR} ${WRKDIR}/build-lib
	(cd ${WRKDIR}/build-lib && \
		${SETENV} HOME=${WRKDIR} npm install ${WRKSRC})

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin \
		${STAGEDIR}${PREFIX}/lib/node_modules/.bin
	${MV} ${WRKDIR}/build-lib/node_modules/less \
		${STAGEDIR}${PREFIX}/lib/node_modules
	${MV} ${WRKDIR}/build-lib/node_modules/.bin/lessc \
		${STAGEDIR}${PREFIX}/lib/node_modules/.bin
	(cd ${STAGEDIR}${PREFIX}/bin && \
		${LN} -s ../lib/node_modules/.bin/lessc lessc)

.include <bsd.port.mk>
