# $FreeBSD$

PORTNAME=	packer
PORTVERSION=	0.10.0
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Tool for creating machine images

BUILD_DEPENDS=	${LOCALBASE}/bin/go:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	mitchellh

STRIP=		# stripping can break go binaries

post-extract:
	@${MV} ${WRKSRC}/vendor ${WRKSRC}/src
	@${MKDIR} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.for src in .github .gitignore .travis.yml CHANGELOG.md CONTRIBUTING.md Godeps \
	LICENSE Makefile README.md Vagrantfile appveyor.yml azure-merge.sh \
	builder checkpoint.go command commands.go common communicator config.go \
	contrib examples fix helper log.go main.go main_test.go packer panic.go \
	plugin post-processor provisioner scripts signal.go stdin.go template \
	test version.go website
	@${MV} ${WRKSRC}/${src} \
		${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}
.endfor

do-build:
	@cd ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}; ${SETENV} GOPATH=${WRKSRC} go build -o bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
