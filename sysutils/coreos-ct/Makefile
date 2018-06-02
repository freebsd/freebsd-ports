# $FreeBSD$

PORTNAME=	coreos-ct
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	fabian.freyer@physik.tu-berlin.de
COMMENT=	Container Linux Config Transpiler

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_GITHUB=	yes

GH_ACCOUNT=	coreos
GH_PROJECT=	container-linux-config-transpiler

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_LDFLAGS=	-w -X github.com/${GH_ACCOUNT}/${GH_PROJECT}/internal/version.Raw=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md NEWS doc/*

do-build:
	@(cd ${GO_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} build -o ${WRKDIR}/bin/ct -ldflags "${GO_LDFLAGS}" ./internal)

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/ct ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
