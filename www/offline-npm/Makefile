# Created by: Carlos J Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	offline-npm
PORTVERSION=	0.2.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Offline installation with npm install

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	npm>0:www/npm
RUN_DEPENDS=	npm>0:www/npm

BROKEN=	Support for this project is broken with npm >= v3.x

USE_GITHUB=	yes
GH_ACCOUNT=	commenthol
GH_PROJECT=	offline-npm

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	(cd ${STAGEDIR}${PREFIX}/lib && ${SETENV} \
		HOME=${WRKDIR} npm install ${WRKSRC})

	# this is a dirty hack
	${LN} -s ${PREFIX}/lib/node_modules/.bin/offline-npm ${STAGEDIR}${PREFIX}/bin/offline-npm

.include <bsd.port.mk>
