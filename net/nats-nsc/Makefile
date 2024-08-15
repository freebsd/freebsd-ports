PORTNAME=	nsc
PORTVERSION=	2.8.6
DISTVERSIONPREFIX=v
PORTREVISION=	6
CATEGORIES=	net
PKGNAMEPREFIX=	nats-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Tool for creating NATS account and user access configurations
WWW=		https://github.com/nats-io/nsc

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	nats-io
GH_TUPLE=	AlecAivazis:survey:v2.3.7:alecaivazis_survey_v2/vendor/github.com/AlecAivazis/survey/v2 \
		blang:semver:v3.5.1:blang_semver/vendor/github.com/blang/semver \
		briandowns:spinner:v1.23.0:briandowns_spinner/vendor/github.com/briandowns/spinner \
		cpuguy83:go-md2man:v2.0.3:cpuguy83_go_md2man_v2/vendor/github.com/cpuguy83/go-md2man/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dustin:go-humanize:v1.0.1:dustin_go_humanize/vendor/github.com/dustin/go-humanize \
		fatih:color:v1.16.0:fatih_color/vendor/github.com/fatih/color \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		go-yaml:yaml:v3.0.1:go_yaml_yaml_1/vendor/gopkg.in/yaml.v3 \
		golang:appengine:v1.6.8:golang_appengine/vendor/google.golang.org/appengine \
		golang:crypto:v0.21.0:golang_crypto/vendor/golang.org/x/crypto \
		golang:net:v0.22.0:golang_net/vendor/golang.org/x/net \
		golang:oauth2:v0.18.0:golang_oauth2/vendor/golang.org/x/oauth2 \
		golang:protobuf:v1.5.4:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:v0.18.0:golang_sys/vendor/golang.org/x/sys \
		golang:term:v0.18.0:golang_term/vendor/golang.org/x/term \
		golang:text:v0.14.0:golang_text/vendor/golang.org/x/text \
		golang:time:v0.5.0:golang_time/vendor/golang.org/x/time \
		google:go-github:v30.1.0:google_go_github_v30/vendor/github.com/google/go-github/v30 \
		google:go-querystring:v1.1.0:google_go_querystring/vendor/github.com/google/go-querystring \
		inconshreveable:go-update:8152e7eb6ccf:inconshreveable_go_update/vendor/github.com/inconshreveable/go-update \
		inconshreveable:mousetrap:v1.1.0:inconshreveable_mousetrap/vendor/github.com/inconshreveable/mousetrap \
		kballard:go-shellquote:95032a82bc51:kballard_go_shellquote/vendor/github.com/kballard/go-shellquote \
		klauspost:compress:v1.17.7:klauspost_compress/vendor/github.com/klauspost/compress \
		mattn:go-colorable:v0.1.13:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.20:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mgutz:ansi:d51e80ef957d:mgutz_ansi/vendor/github.com/mgutz/ansi \
		minio:highwayhash:v1.0.2:minio_highwayhash/vendor/github.com/minio/highwayhash \
		mitchellh:go-homedir:v1.1.0:mitchellh_go_homedir/vendor/github.com/mitchellh/go-homedir \
		mitchellh:go-wordwrap:v1.0.1:mitchellh_go_wordwrap/vendor/github.com/mitchellh/go-wordwrap \
		nats-io:cliprompts:801ca035562a:nats_io_cliprompts_v2/vendor/github.com/nats-io/cliprompts \
		nats-io:jsm.go:v0.1.0:nats_io_jsm_go/vendor/github.com/nats-io/jsm.go \
		nats-io:jwt:v2.5.5:nats_io_jwt_v2/vendor/github.com/nats-io/jwt \
		nats-io:nats-server:v2.10.11:nats_io_nats_server_v2/vendor/github.com/nats-io/nats-server/v2 \
		nats-io:nats.go:v1.33.1:nats_io_nats_go/vendor/github.com/nats-io/nats.go \
		nats-io:nkeys:v0.4.7:nats_io_nkeys/vendor/github.com/nats-io/nkeys \
		nats-io:nuid:v1.0.1:nats_io_nuid/vendor/github.com/nats-io/nuid \
		onsi:gomega:v1.4.3:onsi_gomega/vendor/github.com/onsi/gomega \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		protocolbuffers:protobuf-go:v1.33.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		rhysd:go-github-selfupdate:v1.2.3:rhysd_go_github_selfupdate/vendor/github.com/rhysd/go-github-selfupdate \
		russross:blackfriday:v2.1.0:russross_blackfriday_v2/vendor/github.com/russross/blackfriday/v2 \
		spf13:cobra:v1.8.0:spf13_cobra/vendor/github.com/spf13/cobra \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		stretchr:testify:v1.7.1:stretchr_testify/vendor/github.com/stretchr/testify \
		tcnksm:go-gitconfig:v0.1.2:tcnksm_go_gitconfig/vendor/github.com/tcnksm/go-gitconfig \
		ulikunitz:xz:v0.5.11:ulikunitz_xz/vendor/github.com/ulikunitz/xz \
		xlab:tablewriter:80b567a11ad5:xlab_tablewriter/vendor/github.com/xlab/tablewriter
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}/v2
GO_TARGET=	nsc

PLIST_FILES=	bin/nsc \
		share/doc/${PORTNAME}/README.md

post-extract:
	# @${RLN} ${WRKSRC_nats_io_jwt} ${WRKSRC}/vendor/github.com/nats-io/jwt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
