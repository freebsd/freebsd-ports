# $FreeBSD$

PORTNAME=		goss
PORTVERSION=		0.3.4
DISTVERSIONPREFIX=	v
CATEGORIES=	 	sysutils

MAINTAINER=	 	englishm@llnw.com
COMMENT=		Quick and Easy server validation

LICENSE=		APACHE20
LICENSE_FILE=	 	${WRKSRC}/LICENSE

BUILD_DEPENDS=		go:lang/go

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	go-ps only supports amd64

PLIST_FILES=		bin/goss

USE_GITHUB=	 	yes
GH_ACCOUNT=	 	aelsabbahy
GH_SUBDIR=		src/github.com/aelsabbahy/${PORTNAME}
GH_TUPLE=		achanda:go-sysctl:6be7678:achanda/src/github.com/achanda/go-sysctl \
			aelsabbahy:go-ps:4433868:gops/src/github.com/aelsabbahy/go-ps \
			aelsabbahy:GOnetstat:edf89f7:GOnetstat/src/github.com/aelsabbahy/GOnetstat \
			cheekybits:genny:e8e29e6:cheekybits/src/github.com/cheekybits/genny \
			fatih:color:bf82308:fatih/src/github.com/fatih/color \
			go-yaml:yaml:a5b47d3:yaml/src/gopkg.in/yaml.v2 \
			golang:sys:9a2e24c:sys/src/golang.org/x/sys \
			mattn:go-colorable:d228849:mattn/src/github.com/mattn/go-colorable \
			mattn:go-isatty:66b8e73:mattnisatty/src/github.com/mattn/go-isatty \
			miekg:dns:58f52c5:miekg/src/github.com/miekg/dns \
			moby:moby:383a2f0:docker/src/github.com/docker/docker \
			oleiade:reflections:0e86b3c:oleiade/src/github.com/oleiade/reflections \
			onsi:gomega:ff4bc6b:onsi/src/github.com/onsi/gomega \
			opencontainers:runc:8779fa5:opencontainers/src/github.com/opencontainers/runc \
			patrickmn:go-cache:1881a9b:patrickmn/src/github.com/patrickmn/go-cache \
			urfave:cli:d86a009:urfave/src/github.com/urfave/cli
do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} CGO_ENABLED=0 GOPATH=${WRKSRC} \
	go build -ldflags "-X main.version=${DISTVERSIONPREFIX}${PORTVERSION} -s -w" -o \
		bin/${PORTNAME} ./cmd/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/github.com/${GH_ACCOUNT}/${PORTNAME}/bin/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
