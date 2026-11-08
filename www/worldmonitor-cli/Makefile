PORTNAME=	worldmonitor-cli
DISTVERSION=	0.2.2
CATEGORIES=	www
MASTER_SITES=	https://registry.npmjs.org/worldmonitor/-/
DISTNAME=	worldmonitor-${DISTVERSION}
DIST_SUBDIR=	worldmonitor-cli

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Command-line client for the World Monitor global intelligence API
WWW=		https://github.com/koala73/worldmonitor/tree/main/cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe nodejs:run shebangfix tar:tgz
CPE_VENDOR=	koala73
CPE_PRODUCT=	worldmonitor_cli
SHEBANG_LANG=	node
SHEBANG_FILES=	bin/worldmonitor.mjs

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/package

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} src ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/worldmonitor.mjs ${STAGEDIR}${DATADIR}/bin/worldmonitor.mjs
	${RLN} ${STAGEDIR}${DATADIR}/bin/worldmonitor.mjs ${STAGEDIR}${PREFIX}/bin/worldmonitor
	${RLN} ${STAGEDIR}${DATADIR}/bin/worldmonitor.mjs ${STAGEDIR}${PREFIX}/bin/wm

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
