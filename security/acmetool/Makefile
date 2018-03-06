# $FreeBSD$

PORTNAME=	acmetool
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.67
CATEGORIES=	security

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	CLI tool for automatically acquiring certificates from ACME servers

LICENSE=	MIT

BUILD_DEPENDS=	go>=1.8:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hlandau
GH_PROJECT=	acme
GH_SUBDIR=	src/github.com/hlandau/acme
GH_TUPLE=	alecthomas:template:a0175ee:template/src/github.com/alecthomas/template \
		alecthomas:units:2efee85:units/src/github.com/alecthomas/units \
		coreos:go-systemd:749ef98:go_systemd/src/github.com/coreos/go-systemd \
		hlandau:acme:221ea15:acme/src/github.com/hlandau/acme \
		hlandau:buildinfo:337a29b:buildinfo/src/github.com/hlandau/buildinfo \
		hlandau:dexlogconfig:244f29b:dexlogconfig/src/github.com/hlandau/dexlogconfig \
		hlandau:goutils:0cdb66a:goutils/src/github.com/hlandau/goutils \
		hlandau:xlog:197ef79:xlog/src/github.com/hlandau/xlog \
		jmhodges:clock:880ee4c:clock/src/github.com/jmhodges/clock \
		mattn:go-isatty:6ca4dbf:go_isatty/src/github.com/mattn/go-isatty \
		mattn:go-runewidth:a9d6d1e:go_runewidth/src/github.com/mattn/go-runewidth \
		mitchellh:go-wordwrap:ad45545:go_wordwrap/src/github.com/mitchellh/go-wordwrap \
		ogier:pflag:45c278a:pflag/src/github.com/ogier/pflag \
		peterhellberg:link:6d32b8d:link/src/github.com/peterhellberg/link \
		satori:go.uuid:36e9d2e:go_uuid/src/github.com/satori/go.uuid \
		shiena:ansicolor:a422bbe:ansicolor/src/github.com/shiena/ansicolor \
		golang:crypto:91a49db:crypto/src/golang.org/x/crypto \
		golang:net:22ae77b:net/src/golang.org/x/net \
		golang:sys:dd2ff4a:sys/src/golang.org/x/sys \
		golang:text:b7ef84a:text/src/golang.org/x/text \
		alecthomas:kingpin:947dcec:kingpin/src/gopkg.in/alecthomas/kingpin.v2 \
		cheggaaa:pb:72b9643:pb/src/gopkg.in/cheggaaa/pb.v1 \
		hlandau:configurable:4149686:configurable/src/gopkg.in/hlandau/configurable.v1 \
		hlandau:easyconfig:7589cb9:easyconfig/src/gopkg.in/hlandau/easyconfig.v1 \
		hlandau:service:b64b346:service/src/gopkg.in/hlandau/service.v2 \
		hlandau:svcutils:c25dac4:svcutils/src/gopkg.in/hlandau/svcutils.v1 \
		square:go-jose:aa2e30f:go_jose/src/gopkg.in/square/go-jose.v1 \
		tylerb:graceful:4654dfb:graceful/src/gopkg.in/tylerb/graceful.v1 \
		go-yaml:yaml:7f97868:go_yaml/src/gopkg.in/yaml.v2

do-build:
	@cd ${WRKSRC}/src/github.com/hlandau/acme && \
		${SETENV} ${MAKE_ENV} GOPATH=${WRKSRC} \
		go build -o ${WRKSRC}/bin/${PORTNAME} -ldflags "\
		-X github.com/hlandau/acme/hooks.DefaultPath=${PREFIX}/libexec/acme/hooks \
		-X github.com/hlandau/acme/storage.RecommendedPath=/var/db/acme \
		-X github.com/hlandau/buildinfo.BuildInfo=${PORTNAME}-v${PORTVERSION}-freebsd-ports \
		"\
		github.com/hlandau/acme/cmd/acmetool
	@${WRKSRC}/bin/${PORTNAME} --help-man > ${WRKSRC}/${PORTNAME}.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${MKDIR} ${STAGEDIR}/var/db/acme
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/acme/hooks

.include <bsd.port.mk>
