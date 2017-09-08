# $FreeBSD$

PORTNAME=	yarn
DISTVERSIONPREFIX=	v
DISTVERSION=	0.27.5
CATEGORIES=	www
MASTER_SITES=	https://yarnpkg.com/downloads/${PORTVERSION}/

MAINTAINER=	pizzamig@FreeBSD.org
COMMENT=	Package manager for node, alternative to npm

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/dist

OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	NODE4 NODE6 NODE
OPTIONS_DEFAULT=	NODE
NODE_DESC=	Use www/node as backend
NODE6_DESC=	Use www/node6 as backend
NODE4_DESC=	Use www/node4 as backend

NODE_RUN_DEPENDS=	node>=0.8.0:www/node
NODE6_RUN_DEPENDS=	node6>=0.8.0:www/node6
NODE4_RUN_DEPENDS=	node4>=0.8.0:www/node4

CONFLICTS_INSTALL=	hadoop-2*

NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	@${RM} ${WRKSRC}/bin/*.cmd
	@${REINPLACE_CMD} -i '' -e 's|"installationMethod": "tar"|"installationMethod": "pkg"|g' \
		${WRKSRC}/package.json

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/yarn
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/node_modules/yarn)
	${RLN} ${STAGEDIR}${PREFIX}/lib/node_modules/yarn/bin/yarn.js ${STAGEDIR}${PREFIX}/bin/yarn
	${RLN} ${STAGEDIR}${PREFIX}/lib/node_modules/yarn/bin/yarnpkg ${STAGEDIR}${PREFIX}/bin/yarnpkg

.include <bsd.port.mk>
