# Created by: fabian.freyer@physik.tu-berlin.de
# $FreeBSD$

PORTNAME=	caddy
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.4
CATEGORIES=	www

MAINTAINER=	fabian.freyer@physik.tu-berlin.de
COMMENT=	Fast, cross-platform HTTP/2 web server with automatic HTTPS

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	ca_root_nss>=0:security/ca_root_nss

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	mholt
GH_TUPLE=	\
		cenkalti:backoff:v3.0.0:cenkalti_backoff/vendor/github.com/cenkalti/backoff/v3 \
		cheekybits:genny:v1.0.0:cheekybits_genny/vendor/github.com/cheekybits/genny \
		dustin:go-humanize:v1.0.0:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		flynn:go-shlex:3f9db97f8568:flynn_go_shlex/vendor/github.com/flynn/go-shlex \
		fsnotify:fsnotify:v1.4.7:fsnotify_fsnotify/vendor/gopkg.in/fsnotify.v1 \
		go-acme:lego:v3.2.0:go_acme_lego/vendor/github.com/go-acme/lego/v3 \
		go-tomb:tomb:dd632973f1e7:go_tomb_tomb/vendor/gopkg.in/tomb.v1 \
		go-yaml:yaml:v2.2.2:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:227b76d455e7:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:83d349e8ac1a:golang_net/vendor/golang.org/x/net \
		golang:protobuf:v1.3.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:33540a1f6037:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.2:golang_text/vendor/golang.org/x/text \
		google:uuid:v1.1.1:google_uuid/vendor/github.com/google/uuid \
		gorilla:websocket:v1.4.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		hashicorp:go-syslog:v1.0.0:hashicorp_go_syslog/vendor/github.com/hashicorp/go-syslog \
		hpcloud:tail:v1.0.0:hpcloud_tail/vendor/github.com/hpcloud/tail \
		jimstudt:http-authentication:3eca13d6893a:jimstudt_http_authentication/vendor/github.com/jimstudt/http-authentication \
		klauspost:cpuid:v1.2.0:klauspost_cpuid/vendor/github.com/klauspost/cpuid \
		lucas-clemente:quic-go:v0.13.1:lucas_clemente_quic_go/vendor/github.com/lucas-clemente/quic-go \
		marten-seemann:chacha20:v0.2.0:marten_seemann_chacha20/vendor/github.com/marten-seemann/chacha20 \
		marten-seemann:qpack:v0.1.0:marten_seemann_qpack/vendor/github.com/marten-seemann/qpack \
		marten-seemann:qtls:v0.4.1:marten_seemann_qtls/vendor/github.com/marten-seemann/qtls \
		mcuadros:go-syslog:v2.2.1:mcuadros_go_syslog/vendor/gopkg.in/mcuadros/go-syslog.v2 \
		mholt:certmagic:v0.8.3:mholt_certmagic/vendor/github.com/mholt/certmagic \
		miekg:dns:v1.1.15:miekg_dns/vendor/github.com/miekg/dns \
		naoina:go-stringutil:v0.1.0:naoina_go_stringutil/vendor/github.com/naoina/go-stringutil \
		naoina:toml:v0.1.1:naoina_toml/vendor/github.com/naoina/toml \
		natefinch:lumberjack:v2.0.0:natefinch_lumberjack/vendor/gopkg.in/natefinch/lumberjack.v2 \
		onsi:ginkgo:v1.7.0:onsi_ginkgo/vendor/github.com/onsi/ginkgo \
		russross:blackfriday:067529f716f4:russross_blackfriday/vendor/github.com/russross/blackfriday \
		square:go-jose:v2.3.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2

GO_TARGET=	./caddy

SUB_FILES=	pkg-message
PLIST_FILES=	bin/caddy etc/rc.d/caddy

OPTIONS_DEFINE=	TELEMETRY

TELEMETRY_DESC=	Enable telemetry support
TELEMETRY_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-disable-telemetry

# It is a bit involved to get caddy --version to work correctly, so this
# simple hack gets the right version number that the port has downloaded.  See
# https://github.com/caddyserver/caddy/issues/2875 for more details.
post-patch:
	@${REINPLACE_CMD} -e 's|module.Version|"v${DISTVERSION}"|g' ${WRKSRC}/caddy/caddymain/run.go

post-install:
	${INSTALL_SCRIPT} ${GO_WRKSRC}/dist/init/freebsd/${PORTNAME} \
		${STAGEDIR}/${PREFIX}/etc/rc.d/${PORTNAME}

.include <bsd.port.mk>
