# Created by: Rodrigo Osorio <rodrigo@freebsd.org>
# $FreeBSD$

PORTNAME=	npm-less-plugin-clean-css
PORTVERSION=	20170503
CATEGORIES=	www devel

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Compresses the css output from less using clean-css

LICENSE=	APACHE20

BUILD_DEPENDS=	npm>=0:www/npm
RUN_DEPENDS=	npm>=0:www/npm \
		${LOCALBASE}/lib/node_modules/clean-css/index.js:devel/npm-clean-css \
		${LOCALBASE}/bin/lessc:www/lessc

USE_GITHUB=	yes
GH_ACCOUNT=	less
GH_TAGNAME=	19c7f4bfc7d1f30243f24944d44b794a407211fb
GH_PROJECT=	less-plugin-clean-css

# npm install both builds and installs.  To avoid building in the stage phase,
# allow npm to install in a temporary directory and move from there.
# Moreover, only a fraction of what is installed by npm needs to be packaged
do-build:
	${MKDIR} ${WRKDIR}/build-lib
	(cd ${WRKDIR}/build-lib && \
		${SETENV} HOME=${WRKDIR} npm install ${WRKSRC})

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/ && \
	${MV} ${WRKDIR}/build-lib/node_modules/less-plugin-clean-css \
		${STAGEDIR}${PREFIX}/lib/node_modules/

.include <bsd.port.mk>
