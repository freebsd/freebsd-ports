# $FreeBSD$

PORTNAME=	sops
DISTVERSION=	3.0.2
CATEGORIES=	security editors

MAINTAINER=	dg@syrec.org
COMMENT=	Editor of encrypted files that supports YAML, JSON and BINARY formats

LICENSE=	MPL20

BUILD_DEPENDS=	go>=1.8:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	mozilla
GH_SUBDIR=	src/go.mozilla.org/${PORTNAME}

PLIST_FILES=	bin/sops

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.rst CHANGELOG.rst

do-build:
	@cd ${WRKSRC}/${GH_SUBDIR} && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} go build -o ${PORTNAME} ./cmd/sops

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
