# Created by: Steve Wills <swills@freebsd.org>
# $FreeBSD$

PORTNAME=	uglifyjs
PORTVERSION=	1.3.5
CATEGORIES=	www devel
MASTER_SITES=	http://github.com/mishoo/UglifyJS/archive/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	swills@freebsd.org
COMMENT=	JavaScript parser/compressor/beautifier

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	npm>=0:${PORTSDIR}/www/npm
RUN_DEPENDS=	npm>=0:${PORTSDIR}/www/npm

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/UglifyJS-${PORTVERSION}

do-install:
	(cd ${STAGEDIR}${PREFIX}/lib ; ${SETENV} HOME=${WRKDIR} npm install ${WRKSRC})
	# this is a dirty hack
	${LN} -s ${PREFIX}/lib/node_modules/.bin/uglifyjs ${STAGEDIR}${PREFIX}/bin/uglifyjs

.include <bsd.port.mk>
