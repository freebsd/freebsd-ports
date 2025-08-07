PORTNAME=	coreos-ct
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
PORTREVISION=	28
CATEGORIES=	sysutils

MAINTAINER=	fabian.freyer@physik.tu-berlin.de
COMMENT=	Container Linux Config Transpiler
WWW=		https://coreos.com/os/docs/latest/overview-of-ct.html

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	coreos
GH_PROJECT=	container-linux-config-transpiler

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_BUILDFLAGS=	-ldflags "-w -X github.com/${GH_ACCOUNT}/${GH_PROJECT}/internal/version.Raw=${PORTVERSION}"
GO_TARGET=	./internal:ct

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md NEWS doc/*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
