PORTNAME=	croc
PORTVERSION=	9.6.0
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Tool to simply and securely transfer files and folders

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	schollz
GH_TUPLE=	OneOfOne:xxhash:v1.2.5:oneofone_xxhash/vendor/github.com/OneOfOne/xxhash \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		cpuguy83:go-md2man:v2.0.2:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		denisbrodbeck:machineid:v1.0.1:denisbrodbeck_machineid/vendor/github.com/denisbrodbeck/machineid \
		go-check:check:41f04d3bba15:go_check_check/vendor/gopkg.in/check.v1 \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:05595931fe9d:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:c90051bbdb60:golang_net/vendor/golang.org/x/net \
		golang:sys:05e143d24a9e:golang_sys/vendor/golang.org/x/sys \
		golang:term:065cf7ba2467:golang_term/vendor/golang.org/x/term \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:time:579cf78fd858:golang_time/vendor/golang.org/x/time \
		kalafut:imohash:v1.0.2:kalafut_imohash/vendor/github.com/kalafut/imohash \
		kr:pretty:v0.1.0:kr_pretty/vendor/github.com/kr/pretty \
		mattn:go-runewidth:v0.0.13:mattn_go_runewidth/vendor/github.com/mattn/go-runewidth \
		mitchellh:colorstring:d06e56a500db:mitchellh_colorstring/vendor/github.com/mitchellh/colorstring \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.2.0:rivo_uniseg/vendor/github.com/rivo/uniseg \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		schollz:cli:v2.2.1:schollz_cli_v2/vendor/github.com/schollz/cli/v2 \
		schollz:logger:v1.2.0:schollz_logger/vendor/github.com/schollz/logger \
		schollz:mnemonicode:v1.0.1:schollz_mnemonicode/vendor/github.com/schollz/mnemonicode \
		schollz:pake:v3.0.4:schollz_pake_v3/vendor/github.com/schollz/pake/v3 \
		schollz:peerdiscovery:v1.6.12:schollz_peerdiscovery/vendor/github.com/schollz/peerdiscovery \
		schollz:progressbar:v3.8.6:schollz_progressbar_v3/vendor/github.com/schollz/progressbar/v3 \
		spaolacci:murmur3:v1.1.0:spaolacci_murmur3/vendor/github.com/spaolacci/murmur3 \
		stretchr:testify:v1.6.1:stretchr_testify/vendor/github.com/stretchr/testify \
		tscholl2:siec:9bdfc483d499:tscholl2_siec/vendor/github.com/tscholl2/siec \
		twmb:murmur3:v1.1.6:twmb_murmur3/vendor/github.com/twmb/murmur3
USE_RC_SUBR=	croc

PLIST_FILES=	bin/croc

.include <bsd.port.mk>
