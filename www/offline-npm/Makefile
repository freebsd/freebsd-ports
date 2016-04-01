# Created by: Carlos J Puga Medina <cpm@fbsd.es>
# $FreeBSD$

PORTNAME=	offline-npm
PORTVERSION=	0.2.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	www

MAINTAINER=	cpm@fbsd.es
COMMENT=	Offline installation with npm install

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	npm>0:www/npm
RUN_DEPENDS=	npm>0:www/npm

USE_GITHUB=	yes
GH_ACCOUNT=	commenthol
GH_PROJECT=	offline-npm

NO_BUILD=	yes
NO_ARCH=	yes
USES=		shebangfix
SHEBANG_FILES=	test/test.sh

do-install:
	(cd ${STAGEDIR}${PREFIX}/lib && ${SETENV} \
		HOME=${WRKDIR} npm install ${WRKSRC})

	# this is a dirty hack
	${LN} -s ${PREFIX}/lib/node_modules/.bin/offline-npm ${STAGEDIR}${PREFIX}/bin/offline-npm

.include <bsd.port.mk>
