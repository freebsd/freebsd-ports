PORTNAME=	typescript-devel
DISTVERSION=	7.1.0-dev.20261105.1
CATEGORIES=	lang

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	JavaScript with syntax for types (development version)
WWW=		https://www.typescriptlang.org/ \
		https://github.com/microsoft/TypeScript

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
GH_PROJECT=	TypeScript
GH_TAGNAME=	c46bcd6089ea2e5e84e7fcc60845ac884a5b0ac1

GO_MOD_DIST=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${GH_PROJECT}/${GH_TAGNAME}/tsc/
GO_MODULE=	github.com/${GH_ACCOUNT}/${GH_PROJECT}/tsc
GO_ENV+=	GOWORK=off
GO_TARGET=	./cmd/tsc
GO_LDFLAGS=	-w -X ${GO_MODULE}/internal/core.version=${DISTVERSION}

CONFLICTS_INSTALL=	typescript-go

WRKSRC_SUBDIR=	tsc

PORTDOCS=	CONTRIBUTING.md README.md SECURITY.md SUPPORT.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${MV} -f ${STAGEDIR}${PREFIX}/bin/tsc \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/internal/bundled/libs/lib.*.ts \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${RLN} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/tsc \
		${STAGEDIR}${PREFIX}/bin/tsc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/../|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
