# $FreeBSD$

PORTNAME=	acmetool
PORTVERSION=	0.0.61
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	CLI tool for automatically acquiring certificates from ACME servers

LICENSE=	MIT

BUILD_DEPENDS=	go>=1.8:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hlandau
GH_PROJECT=	acme
GH_SUBDIR=	src/github.com/hlandau/acme
GH_TUPLE=	go-yaml:yaml:a3f3340:go_yaml/src/gopkg.in/yaml.v2 \
		tylerb:graceful:4654dfb:graceful/src/gopkg.in/tylerb/graceful.v1 \
		cheggaaa:pb:657164d:pb_v1/src/gopkg.in/cheggaaa/pb.v1 \
		hlandau:svcutils:c25dac4:svcutils_v1/src/gopkg.in/hlandau/svcutils.v1 \
		hlandau:configurable:4149686:configurable_v1/src/gopkg.in/hlandau/configurable.v1 \
		hlandau:easyconfig:7589cb9:easyconfig_v1/src/gopkg.in/hlandau/easyconfig.v1 \
		hlandau:service:b64b346:service_v2/src/gopkg.in/hlandau/service.v2 \
		square:go-jose:v1.1.0:go_jose/src/gopkg.in/square/go-jose.v1 \
		alecthomas:kingpin:1087e65:kingpin_v2/src/gopkg.in/alecthomas/kingpin.v2 \
		golang:crypto:b080dc9:crypto/src/golang.org/x/crypto \
		golang:text:88f656f:text/src/golang.org/x/text \
		golang:net:c708664:net/src/golang.org/x/net \
		mattn:go-runewidth:97311d9:go_runewidth/src/github.com/mattn/go-runewidth \
		mattn:go-isatty:6ca4dbf:go_isatty/src/github.com/mattn/go-isatty \
		ogier:pflag:45c278a:pflag/src/github.com/ogier/pflag \
		jmhodges:clock:880ee4c:clock/src/github.com/jmhodges/clock \
		mitchellh:go-wordwrap:ad45545:go_wordwrap/src/github.com/mitchellh/go-wordwrap \
		satori:go.uuid:5bf94b6:go_uuid/src/github.com/satori/go.uuid \
		hlandau:dexlogconfig:244f29b:dexlogconfig/src/github.com/hlandau/dexlogconfig \
		hlandau:buildinfo:337a29b:buildinfo/src/github.com/hlandau/buildinfo \
		hlandau:xlog:197ef79:xlog/src/github.com/hlandau/xlog \
		hlandau:goutils:0cdb66a:goutils/src/github.com/hlandau/goutils \
		hlandau:acme:56c12bd:acme/src/github.com/hlandau/acme \
		alecthomas:template:a0175ee:template/src/github.com/alecthomas/template \
		alecthomas:units:2efee85:units/src/github.com/alecthomas/units \
		coreos:go-systemd:d219646:go_systemd/src/github.com/coreos/go-systemd \
		shiena:ansicolor:a422bbe:ansicolor/src/github.com/shiena/ansicolor \
		peterhellberg:link:3eea38c:link/src/github.com/peterhellberg/link

do-build:
	cd ${WRKSRC}/src/github.com/hlandau/acme ; \
		${SETENV} GOPATH=${WRKSRC} \
		go build -o ${WRKSRC}/bin/${PORTNAME} -ldflags "\
		-X github.com/hlandau/acme/hooks.DefaultPath=${PREFIX}/libexec/acme/hooks \
		-X github.com/hlandau/acme/storage.RecommendedPath=/var/db/acme \
		-X github.com/hlandau/buildinfo.BuildInfo=${PORTNAME}-v${PORTVERSION}-freebsd-ports \
		"\
		github.com/hlandau/acme/cmd/acmetool
	${WRKSRC}/bin/${PORTNAME} --help-man > ${WRKSRC}/${PORTNAME}.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${MKDIR} ${STAGEDIR}/var/db/acme
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/acme/hooks

.include <bsd.port.mk>
