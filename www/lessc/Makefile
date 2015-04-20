# Created by: Rodrigo Osorio <rodrigo@freebsd.org>
# $FreeBSD$

PORTNAME=	lessc
PORTVERSION=	2.5.0
CATEGORIES=	www devel
MASTER_SITES=	http://github.com/less/less.js/archive/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Javascript CSS pre-processor

LICENSE=	APACHE20

BUILD_DEPENDS=	npm>=0:${PORTSDIR}/www/npm
RUN_DEPENDS=	npm>=0:${PORTSDIR}/www/npm

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/less.js-${PORTVERSION}

do-install:
	(cd ${STAGEDIR}${PREFIX}/lib ; ${SETENV} HOME=${WRKDIR} npm install ${WRKSRC})
	# this is a dirty hack
	${LN} -s ${PREFIX}/lib/node_modules/.bin/lessc ${STAGEDIR}${PREFIX}/bin/lessc

.include <bsd.port.mk>
