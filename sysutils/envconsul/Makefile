# $FreeBSD$

PORTNAME=	envconsul
PORTVERSION=	0.7.3
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Populate values from Consul into a process environment

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_SUBDIR=	src/github.com/${GH_ACCOUNT}/${PORTNAME}

PLIST_FILES=	bin/envconsul

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md
COMMIT=		7ece735
GO_BUILDFLAGS=	-ldflags="-s -w \
		-X main.Name=${PORTNAME} \
		-X main.Version=${PORTVERSION} \
		-X main.GitCommit=${COMMIT}"

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${CP} ${WRKSRC}/src/github.com/hashicorp/envconsul/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
