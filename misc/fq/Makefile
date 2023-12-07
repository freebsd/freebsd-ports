PORTNAME=	fq
PORTVERSION=	0.9.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
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
		BurntSushi:toml:v1.3.2:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		creasty:defaults:v1.7.0:creasty_defaults/vendor/github.com/creasty/defaults \
		go-check:check:8fa46927fb4f:go_check_check/vendor/gopkg.in/check.v1 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:v0.15.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:exp:9a3e6036ecaa:golang_exp/vendor/golang.org/x/exp \
		golang:net:v0.18.0:golang_net/vendor/golang.org/x/net \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:v0.14.0:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		gomarkdown:markdown:a660076da3fd:gomarkdown_markdown/vendor/github.com/gomarkdown/markdown \
		gopacket:gopacket:v1.2.0:gopacket_gopacket/vendor/github.com/gopacket/gopacket \
		itchyny:timefmt-go:v0.1.5:itchyny_timefmt_go/vendor/github.com/itchyny/timefmt-go \
		mitchellh:copystructure:v1.2.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.2:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		niemeyer:pretty:a10e7caefd8e:niemeyer_pretty/vendor/github.com/niemeyer/pretty \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		wader:gojq:2b6d9e2f4985:wader_gojq/vendor/github.com/wader/gojq \
		wader:readline:bcb7158e7448:wader_readline/vendor/github.com/wader/readline

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
