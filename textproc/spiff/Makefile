# $FreeBSD$

PORTNAME=	spiff
PORTVERSION=	1.0.8
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Declarative YAML templating system tuned for BOSH deployment manifests

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	cloudfoundry-incubator

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}

PLIST_FILES=	bin/spiff

PORTDOCS=	LICENSE README.md examples/cf-aws.yml \
		examples/multi-az-cf-aws.yml examples/tutorial.md

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} examples ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
