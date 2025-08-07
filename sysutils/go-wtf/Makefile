PORTNAME=	wtf
PORTVERSION=	0.43.0
DISTVERSIONPREFIX=	v
PORTREVISION=	18
CATEGORIES=	sysutils
PKGNAMEPREFIX=	go-

MAINTAINER=	hsw@bitmark.com
COMMENT=	Personal information dashboard for your terminal
WWW=		https://wtfutil.com

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cpe go:modules

GO_MODULE=      github.com/wtfutil/wtf
GO_BUILDFLAGS=	-ldflags "-X main.version=${DISTVERSION}"

CPE_VENDOR=	wtfutil

CONFLICTS=	wtf

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${FIND} ${WRKSRC}/_sample_configs -name "*.yml" -exec ${INSTALL_DATA} {} \
	${STAGEDIR}${EXAMPLESDIR}/ \;

.include <bsd.port.mk>
