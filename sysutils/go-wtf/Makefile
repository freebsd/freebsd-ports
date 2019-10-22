# $FreeBSD$

PORTNAME=	wtf
PORTVERSION=	0.23.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
PKGNAMEPREFIX=	go-

MAINTAINER=	hsw@bitmark.com
COMMENT=	Personal information dashboard for your terminal

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		go:modules

CONFLICTS=	wtf

USE_GITHUB=	yes
GH_ACCOUNT=	wtfutil

GO_BUILDFLAGS=	-ldflags "-X main.version=${DISTVERSION}"

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_SUB=	yes

# try to deal with case insensitive github names
WTF_VGH_DIR=	${WRKSRC}/vendor/github.com
post-patch:
	[ -d "${WTF_VGH_DIR}/Microsoft" -a ! -d "${WTF_VGH_DIR}/microsoft" ] && \
	  ${LN} -s Microsoft "${WTF_VGH_DIR}/microsoft" || true
	[ -d "${WTF_VGH_DIR}/microsoft" -a ! -d "${WTF_VGH_DIR}/Microsoft" ] && \
	  ${LN} -s microsoft "${WTF_VGH_DIR}/Microsoft" || true

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${FIND} ${WRKSRC}/_sample_configs -name "*.yml" -exec ${INSTALL_DATA} {} \
	${STAGEDIR}${EXAMPLESDIR}/ \;

.include <bsd.port.mk>
