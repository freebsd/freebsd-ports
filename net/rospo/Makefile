PORTNAME=	rospo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
CATEGORIES=	net net-vpn sysutils
MASTER_SITES=	https://github.com/ferama/rospo/releases/download/v${DISTVERSION}/ui-artifacts.tar.gz?dummy=/:artifacts
DISTFILES=	${PORTNAME}-ui-artifacts-${DISTVERSION}.tar.gz:artifacts

MAINTAINER=	fuz@fuz.su
COMMENT=	Simple and reliable ssh tunnels with embedded ssh server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	ferama
GH_TUPLE=	creack:pty:v1.1.14:creack_pty/vendor/github.com/creack/pty \
		gin-contrib:cors:v1.3.1:gin_contrib_cors/vendor/github.com/gin-contrib/cors \
		gin-contrib:sse:v0.1.0:gin_contrib_sse/vendor/github.com/gin-contrib/sse \
		gin-gonic:gin:v1.7.4:gin_gonic_gin/vendor/github.com/gin-gonic/gin \
		go-playground:locales:v0.13.0:go_playground_locales/vendor/github.com/go-playground/locales \
		go-playground:universal-translator:v0.17.0:go_playground_universal_translator/vendor/github.com/go-playground/universal-translator \
		go-playground:validator:v10.4.1:go_playground_validator_v10/vendor/github.com/go-playground/validator/v10 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:32db794688a5:golang_crypto/vendor/golang.org/x/crypto \
		golang:protobuf:v1.5.2:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:41cdb8703e55:golang_sys/vendor/golang.org/x/sys \
		golang:term:6886f2dfbf5b:golang_term/vendor/golang.org/x/term \
		inconshreveable:mousetrap:v1.0.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		json-iterator:go:v1.1.11:json_iterator_go/vendor/github.com/json-iterator/go \
		leodido:go-urn:v1.2.0:leodido_go_urn/vendor/github.com/leodido/go-urn \
		mattn:go-isatty:v0.0.12:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		modern-go:concurrent:e0a39a4cb421:modern_go_concurrent/vendor/github.com/modern-go/concurrent \
		modern-go:reflect2:v1.0.1:modern_go_reflect2/vendor/github.com/modern-go/reflect2 \
		protocolbuffers:protobuf-go:v1.26.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		spf13:cobra:v1.2.1:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		ugorji:go:v1.1.7:ugorji_go_codec/vendor/github.com/ugorji/go

GO_BUILDFLAGS=	-ldflags="-X github.com/ferama/rospo/cmd.Version=${DISTVERSION}"

PLIST_FILES=	bin/rospo
PORTDOCS=	README.md \
		configs/config_template.yaml \
		img/home.png \
		img/pipes.png \
		img/tunnels.png

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKDIR}/pkg/web/ui/build ${WRKSRC}/pkg/web/ui/build

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/configs
	${MKDIR} ${STAGEDIR}${DOCSDIR}/img
.for doc in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}/`dirname ${doc}`
.endfor

.include <bsd.port.mk>
