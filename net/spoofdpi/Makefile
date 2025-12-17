PORTNAME=	spoofdpi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.0
CATEGORIES=	net

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Simple and fast anti-censorship tool
WWW=		https://spoofdpi.xvzc.dev/ \
		https://github.com/xvzc/SpoofDPI/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	xvzc
GH_PROJECT=	SpoofDPI
GH_TUPLE=	BurntSushi:toml:v1.5.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		gabriel-vasile:mimetype:v1.4.10:gabriel_vasile_mimetype/vendor/github.com/gabriel-vasile/mimetype \
		go-check:check:41f04d3bba15:go_check_check/vendor/gopkg.in/check.v1 \
		go-playground:locales:v0.14.1:go_playground_locales/vendor/github.com/go-playground/locales \
		go-playground:universal-translator:v0.18.1:go_playground_universal_translator/vendor/github.com/go-playground/universal-translator \
		go-playground:validator:v10.28.0:go_playground_validator_v10/vendor/github.com/go-playground/validator/v10 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:v0.42.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:v0.27.0:golang_mod/vendor/golang.org/x/mod \
		golang:net:v0.43.0:golang_net/vendor/golang.org/x/net \
		golang:sync:v0.17.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.36.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.29.0:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.36.0:golang_tools/vendor/golang.org/x/tools \
		google:gopacket:v1.1.19:google_gopacket/vendor/github.com/google/gopacket \
		jackpal:gateway:v1.1.1:jackpal_gateway/vendor/github.com/jackpal/gateway \
		kr:pretty:v0.1.0:kr_pretty/vendor/github.com/kr/pretty \
		leodido:go-urn:v1.4.0:leodido_go_urn/vendor/github.com/leodido/go-urn \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.19:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		miekg:dns:v1.1.61:miekg_dns/vendor/github.com/miekg/dns \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rs:zerolog:v1.33.0:rs_zerolog/vendor/github.com/rs/zerolog \
		samber:lo:v1.52.0:samber_lo/vendor/github.com/samber/lo \
		stretchr:objx:v0.5.2:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.11.1:stretchr_testify/vendor/github.com/stretchr/testify \
		urfave:cli:v3.6.1:urfave_cli_v3/vendor/github.com/urfave/cli/v3

USE_RC_SUBR=	${PORTNAME}
GO_TARGET=	./cmd/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-s -w -X main.build=${OPSYS:tl} -X main.version=${DISTVERSION}"
CGO_CFLAGS+=	-I/usr/include
CGO_LDFLAGS+=	-L/usr/lib
SUB_FILES=	pkg-message
SUB_LIST=	USER=${USERS}
USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_FILES=	"@dir(${USERS},${GROUPS},0770) ${ETCDIR}" \
		"@sample(${USERS},${GROUPS},0770) ${ETCDIR}/${PORTNAME}.toml.sample" \
		bin/${PORTNAME}

post-patch:
	${CP} ${FILESDIR}/modules.txt ${WRKSRC}/vendor
	@${REINPLACE_CMD} -e '342s#"etc"#"${ETCDIR}"#g' \
		${WRKSRC}/internal/config/cli.go

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.toml.sample \
		${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
