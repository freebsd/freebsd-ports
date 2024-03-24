PORTNAME=	spiff
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.8
PORTREVISION=	19
CATEGORIES=	textproc

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Declarative YAML templating system tuned for BOSH deployment manifests
WWW=		https://github.com/cloudfoundry-incubator/spiff

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Active development of this port has been ceased
EXPIRATION_DATE=2024-04-13

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
