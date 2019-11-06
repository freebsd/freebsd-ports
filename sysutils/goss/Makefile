# $FreeBSD$

PORTNAME=		goss
PORTVERSION=		0.3.4
DISTVERSIONPREFIX=	v
PORTREVISION=		1
CATEGORIES=		sysutils

MAINTAINER=		englishm@llnw.com
COMMENT=		Quick and Easy server validation

BROKEN=		unfetchable

LICENSE=		APACHE20
LICENSE_FILE=		${WRKSRC}/LICENSE

USES=			go

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	go-ps only supports amd64

USE_RC_SUBR=		goss

USE_GITHUB=		yes
GH_ACCOUNT=		aelsabbahy
GH_SUBDIR=		src/github.com/aelsabbahy/${PORTNAME}
GH_TUPLE=		achanda:go-sysctl:6be7678:achanda/vendor/github.com/achanda/go-sysctl \
			aelsabbahy:go-ps:4433868:gops/vendor/github.com/aelsabbahy/go-ps \
			aelsabbahy:GOnetstat:edf89f7:GOnetstat/vendor/github.com/aelsabbahy/GOnetstat \
			cheekybits:genny:e8e29e6:cheekybits/vendor/github.com/cheekybits/genny \
			fatih:color:bf82308:fatih/vendor/github.com/fatih/color \
			go-yaml:yaml:a5b47d3:yaml/vendor/gopkg.in/yaml.v2 \
			golang:sys:9a2e24c:sys/vendor/golang.org/x/sys \
			mattn:go-colorable:d228849:mattn/vendor/github.com/mattn/go-colorable \
			mattn:go-isatty:66b8e73:mattnisatty/vendor/github.com/mattn/go-isatty \
			miekg:dns:58f52c5:miekg/vendor/github.com/miekg/dns \
			moby:moby:383a2f0:docker/vendor/github.com/docker/docker \
			oleiade:reflections:0e86b3c:oleiade/vendor/github.com/oleiade/reflections \
			onsi:gomega:ff4bc6b:onsi/vendor/github.com/onsi/gomega \
			opencontainers:runc:8779fa5:opencontainers/vendor/github.com/opencontainers/runc \
			patrickmn:go-cache:1881a9b:patrickmn/vendor/github.com/patrickmn/go-cache \
			urfave:cli:d86a009:urfave/vendor/github.com/urfave/cli

GO_BUILDFLAGS=		-ldflags "-X main.version=${DISTVERSIONPREFIX}${PORTVERSION} -s -w"
GO_TARGET=		./cmd/${PORTNAME}

post-patch:
	${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/extras/goss.yaml.sample

post-install:
	${INSTALL_DATA} ${WRKSRC}/extras/goss.yaml.sample ${STAGEDIR}${PREFIX}/etc/goss.yaml.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/goss.d
	${INSTALL_DATA} ${WRKSRC}/extras/process_goss.yaml.sample \
		${STAGEDIR}${PREFIX}/etc/goss.d/process_goss.yaml.sample

.include <bsd.port.mk>
