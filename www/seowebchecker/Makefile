PORTNAME=	seowebchecker
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.2
CATEGORIES=	www

MAINTAINER=	support@seowebchecker.com
COMMENT=	Lightweight website SEO audit tool and CLI by SEOWebChecker
WWW=		https://seowebchecker.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		nodejs:run

USE_GITHUB=	yes
GH_ACCOUNT=	jaiganesh6999
GH_PROJECT=	seowebchecker-seoaudit-sdk

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}
	(cd ${WRKSRC}/npm && ${COPYTREE_SHARE} "bin lib index.d.ts index.js package.json README.md" ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME})
	${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}/bin/cli.js
	${RLN} ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}/bin/cli.js ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${RLN} ${STAGEDIR}${PREFIX}/lib/node_modules/${PORTNAME}/bin/cli.js ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-audit

.include <bsd.port.mk>
