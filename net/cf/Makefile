# $FreeBSD$

PORTNAME=	cf
PORTVERSION=	6.22.2
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	swills@FreeBSD.org
COMMENT=	CLI for Cloud Foundry written in Go

LICENSE=	APACHE20

BUILD_DEPENDS=	${LOCALBASE}/bin/go-bindata:devel/go-bindata

USE_GITHUB=	yes
GH_ACCOUNT=	cloudfoundry
GH_PROJECT=	cli

USES=		go
GO_PKGNAME=	code.cloudfoundry.org/cli

PLIST_FILES=	bin/cf

PORTDOCS=	CHANGELOG.md LICENSE NOTICE README.md

STRIP=		# stripping can break go binaries

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e "s/BUILT_FROM_SOURCE/${PORTVERSION}/g" \
		${WRKSRC}/cf/app_constants.go
	@: ${LN} -s ../.. ${WRKSRC}/vendor/code.cloudfoundry.org/cli

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for x in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${x} ${STAGEDIR}${DOCSDIR}
.endfor

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/cli ${STAGEDIR}${PREFIX}/bin/cf

.include <bsd.port.mk>
