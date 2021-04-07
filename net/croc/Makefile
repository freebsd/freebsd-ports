PORTNAME=	croc
PORTVERSION=	8.6.12
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Tool to simply and securely transfer files and folders

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	schollz
GH_TUPLE=	cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		cpuguy83:go-md2man:v2.0.0:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		denisbrodbeck:machineid:v1.0.1:denisbrodbeck_machineid/vendor/github.com/denisbrodbeck/machineid \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:0c34fe9e7dc2:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:61e056675ecf:golang_net/vendor/golang.org/x/net \
		golang:sys:49726bf1d181:golang_sys/vendor/golang.org/x/sys \
		golang:term:de623e64d2a6:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.5:golang_text/vendor/golang.org/x/text \
		kalafut:imohash:v1.0.0:kalafut_imohash/vendor/github.com/kalafut/imohash \
		mattn:go-runewidth:v0.0.10:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:colorstring:d06e56a500db:mitchellh_colorstring/vendor/github.com/mitchellh/colorstring \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		schollz:cli:v2.2.1:schollz_cli_v2/vendor/github.com/schollz/cli/v2 \
		schollz:logger:v1.2.0:schollz_logger/vendor/github.com/schollz/logger \
		schollz:mnemonicode:v1.0.1:schollz_mnemonicode/vendor/github.com/schollz/mnemonicode \
		schollz:pake:v2.0.7:schollz_pake_v2/vendor/github.com/schollz/pake/v2 \
		schollz:peerdiscovery:v1.6.3:schollz_peerdiscovery/vendor/github.com/schollz/peerdiscovery \
		schollz:progressbar:v3.7.6:schollz_progressbar_v3/vendor/github.com/schollz/progressbar/v3 \
		spaolacci:murmur3:v1.1.0:spaolacci_murmur3/vendor/github.com/spaolacci/murmur3 \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		tscholl2:siec:8da93652b094:tscholl2_siec/vendor/github.com/tscholl2/siec

PLIST_FILES=	bin/croc

.include <bsd.port.mk>
