PORTNAME=	acmetool
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.2
PORTREVISION=	20
CATEGORIES=	security

MAINTAINER=	samm@FreeBSD.org
COMMENT=	CLI tool for automatically acquiring certificates from ACME servers
WWW=		https://github.com/hlandau/acme/

LICENSE=	MIT

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	hlandau
GH_SUBDIR=	src/github.com/hlandau/acmetool
GH_TUPLE=	alecthomas:template:fb15b89:template/vendor/github.com/alecthomas/template \
		alecthomas:units:b94a6e3cc137:units/vendor/github.com/alecthomas/units \
		coreos:go-systemd:d3cd4ed1dbcf:go_systemd/vendor/github.com/coreos/go-systemd \
		hlandau:acmetool:d3428cf:acme/vendor/github.com/hlandau/acmetool \
		hlandau:buildinfo:337a29b54997:buildinfo/vendor/github.com/hlandau/buildinfo \
		hlandau:dexlogconfig:86a3fc314fe7:dexlogconfig/vendor/github.com/hlandau/dexlogconfig \
		hlandau:goutils:0cdb66aea5b8:goutils/vendor/github.com/hlandau/goutils \
		hlandau:xlog:197ef79:xlog/vendor/github.com/hlandau/xlog \
		hlandau:acmeapi:2f4c7d8:acmeapi/vendor/gopkg.in/hlandau/acmeapi.v2 \
		jmhodges:clock:21de17d:clock/vendor/github.com/jmhodges/clock \
		mattn:go-isatty:c067b4f:go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:2c6a438:go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-wordwrap:ecf0936:go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		ogier:pflag:32a05c6:pflag/vendor/github.com/ogier/pflag \
		peterhellberg:link:980077b:link/vendor/github.com/peterhellberg/link \
		rivo:uniseg:75711fc:uniseg/vendor/github.com/rivo/uniseg \
		gofrs:uuid:8345c9a:uuid/vendor/github.com/gofrs/uuid \
		shiena:ansicolor:a422bbe:ansicolor/vendor/github.com/shiena/ansicolor \
		golang:crypto:a4e9841:crypto/vendor/golang.org/x/crypto \
		golang:net:daac0ce:net/vendor/golang.org/x/net \
		golang:sys:ca59eda:sys/vendor/golang.org/x/sys \
		golang:text:48e4a4a:text/vendor/golang.org/x/text \
		alecthomas:kingpin:947dcec:kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		cheggaaa:pb:f907f6f:pb/vendor/gopkg.in/cheggaaa/pb.v1 \
		hlandau:configurable:4149686:configurable/vendor/gopkg.in/hlandau/configurable.v1 \
		hlandau:easyconfig:30db285:easyconfig/vendor/gopkg.in/hlandau/easyconfig.v1 \
		hlandau:service:0e0d7e6:service/vendor/gopkg.in/hlandau/service.v2 \
		hlandau:svcutils:6e7e875:svcutils/vendor/gopkg.in/hlandau/svcutils.v1 \
		square:go-jose:a10ff54:go_jose2/vendor/gopkg.in/square/go-jose.v2 \
		square:go-jose:5606281:go_jose/vendor/gopkg.in/square/go-jose.v1 \
		tylerb:graceful:4654dfb:graceful/vendor/gopkg.in/tylerb/graceful.v1 \
		go-yaml:yaml:7649d45:go_yaml/vendor/gopkg.in/yaml.v2 \
		erikdubbelboer:gspt:ce36a51:gspt/vendor/github.com/erikdubbelboer/gspt

GO_BUILDFLAGS=	-ldflags "\
		-X github.com/hlandau/acmetool/vendor/github.com/hlandau/acmetool/hooks.DefaultPath=${PREFIX}/libexec/acme/hooks \
		-X github.com/hlandau/acmetool/vendor/github.com/hlandau/acmetool/storage.RecommendedPath=/var/db/acme \
		-X github.com/hlandau/acmetool/vendor/github.com/hlandau/buildinfo.BuildInfo=${PORTNAME}-v${PORTVERSION}-freebsd-ports"
GO_TARGET=	./cmd/acmetool

post-build:
	${GO_WRKDIR_BIN}/${PORTNAME} --help-man > ${WRKSRC}/${PORTNAME}.8

post-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${MKDIR} ${STAGEDIR}/var/db/acme
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/acme/hooks

.include <bsd.port.mk>
