# $FreeBSD$

PORTNAME=	acmetool
PORTVERSION=	0.0.59
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	CLI tool for automatically acquiring certificates from ACME servers

LICENSE=	MIT

BUILD_DEPENDS=	go>=1.4:lang/go

USE_GITHUB=	yes
GH_ACCOUNT=	hlandau
GH_PROJECT=	acme
GH_SUBDIR=	src/github.com/hlandau/acme
GH_TUPLE=	alecthomas:template:a0175ee:template/src/github.com/alecthomas/template \
		alecthomas:units:2efee857:units/src/github.com/alecthomas/units \
		hlandau:goutils:0cdb66a:goutils/src/github.com/hlandau/goutils \
		hlandau:buildinfo:337a29b:buildinfo/src/github.com/hlandau/buildinfo \
		hlandau:dexlogconfig:244f29b:dexlogconfig/src/github.com/hlandau/dexlogconfig \
		hlandau:xlog:197ef79:xlog/src/github.com/hlandau/xlog \
		hlandau:easyconfig:v1.0.15:easyconfig/src/gopkg.in/hlandau/easyconfig.v1 \
		jmhodges:clock:880ee4c:clock/src/github.com/jmhodges/clock \
		mattn:go-isatty:30a891c:go_isatty/src/github.com/mattn/go-isatty \
		mattn:go-runewidth:14207d2:go_runewidth/src/github.com/mattn/go-runewidth \
		coreos:go-systemd:e97b35f:go_systemd/src/github.com/coreos/go-systemd \
		ogier:pflag:45c278ab:pflag/src/github.com/ogier/pflag \
		peterhellberg:link:24c1495e:link/src/github.com/peterhellberg/link \
		satori:go.uuid:b061729:go_uuid/src/github.com/satori/go.uuid \
		shiena:ansicolor:a422bbe9:ansi_color/src/github.com/shiena/ansicolor \
		golang:crypto:bed1280:crypto/src/golang.org/x/crypto \
		golang:net:41bba8d:net/src/golang.org/x/net \
		alecthomas:kingpin:v2.2.3:kingpin/src/gopkg.in/alecthomas/kingpin.v2 \
		mitchellh:go-wordwrap:ad45545:go_wordwrap/src/github.com/mitchellh/go-wordwrap \
		cheggaaa:pb:v1.0.11:pb_v1/src/gopkg.in/cheggaaa/pb.v1 \
		go-yaml:yaml:a3f3340:go_yaml/src/gopkg.in/yaml.v2 \
		hlandau:svcutils:v1.0.10:svcutils/src/gopkg.in/hlandau/svcutils.v1 \
		hlandau:service:v2.0.16:service/src/gopkg.in/hlandau/service.v2 \
		hlandau:configurable:v1.0.1:configurable/src/gopkg.in/hlandau/configurable.v1 \
		tylerb:graceful:v1.2.15:graceful/src/gopkg.in/tylerb/graceful.v1 \
		square:go-jose:v1.1.0:go_jose/src/gopkg.in/square/go-jose.v1

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
