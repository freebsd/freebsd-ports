PORTNAME=	fq
PORTVERSION=	0.0.8
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Tool, language, and decoders for inspecting binary data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	wader
GH_TUPLE=	\
		BurntSushi:toml:v1.2.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		creasty:defaults:v1.6.0:creasty_defaults/vendor/github.com/creasty/defaults \
		go-check:check:8fa46927fb4f:go_check_check/vendor/gopkg.in/check.v1 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:05595931fe9d:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:69896b714898:golang_net/vendor/golang.org/x/net \
		golang:snappy:v0.0.4:golang_snappy/vendor/github.com/golang/snappy \
		golang:sys:f75cf1eec38b:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		google:gopacket:v1.1.19:google_gopacket/vendor/github.com/google/gopacket \
		itchyny:timefmt-go:v0.1.3:itchyny_timefmt_go/vendor/github.com/itchyny/timefmt-go \
		mitchellh:copystructure:v1.2.0:mitchellh_copystructure/vendor/github.com/mitchellh/copystructure \
		mitchellh:mapstructure:v1.5.0:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mitchellh:reflectwalk:v1.0.2:mitchellh_reflectwalk/vendor/github.com/mitchellh/reflectwalk \
		niemeyer:pretty:a10e7caefd8e:niemeyer_pretty/vendor/github.com/niemeyer/pretty \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		wader:gojq:0eed2734a1d7:wader_gojq/vendor/github.com/wader/gojq \
		wader:readline:31be50517a56:wader_readline/vendor/github.com/wader/readline

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
