# $FreeBSD$

PORTNAME=	acmetool
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	samm@FreeBSD.org
COMMENT=	CLI tool for automatically acquiring certificates from ACME servers

LICENSE=	MIT

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	hlandau
GH_SUBDIR=	src/github.com/hlandau/acmetool
GH_TUPLE=	alecthomas:template:fb15b89:template/vendor/github.com/alecthomas/template \
		alecthomas:units:f65c72e:units/vendor/github.com/alecthomas/units \
		coreos:go-systemd:749ef98:go_systemd/vendor/github.com/coreos/go-systemd \
		hlandau:acmetool:f68b275:acme/vendor/github.com/hlandau/acmetool \
		hlandau:buildinfo:337a29b:buildinfo/vendor/github.com/hlandau/buildinfo \
		hlandau:dexlogconfig:244f29b:dexlogconfig/vendor/github.com/hlandau/dexlogconfig \
		hlandau:goutils:0cdb66a:goutils/vendor/github.com/hlandau/goutils \
		hlandau:xlog:197ef79:xlog/vendor/github.com/hlandau/xlog \
		hlandau:acmeapi:4c466ab:acmeapi/vendor/gopkg.in/hlandau/acmeapi.v2 \
		jmhodges:clock:880ee4c:clock/vendor/github.com/jmhodges/clock \
		mattn:go-isatty:6ca4dbf:go_isatty/vendor/github.com/mattn/go-isatty \
		mattn:go-runewidth:a9d6d1e:go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:go-wordwrap:ad45545:go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		ogier:pflag:45c278a:pflag/vendor/github.com/ogier/pflag \
		peterhellberg:link:6d32b8d:link/vendor/github.com/peterhellberg/link \
		satori:go.uuid:36e9d2e:go_uuid/vendor/github.com/satori/go.uuid \
		shiena:ansicolor:a422bbe:ansicolor/vendor/github.com/shiena/ansicolor \
		golang:crypto:91a49db:crypto/vendor/golang.org/x/crypto \
		golang:net:22ae77b:net/vendor/golang.org/x/net \
		golang:sys:33540a1f6037:sys/vendor/golang.org/x/sys \
		golang:text:b7ef84a:text/vendor/golang.org/x/text \
		alecthomas:kingpin:947dcec:kingpin/vendor/gopkg.in/alecthomas/kingpin.v2 \
		cheggaaa:pb:72b9643:pb/vendor/gopkg.in/cheggaaa/pb.v1 \
		hlandau:configurable:4149686:configurable/vendor/gopkg.in/hlandau/configurable.v1 \
		hlandau:easyconfig:7589cb9:easyconfig/vendor/gopkg.in/hlandau/easyconfig.v1 \
		hlandau:service:b64b346:service/vendor/gopkg.in/hlandau/service.v2 \
		hlandau:svcutils:c25dac4:svcutils/vendor/gopkg.in/hlandau/svcutils.v1 \
		square:go-jose:4ef0f1b:go_jose2/vendor/gopkg.in/square/go-jose.v2 \
		square:go-jose:aa2e30f:go_jose/vendor/gopkg.in/square/go-jose.v1 \
		tylerb:graceful:4654dfb:graceful/vendor/gopkg.in/tylerb/graceful.v1 \
		go-yaml:yaml:7f97868:go_yaml/vendor/gopkg.in/yaml.v2 \

GO_BUILDFLAGS=	-ldflags "\
		-X github.com/hlandau/acmetool/vendor/github.com/hlandau/acmetool/hooks.DefaultPath=${PREFIX}/libexec/acme/hooks \
		-X github.com/hlandau/acmetool/vendor/github.com/hlandau/acmetool/storage.RecommendedPath=/var/db/acme \
		-X github.com/hlandau/acmetool/vendor/github.com/hlandau/buildinfo.BuildInfo=${PORTNAME}-v${PORTVERSION}-freebsd-ports"
GO_TARGET=	./cmd/acmetool

post-build:
	${GO_WRKDIR_BIN}/${PORTNAME} --help-man > ${WRKSRC}/${PORTNAME}.8

post-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${MKDIR} ${STAGEDIR}/var/db/acme
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/acme/hooks

.include <bsd.port.mk>
