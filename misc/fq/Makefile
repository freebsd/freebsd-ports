PORTNAME=	fq
PORTVERSION=	0.18.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	misc

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Tool, language, and decoders for inspecting binary data
WWW=		https://github.com/wader/fq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	wader
GH_TUPLE=	\
		BurntSushi:toml:v1.6.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		creasty:defaults:v1.8.0:creasty_defaults/vendor/github.com/creasty/defaults \
		ergochat:readline:v0.1.3:ergochat_readline/vendor/github.com/ergochat/readline \
		go-check:check:8fa46927fb4f:go_check_check/vendor/gopkg.in/check.v1 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:v0.55.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.58.0:golang_net/vendor/golang.org/x/net \
		golang:snappy:v1.0.0:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:v0.47.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.45.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.41.0:golang_text/vendor/golang.org/x/text \
		gomarkdown:markdown:e08cff860f76:gomarkdown_markdown/vendor/github.com/gomarkdown/markdown \
		gopacket:gopacket:v1.7.1:gopacket_gopacket/vendor/github.com/gopacket/gopacket \
		itchyny:timefmt-go:v0.1.8:itchyny_timefmt_go/vendor/github.com/itchyny/timefmt-go \
		mitchellh:copystructure:v1.2.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.2:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		niemeyer:pretty:a10e7caefd8e:niemeyer_pretty/vendor/github.com/niemeyer/pretty \
		wader:gojq:6128faeeac7b:wader_gojq/vendor/github.com/wader/gojq

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

post-extract:
	@${LN} -sf ${FILESDIR}/modules.txt ${WRKSRC}/vendor

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
