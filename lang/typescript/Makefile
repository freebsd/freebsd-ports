PORTNAME=	typescript
DISTVERSION=	5.9.2
CATEGORIES=	lang
MASTER_SITES=	https://registry.npmjs.org/${PORTNAME}/-/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Superset of JavaScript that compiles to JavaScript output
WWW=		https://www.typescriptlang.org/

DEPRECATED=	No port maintainer, fast moving port.
EXPIRATION_DATE=2025-11-30

LICENSE=	APACHE20

NO_ARCH=	yes
NO_BUILD=	yes

USES=		nodejs:run tar

WRKSRC=		${WRKDIR}/package


post-patch:
	${FIND} ${WRKSRC}/bin -type f | ${XARGS} \
		${REINPLACE_CMD} -i "" -e 's|../lib|${LOCALBASE}/lib/node_modules/${PORTNAME}|'

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/tsc \
		${STAGEDIR}${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/tsserver \
		${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}

.include <bsd.port.mk>
