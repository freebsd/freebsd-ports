PORTNAME=	croc
PORTVERSION=	10.0.9
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Tool to simply and securely transfer files and folders
WWW=		https://github.com/schollz/croc

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	schollz
GH_TUPLE=	OneOfOne:xxhash:v1.2.8:oneofone_xxhash/vendor/github.com/OneOfOne/xxhash \
		cespare:xxhash:v1.1.0:cespare_xxhash/vendor/github.com/cespare/xxhash \
		chzyer:readline:v1.5.1:chzyer_readline/vendor/github.com/chzyer/readline \
		cpuguy83:go-md2man:v2.0.4:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		denisbrodbeck:machineid:v1.0.1:denisbrodbeck_machineid/vendor/github.com/denisbrodbeck/machineid \
		go-check:check:10cb98267c6c:go_check_check/vendor/gopkg.in/check.v1 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:v0.24.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.26.0:golang_net/vendor/golang.org/x/net \
		golang:sys:v0.21.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.21.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.16.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.5.0:golang_time/vendor/golang.org/x/time \
		kalafut:imohash:v1.0.4:kalafut_imohash/vendor/github.com/kalafut/imohash \
		magisterquis:connectproxy:3582e84f0c9b:magisterquis_connectproxy/vendor/github.com/magisterquis/connectproxy \
		minio:highwayhash:v1.0.2:minio_highwayhash/vendor/github.com/minio/highwayhash \
		mitchellh:colorstring:d06e56a500db:mitchellh_colorstring/vendor/github.com/mitchellh/colorstring \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		rivo:uniseg:v0.4.7:rivo_uniseg/vendor/github.com/rivo/uniseg \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		sabhiram:go-gitignore:525f6e181f06:sabhiram_go_gitignore/vendor/github.com/sabhiram/go-gitignore \
		schollz:cli:v2.2.1:schollz_cli_v2/vendor/github.com/schollz/cli/v2 \
		schollz:logger:v1.2.0:schollz_logger/vendor/github.com/schollz/logger \
		schollz:mnemonicode:63fa713ece0d:schollz_mnemonicode/vendor/github.com/schollz/mnemonicode \
		schollz:pake:v3.0.5:schollz_pake_v3/vendor/github.com/schollz/pake/v3 \
		schollz:peerdiscovery:v1.7.3:schollz_peerdiscovery/vendor/github.com/schollz/peerdiscovery \
		schollz:progressbar:v3.14.4:schollz_progressbar_v3/vendor/github.com/schollz/progressbar/v3 \
		spaolacci:murmur3:v1.1.0:spaolacci_murmur3/vendor/github.com/spaolacci/murmur3 \
		stretchr:testify:v1.9.0:stretchr_testify/vendor/github.com/stretchr/testify \
		tscholl2:siec:c2c6f6198406:tscholl2_siec/vendor/github.com/tscholl2/siec \
		twmb:murmur3:v1.1.8:twmb_murmur3/vendor/github.com/twmb/murmur3
USE_RC_SUBR=	croc

PLIST_FILES=	bin/croc

.include <bsd.port.mk>
