# $FreeBSD$

PORTNAME=	yarn
PORTVERSION=	0.23.2
DISTVERSIONPREFIX=	v
CATEGORIES=	www
MASTER_SITES=	https://yarnpkg.com/downloads/${PORTVERSION}/

MAINTAINER=	luca.pizzamiglio@gmail.com
COMMENT=	Package manager for node, alternative to npm

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/dist

OPTIONS_SINGLE=	BACKEND
OPTIONS_SINGLE_BACKEND=	NODE4 NODE6 NODE
OPTIONS_DEFAULT=	NODE6
NODE_DESC=	Use www/node as backend
NODE6_DESC=	Use www/node6 as backend
NODE4_DESC=	Use www/node4 as backend

NODE_RUN_DEPENDS=	node>=0.8.0:www/node
NODE6_RUN_DEPENDS=	node6>=0.8.0:www/node6
NODE4_RUN_DEPENDS=	node4>=0.8.0:www/node4

NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	@${RM} ${WRKSRC}/node_modules/cli-width/coverage/lcov.info
	@${RM} ${WRKSRC}/node_modules/mute-stream/coverage/lcov.info
	@${RM} -r ${WRKSRC}/node_modules/sshpk/man

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/yarn
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/node_modules/yarn)
	${LN} -sf ../lib/node_modules/yarn/bin/yarn.js ${STAGEDIR}${PREFIX}/bin/yarn

.include <bsd.port.mk>
