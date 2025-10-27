PORTNAME=	corepack
PORTVERSION=	0.34.1
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	https://github.com/nodejs/corepack/releases/download/v${PORTVERSION}/
DIST_SUBDIR=	corepack/${PORTVERSION}
DISTNAME=	corepack

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Zero-runtime-dependency package acting as bridge between Node projects and their package managers
WWW=		https://github.com/nodejs/corepack

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/package/LICENSE.md

USES=		tar:tgz

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/
	cd ${WRKSRC}/package/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/node_modules/corepack/
	${LN} -s ../lib/node_modules/corepack/dist/corepack.js ${STAGEDIR}${PREFIX}/bin/corepack

.include <bsd.port.mk>
