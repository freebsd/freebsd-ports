# $FreeBSD$

PORTNAME=	envconsul
PORTVERSION=	0.7.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Populate values from Consul into a process environment

LICENSE=	MPL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/envconsul

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md
COMMIT=		7ece735
GO_LDFLAGS=	-ldflags="-s -w \
		-X main.Name=${PORTNAME} \
		-X main.Version=${PORTVERSION} \
		-X main.GitCommit=${COMMIT}"

do-build:
	@cd ${WRKSRC}/src/github.com/hashicorp/envconsul; \
		${SETENV} ${BUILD_ENV} GOPATH=${WRKSRC} \
		go build ${GO_LDFLAGS}\
		-o bin/envconsul

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/hashicorp/envconsul/bin/envconsul ${STAGEDIR}${PREFIX}/bin/envconsul

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${CP} ${WRKSRC}/src/github.com/hashicorp/envconsul/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
